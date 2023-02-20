#include "auction/agent.hpp"

/*
 * Code for the agent class of the auction package
 *
 * The agent class provides 2 services to others: the bid service and
 * the auction service
 *
 * These run under the same node, and allow other agents and users to interface
 * with the agent
 *
 * The agent class also occasionally acts as a client for other services, 
 * either when asking for a goal from the goal manager or when asking for bids
 * from other agents. This is done dynamically. In particular, each time
 * the agent wants to act as a client, it creates a client node, and conducts
 * the necessary operations.
 */

void Agent::new_goals_cb(const ma_interfaces::msg::Goal goal) {
    if (goal.owner == "") {
        ma_interfaces::msg::Bid bid = ma_interfaces::msg::Bid();
        bid.agent_id = id_;
        bid.auction_id = goal.id;
        bid.value = 10;

        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Publishing bid for goal %s", goal.id.c_str());
        goal_bid_publisher_->publish(bid);
    } else if (goal.owner == id_) {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Won goal: %s", goal.id.c_str());

        // Agent won the bid, now need to host a task auction
        ma_interfaces::msg::Task task = ma_interfaces::msg::Task();
        task.id = goal.id;
        task.owner = "";
        task.duration = 10; // Default
        task.value = 10; // Default
        bid_map[task.id] = std::vector<ma_interfaces::msg::Bid>();

        // Send out auction
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Publishing auction for task %s", task.id.c_str());
        task_auction_publisher_->publish(task);
        rclcpp::sleep_for(5s);

        // Choose winner
        ma_interfaces::msg::Bid winning_bid = ma_interfaces::msg::Bid();
        winning_bid.st = -1;
        for (ma_interfaces::msg::Bid bid : bid_map[task.id]) {
            if (winning_bid.st < 0 || bid.st < winning_bid.st) {
                winning_bid = bid;
            }
        }
        bid_map.erase(task.id);

        // Create winner message
        if (winning_bid.st >= 0) {
            ma_interfaces::msg::Task allocated_task = ma_interfaces::msg::Task();
            allocated_task.id = winning_bid.auction_id;
            allocated_task.owner = winning_bid.agent_id;
            allocated_task.duration = task.duration;
            allocated_task.value = task.value;

            // Send out winner
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Publishing winner for auction %s: agent %s", task.id.c_str(), winning_bid.agent_id.c_str());
            task_auction_publisher_->publish(allocated_task);
        } else {
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "No bids, closing auction %s", task.id.c_str());
        }
    }
}

// Returns the first node such that the gap between this and the next
// can fit the task
TNode* Agent::find_slot(int dur) {
    print_timeline();
    TNode* curr = timeline;

    while (curr->next) {
        tuple<double,double> st = stn.get_feasible_values(curr->etp_); 
        tuple<double,double> et = stn.get_feasible_values(curr->next->stp_);
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "ST:(%f,%f), ET: (%f,%f)", std::get<0>(st), std::get<1>(st), std::get<0>(et), std::get<1>(et));

        if (std::get<1>(et) + std::get<0>(st) >= dur) {
            // std::get<0>(tp) is negative, so adding it is correct
            return curr;
        }

        curr = curr->next;
    }

    return curr;
}

void Agent::print_timeline() {
    TNode* curr = timeline;
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Printing timeline...");

    while (curr) {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "%s: (%s, %s)->\n", curr->name_.c_str(), curr->stp_.c_str(), curr->etp_.c_str());
        curr = curr->next;
    }
}

