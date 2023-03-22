#include "auction/agent.hpp"

bool agent_verbose_1 = true; // Higher-level messages, pub/sub
bool agent_verbose_2 = false; // Lower-level, searches, etc.

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

/*
 * Callback function for goals published by goal manager
 * Input: Goal
 * Output: Bid IF Goal unowned, ELSE create and start auction for goal as task
 */

void Agent::new_goals_cb(const ma_interfaces::msg::Goal goal) {
    if (goal.owner == "") {
        // Goal is unowned, formulate a bid
        ma_interfaces::msg::Bid bid = ma_interfaces::msg::Bid();
        bid.agent_id = id_;
        bid.auction_id = goal.id;
        bid.value = 10; // Default value


        if (agent_verbose_1) RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Publishing bid for goal %s", goal.id.c_str());
        goal_bid_publisher_->publish(bid);
    } else if (goal.owner == id_) {
        // Agent won the bid, now need to host a task auction
        if (agent_verbose_1) RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Won goal: %s", goal.id.c_str());

        ma_interfaces::msg::Task task = ma_interfaces::msg::Task();
        task.id = goal.id;
        task.owner = "";
        task.duration = 10; // Default
        task.value = 10; // Default
        bid_map[task.id] = std::vector<ma_interfaces::msg::Bid>();

        // Send out auction
        if (agent_verbose_1) RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Publishing auction for task %s", task.id.c_str());
        task_auction_publisher_->publish(task);

        // Wait to collect bids
        rclcpp::sleep_for(5s);

        // Choose winner -- default is earliest start time
        int winning_idx = -1;
        for (size_t i = 0; i < bid_map[task.id].size(); i++) {
            auto bid = bid_map[task.id][i];
            if (winning_idx < 0 || bid.st < bid_map[task.id][winning_idx].st) {
                winning_idx = i;
            }
        }

        ma_interfaces::msg::Bid winning_bid = bid_map[task.id][winning_idx];
        bid_map[task.id].erase(bid_map[task.id].begin()+winning_idx);

        // Create winner message
        if (winning_bid.st >= 0) {
            ma_interfaces::msg::Task allocated_task = ma_interfaces::msg::Task();
            allocated_task.id = winning_bid.auction_id;
            allocated_task.owner = winning_bid.agent_id;
            allocated_task.duration = task.duration;
            allocated_task.value = task.value;

            // Send out winner
            if (agent_verbose_1) RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Publishing winner for auction %s: agent %s", task.id.c_str(), winning_bid.agent_id.c_str());
            task_auction_publisher_->publish(allocated_task);
        } else {
            if (agent_verbose_1) RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "No bids, closing auction %s", task.id.c_str());
        }
    }
}

/*
 * Function to find a slot on an agent timeline
 * Input: Duration representing size of slot
 * Output: TNode curr, where the slot is between curr and curr->next
 */
TNode* Agent::find_slot(int dur) {
    print_timeline();
    TNode* curr = timeline;

    while (curr->next) {
        tuple<double,double> st = stn.get_feasible_values(curr->etp_); 
        tuple<double,double> et = stn.get_feasible_values(curr->next->stp_);

        if (curr->next->status == TNode::WAITING && std::get<1>(et) + std::get<0>(st) >= dur) {
            // std::get<0>(tp) is negative, so adding it is correct
            // Check that next node on timeline isn't already in execution
            return curr;
        }

        curr = curr->next;
    }

    return curr;
}

// std::vector<TNode*> Agent::find_slots(int dur) {
//     std::vector<TNode*> slots;
//     TNode* curr = timeline;

//     while (curr->next) {
//         tuple<double,double> st = stn.get_feasible_values(curr->etp_); 
//         tuple<double,double> et = stn.get_feasible_values(curr->next->stp_);
        
//         if (curr->next->status == TNode::WAITING && std::get<1>(et) + std::get<0>(st) >= dur) {
//             // std::get<0>(tp) is negative, so adding it is correct
//             // Check that next node on timeline isn't already in execution
//             slots.push_back(curr);
//         }

//         curr = curr->next;
//     }

//     return slots;

// }

/*
 * Function to print timeline for agent
 * Input: void
 * Output: prints timeline
 */
void Agent::print_timeline() {
    TNode* curr = timeline;
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Printing timeline...");

    while (curr) {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "%s: (%s, %s)->\n", curr->name_.c_str(), curr->stp_.c_str(), curr->etp_.c_str());
        curr = curr->next;
    }
}

/*
 * Callback function to process task messages that correspond to auctions
 * Input: Task that represents either an auction or auction winner
 * Output: Bid for task IF unowned, 
 */