void Agent::new_tasks_cb(const ma_interfaces::msg::Task task) {
    if (task.owner == "" && bid_map.find(task.id) == bid_map.end()) {
        // Generate a bid
        //
        // First need to search timeline for a slot
        TNode* slot_head = find_slot(task.duration);
        if (slot_head->name_ == "tail") {
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Couldn't find slot");
        } else {
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Found slot: %s=(%s,%s)", slot_head->name_.c_str(),slot_head->stp_.c_str(),slot_head->etp_.c_str());

            int st = (int)std::get<0>(stn.get_feasible_values(slot_head->etp_));
            task_map[task.id] = slot_head;

            ma_interfaces::msg::Bid bid = ma_interfaces::msg::Bid();
            bid.agent_id = id_;
            bid.auction_id = task.id;
            bid.st = st;
            bid.value = 10;
            
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Publishing bid for auction %s", bid.auction_id.c_str());
            task_bid_publisher_->publish(bid);
        }
    } else if (task.owner == id_) {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Won the bid for auction %s", task.id.c_str());
        // Now need to schedule the task
        TNode* slot_head = task_map[task.id];

        // Try adding task
        // First, delete the existing sequencing constraint

        std::string slot_st = slot_head->etp_;
        std::string slot_et = slot_head->next->stp_;

        stn.del_constraint(slot_st + "_" + slot_et + "_seq");

        // Now, add in the new timepoints and constraints
        std::string new_stp = task.id + "_st";
        std::string new_etp = task.id + "_et";

        constraint task_dur = std::make_tuple(new_stp, new_etp, task.duration, task.duration);
        constraint head_seq = std::make_tuple(slot_st, new_stp, 0, inf);
        constraint tail_seq = std::make_tuple(new_etp, slot_et, 0, inf);

        stn.add_timepoint(new_stp);
        stn.add_timepoint(new_etp);

        bool status = stn.add_constraint(slot_st + "_" + new_stp + "_seq", head_seq);
        status = status && stn.add_constraint(new_stp + "_" + new_etp + "_dur", task_dur);
        status = status && stn.add_constraint(new_etp + "_" + slot_et + "_seq", tail_seq);

        if (status) {
            // Able to add, need to confirm
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Task added successfully: %s", task.id.c_str());
            TNode* new_task = new TNode(task.id, new_stp, new_etp);
            TNode* tmp = slot_head->next;
            slot_head->next = new_task;
            new_task->next = tmp;
            
            // Check to see if there are any tasks to dispatch
            stn.print_graph();
            print_timeline();

            check_dispatch();
        } else {
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Couldn't add task: %s", task.id.c_str());
            stn.del_all_constraints(new_stp, new_etp);
            stn.del_timepoint(new_stp);
            stn.del_timepoint(new_etp);
            constraint old_seq = std::make_tuple(slot_st, slot_et, 0, inf);
            stn.add_constraint(slot_st + "_" + slot_et + "_seq", old_seq);
        }
    }
}

void Agent::check_dispatch() {
    if (timeline->next->name_ != "tail") {
        // Action exists to dispatch
        TNode* curr = timeline->next;
        if (curr->status == TNode::WAITING) {
            RCLCPP_INFO(this->get_logger(), "Found task to dispatch: %s", curr->name_.c_str());
            ma_interfaces::msg::ActionDispatch msg = ma_interfaces::msg::ActionDispatch();
            msg.action_id = curr->name_;
            msg.agent_id = id_;
            msg.name = curr->name_;

            auto stp = stn.get_feasible_values(curr->stp_);
            auto etp = stn.get_feasible_values(curr->etp_);

            msg.duration = -1*(std::get<0>(etp) - std::get<0>(stp));
            msg.start_time = -1*std::get<0>(stp);

            RCLCPP_INFO(this->get_logger(), "Start time: %f, duration: %f", msg.start_time, msg.duration);

            action_dispatch_publisher_->publish(msg);
            curr->status = TNode::EXECUTING;
        }
    }
}

void Agent::new_bids_cb(const ma_interfaces::msg::Bid bid) {
    if (bid_map.find(bid.auction_id) != bid_map.end()) {
        bid_map[bid.auction_id].push_back(bid);
        
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Added bid from agent %s to auction %s", bid.agent_id.c_str(), bid.auction_id.c_str());
    }
}


int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);

    rclcpp::executors::MultiThreadedExecutor executor;
    auto agent_node = std::make_shared<Agent>(argv[1]);

    executor.add_node(agent_node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}