void Agent::new_tasks_cb(const ma_interfaces::msg::Task task) {
    if (task.owner == "" && bid_map.find(task.id) == bid_map.end()) {
        // Generate a bid for the unowned task, first by searching for a slot

        TNode* slot_head = find_slot(task.duration);
        if (slot_head->name_ == "tail") {
            // Reached end of timeline without finding a slot
            if (agent_verbose_2) RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Couldn't find slot");
        } else {
            if (agent_verbose_2) RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Found slot: %s=(%s,%s)", slot_head->name_.c_str(),slot_head->stp_.c_str(),slot_head->etp_.c_str());

            // Slot is the earliest finish time of the TNode
            double st = -1*std::get<0>(stn.get_feasible_values(slot_head->etp_));
            task_map[task.id] = slot_head;

            // Build bid message
            ma_interfaces::msg::Bid bid = ma_interfaces::msg::Bid();
            bid.agent_id = id_;
            bid.auction_id = task.id;
            bid.status = 0;
            bid.st = st;
            bid.et = st + task.duration;
            bid.value = 10;
            
            // Publish bid
            if (agent_verbose_1) RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Publishing bid for auction %s", bid.auction_id.c_str());
            task_bid_publisher_->publish(bid);
        }
    } else if (task.owner == id_) {
        // Agent won the bid for the task
        if (agent_verbose_1) RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Won the bid for auction %s", task.id.c_str());

        // Now need to schedule the task
        TNode* slot_head = task_map[task.id];

        // Try adding task by first deleting the existing sequencing constraint
        std::string slot_st = slot_head->etp_;
        std::string slot_et = slot_head->next->stp_;

        stn.del_constraint(slot_st + "_" + slot_et + "_seq");

        // Now, add in the new timepoints and constraints
        std::string new_stp = task.id + "_st";
        std::string new_etp = task.id + "_et";

        constraint task_dur = std::make_tuple(new_stp, new_etp, std::max(0.0,task.duration-execution_threshold_), task.duration+execution_threshold_);
        constraint head_seq = std::make_tuple(slot_st, new_stp, 0, inf);
        constraint tail_seq = std::make_tuple(new_etp, slot_et, 0, inf);

        stn.add_timepoint(new_stp);
        stn.add_timepoint(new_etp);

        bool status = stn.add_constraint(slot_st + "_" + new_stp + "_seq", head_seq);
        status = status && stn.add_constraint(new_stp + "_" + new_etp + "_dur", task_dur);
        status = status && stn.add_constraint(new_etp + "_" + slot_et + "_seq", tail_seq);

        if (status) {
            // Able to add, send confirmation to auctioneer
            if (agent_verbose_2) RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Task added successfully: %s", task.id.c_str());
            TNode* new_task = new TNode(task.id, new_stp, new_etp);
            TNode* tmp = slot_head->next;
            slot_head->next = new_task;
            new_task->next = tmp;
            task_map[task.id] = new_task;
            
            auto msg = ma_interfaces::msg::Bid();
            msg.auction_id = task.id;
            msg.status = 1;

            if (agent_verbose_1) RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Publishing scheduling confirmation of task: %s", task.id.c_str());
            task_bid_publisher_->publish(msg);
            // Check to see if there are any tasks to dispatch
            print_timeline();

            check_dispatch();
        } else {
            // Unable to add message, send failur to auctioneer
            if (agent_verbose_2) RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Couldn't add task: %s", task.id.c_str());
            stn.del_all_constraints(new_stp, new_etp);
            stn.del_timepoint(new_stp);
            stn.del_timepoint(new_etp);
            constraint old_seq = std::make_tuple(slot_st, slot_et, 0, inf);
            stn.add_constraint(slot_st + "_" + slot_et + "_seq", old_seq);

            auto msg = ma_interfaces::msg::Bid();
            msg.agent_id = id_;
            msg.auction_id = task.id;
            msg.status = -1;
            msg.st = 0;
            msg.et = task.duration;
            msg.value = task.value;

            if (agent_verbose_1) RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Publishing scheduling failure of task: %s", task.id.c_str());
            task_bid_publisher_->publish(msg);
        }
    }
}

void Agent::check_dispatch() {
    if (timeline->status == TNode::COMPLETE) {
        // Action exists to dispatch
        TNode* curr = timeline->next;
        if (curr->status == TNode::WAITING) {
            if (agent_verbose_2) RCLCPP_INFO(this->get_logger(), "Found task to dispatch: %s", curr->name_.c_str());
            ma_interfaces::msg::ActionDispatch msg = ma_interfaces::msg::ActionDispatch();
            msg.action_id = curr->name_;
            msg.agent_id = id_;
            msg.name = curr->name_;

            auto stp = stn.get_feasible_values(curr->stp_);
            auto etp = stn.get_feasible_values(curr->etp_);

            msg.duration = -1*(std::get<0>(etp) - std::get<0>(stp));
            msg.start_time = -1*std::get<0>(stp);

            if (agent_verbose_2) RCLCPP_INFO(this->get_logger(), "Start time: %f, duration: %f", msg.start_time, msg.duration);

            if (agent_verbose_1) RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Dispatching action: %s", msg.action_id.c_str());
            action_dispatch_publisher_->publish(msg);
            curr->status = TNode::EXECUTING;

            // Move timeline so that we are now on the current task
            timeline = curr;
        }
    }
}

void Agent::new_bids_cb(const ma_interfaces::msg::Bid bid) {
    if (bid_map.find(bid.auction_id) != bid_map.end()) {
        if (bid.status < 0) {
            // Agent was unable to schedule task, choose next best
            int winning_idx = -1;
            for (size_t i = 0; i < bid_map[bid.auction_id].size(); i++) {
                auto alt_bid = bid_map[bid.auction_id][i];
                if (winning_idx < 0 || alt_bid.st < bid_map[bid.auction_id][winning_idx].st) {
                    winning_idx = i;
                }
            }
            
            if (winning_idx >= 0){
                // Winner was found
                ma_interfaces::msg::Bid winning_bid = bid_map[bid.auction_id][winning_idx];
                bid_map[bid.auction_id].erase(bid_map[bid.auction_id].begin()+winning_idx);

                ma_interfaces::msg::Task allocated_task = ma_interfaces::msg::Task();
                allocated_task.id = winning_bid.auction_id;
                allocated_task.owner = winning_bid.agent_id;
                allocated_task.duration = winning_bid.et - winning_bid.st; //Duration may change
                allocated_task.value = winning_bid.value;

                // Send out winner
                if (agent_verbose_1) RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Publishing winner for auction %s: agent %s", bid.auction_id.c_str(), winning_bid.agent_id.c_str());
                task_auction_publisher_->publish(allocated_task);
            } else {
                // No valid winners
                if (agent_verbose_1) RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "No bids, closing auction %s", bid.auction_id.c_str());
            }
        } else if (bid.status > 0) {
            // Task was scheduled, can now erase and close auction
            bid_map.erase(bid.auction_id);
            if (agent_verbose_1) RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Task <%s> was successfuly scheduled by agent %s, closing auction.", bid.auction_id.c_str(), bid.agent_id.c_str());
        } else {
            // Auction is receiving bids
            bid_map[bid.auction_id].push_back(bid);
            if (agent_verbose_1) RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Added bid from agent %s to auction %s", bid.agent_id.c_str(), bid.auction_id.c_str());
        }
    }
}

void Agent::action_feedback_cb(const ma_interfaces::msg::ActionFeedback action) {
    if (action.agent_id == id_) {
        if (task_map.find(action.action_id) != task_map.end()) {
            TNode* curr = task_map[action.action_id];
            auto end_fv = stn.get_feasible_values(curr->etp_);

            if (action.action_started) {
                constraint c = std::make_tuple("cz", curr->stp_, action.time, action.time);
                bool status = stn.add_constraint(curr->stp_ + "_actual", c);

                if (status) {
                    curr->status = TNode::EXECUTING;
                    if (agent_verbose_2) RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Action executing: %s", action.action_id.c_str());
                } else {
                    if (agent_verbose_2) RCLCPP_INFO(rclcpp::get_logger("rclcpp"),"Unable to add start constraint to timeline for action %s", action.action_id.c_str());
                }
            } else if (action.action_completed) {
                constraint c = std::make_tuple("cz", curr->etp_, action.time, action.time);
                bool status = stn.add_constraint(curr->etp_ + "_actual", c);
                if (status) {
                    curr->status = TNode::COMPLETE;
                    if (agent_verbose_2) RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Action complete: %s", action.action_id.c_str());
                } else {
                    if (agent_verbose_2) RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Unable to add end constraint to timeline for action %s, expected: (%f, %f),  actual: %f", 
                            action.action_id.c_str(), std::get<0>(end_fv), std::get<1>(end_fv), action.time);
                }
            } else if (action.action_failed) {
                if (agent_verbose_2) RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Action failed: %s", action.action_id.c_str());
                // Do something
            }
        }
    }
}

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);

    rclcpp::executors::MultiThreadedExecutor executor;
    auto agent_node = std::make_shared<Agent>(argv[1], std::stod(argv[2]), std::stod(argv[3]));

    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Agent %s started", argv[1]);

    executor.add_node(agent_node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}
