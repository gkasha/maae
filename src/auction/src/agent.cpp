#include "auction/agent.hpp"

bool agent_verbose_1 = true; // Higher-level messages, pub/sub
bool agent_verbose_2 = true; // Lower-level, searches, etc.

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

ma_interfaces::msg::Bid Agent::build_bid_msg(
    std::string agent_id, 
    std::string auction_id,
    int status,
    double st,
    double et,
    double value
) {
    ma_interfaces::msg::Bid bid = ma_interfaces::msg::Bid();
    bid.agent_id = agent_id;
    bid.auction_id = auction_id;
    bid.status = status;
    bid.st = st;
    bid.et = et;
    bid.value = value;
    return bid;
}

ma_interfaces::msg::Task Agent::build_task_msg(
    std::string id,
    std::string owner,
    int num_agents,
    double value,
    double duration,
    double st,
    double et
) {
    ma_interfaces::msg::Task task = ma_interfaces::msg::Task();
    task.id = id;
    task.owner = owner;
    task.num_agents = num_agents;
    task.value = value;
    task.duration = duration;
    task.st = st;
    task.et = et;
    return task;
}

void Agent::clock_cb(const std_msgs::msg::Int64::SharedPtr msg) {
    curr_time_ = msg->data;

    // Delete now constraint
    stn.del_constraint("now_constraint");

    // Get the current time point that we should be looking at
    TNode* curr = timeline;

    // If curr is executing, add constraint to end. Otherwise, add to start
    std::string timepoint;
    if (curr->status == TNode::WAITING) {
        timepoint = curr->stp_;
    } else if (curr->status == TNode::EXECUTING) {
        timepoint = curr->etp_;
    } else {
        timepoint = "end";
    }

    constraint c = std::make_tuple("now", timepoint, curr_time_, std::get<1>(stn.get_feasible_values(timepoint)));
    bool status = stn.add_constraint("now_constraint", c);
    if (!status){
        // if (curr->status == TNode::WAITING) {
        //     // Remove task frome timeline
        //     stn.del_all_constraints(curr->stp_,curr->etp_);
        //     stn.del_timepoint(curr->stp_);
        //     stn.del_timepoint(curr->etp_);
            
        //     c = std::make_tuple(curr->prev->etp_,curr->next->stp_, 0, inf);
        //     stn.add_constraint(curr->prev->etp_ + "_" + curr->next->stp_ + "_seq", c);

        //     ma_interfaces::msg::goal goal = ma_interfaces::msg::goal();
        //     goal.id = curr->task.id;
        //     goal.deadline = curr->task.et;
        //     goal.num_agents = curr->task.num
        //     timeline_ = curr->next;
            
        //     // stn.add_constraint(curr->prev)
        // }
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Unable to add now constraint");
    }


    check_dispatch();
}
/*
 * Determine winners for a task, currently by earliest start time.
 *
 * Notably, the implementation takes a brute-force approach, iterating
 * over all possible bids to generate the overlaps, and then sorts by
 * the earliest start time. The bids are then reformatted such that
 * the end time is shifted to just be the start time + duration.
 *
 * Input: task
 * Output: vector containing the winning bids
 */
std::vector<ma_interfaces::msg::Bid> Agent::choose_winners(ma_interfaces::msg::Task task) {
    // First, need to generate all overlapping intervals
    std::vector<ma_interfaces::msg::Bid> bids;
    std::vector<std::string> agents;

    std::vector<std::vector<ma_interfaces::msg::Bid>> overlaps;

    // Store bids in vector form
    for (auto const& elt : bid_map[task.id]) {
        agents.push_back(elt.first);
        bids.insert(bids.end(), elt.second.begin(), elt.second.end());
    }

    // Get overlapping bids
    if (task.num_agents > 1) {
        for (std::string agent : agents) {
            for (ma_interfaces::msg::Bid bid : bid_map[task.id][agent]) {
                for (ma_interfaces::msg::Bid alt_bid : bids) {
                    if (alt_bid.agent_id != bid.agent_id && alt_bid.st <= bid.et && alt_bid.et >= bid.st) {
                        // Overlap
                        double st = max(bid.st,alt_bid.st);
                        st = max((double)curr_time_,st);
                        double et = min(bid.et,alt_bid.et) ;
                        if (et - st >= task.duration) {
                            bid.st = st;
                            bid.et = st+task.duration;
                            alt_bid.st = st;
                            alt_bid.et = st+task.duration;
                            std::vector<ma_interfaces::msg::Bid> overlap{bid,alt_bid};
                            overlaps.push_back(overlap);
                        }
                    }
                }
            }
        }
    } else {
        for (ma_interfaces::msg::Bid bid : bids) {
            bid.st = bid.st;
            bid.et = bid.st + task.duration;
            overlaps.push_back({bid});
        }    
    }
    

    // Choose best interval by earliest start time
    auto cmp = [](
        std::vector<ma_interfaces::msg::Bid> left,
        std::vector<ma_interfaces::msg::Bid> right)
        {return left[0].st < right[0].st;};
    
    std::sort(overlaps.begin(),overlaps.end(),cmp);

    // Erase the bid map entry, add the winner map
    winner_map[task.id] = overlaps;
    bid_map.erase(task.id);

    return winner_map[task.id][0];
}

void Agent::host_auction(const ma_interfaces::msg::Goal goal) {
    if (agent_verbose_1) RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Won goal %s", goal.id.c_str());

    ma_interfaces::msg::Task task = build_task_msg(goal.id,"",goal.num_agents,10,10,curr_time_+5,curr_time_+15);
    std::map<std::string,std::vector<ma_interfaces::msg::Bid>> new_map;
    bid_map[task.id] = new_map;

    // Send out auction
    if (agent_verbose_1) RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Publishing auction for task %s", task.id.c_str());
    task_auction_publisher_->publish(task);

    // Wait to collect bids
    rclcpp::sleep_for(5s);

    // Choose winner -- default is earliest start time
    std::vector<ma_interfaces::msg::Bid> winning_bids = choose_winners(task);

    // Send out winners
    for (ma_interfaces::msg::Bid bid : winning_bids) {
        if (agent_verbose_1) RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Publishing winner for auction %s: agent %s (%f,%f)", task.id.c_str(), task.owner.c_str(), bid.st, bid.et);
        task.owner = bid.agent_id;
        task.st = bid.st;
        task.et = task.st + task.duration;

        task_auction_publisher_->publish(task);
    }
}
/*
 * Callback function for goals published by goal manager
 *
 * Input: Goal
 * Output: Bid IF Goal unowned, ELSE create and start auction for goal as task
 */
void Agent::new_goals_cb(const ma_interfaces::msg::Goal goal) {
    if (goal.owner == "") {
        // Goal is unowned, formulate a bid
        if (agent_verbose_1) RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Publishing bid for goal %s", goal.id.c_str());

        ma_interfaces::msg::Bid bid = build_bid_msg(id_,goal.id,0,0,0,10);
        goal_bid_publisher_->publish(bid);
    } else if (goal.owner == id_) {
        host_auction(goal);
    }
}

/*
 * Function to find all slots on an agent timeline that can accomplish the task
 *
 * Input: Duration representing size of slot
 * Output: TNode curr, where the slot is between curr and curr->next
 */
std::vector<TNode*> Agent::find_slots(int dur) {
    std::vector<TNode*> slots;
    TNode* curr = timeline;

    while (curr->next) {
        double st = max((double)curr_time_,-1*std::get<0>(stn.get_feasible_values(curr->etp_))); 
        double et = std::get<1>(stn.get_feasible_values(curr->next->stp_));
        if (curr->next->status == TNode::WAITING && et-st >= dur) {
            // Check that next node on timeline isn't already in execution
            slots.push_back(curr);
        }
        curr = curr->next;
    }

    return slots;
}

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

// Assume task.deadline is when we have to start the task
bool Agent::schedule_task(ma_interfaces::msg::Task task) {
    // Search for slot that covers task
    TNode* curr = timeline;
    while (curr->next) {
        double st = max((double)curr_time_,-1*std::get<0>(stn.get_feasible_values(curr->etp_))); 
        double et = std::get<1>(stn.get_feasible_values(curr->next->stp_));
        // won task, make sure that task start and end time are within block
        if (curr->next->status == TNode::WAITING && task.st >= st && task.et <= et) {
            // Check that next node on timeline isn't already in execution
            break;
        }
        curr = curr->next;
    }

    if (curr->name_ == "tail"){
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Unable to find slot to schedule task...");
        return false;
    }

    std::string slot_st = curr->etp_;
    std::string slot_et = curr->next->stp_;

    stn.del_constraint(slot_st + "_" + slot_et + "_seq");

    // Now, add in the new timepoints and constraints
    std::string new_stp = task.id + "_st";
    std::string new_etp = task.id + "_et";

    // task.duration is st
    constraint start_seq = std::make_tuple("cz", new_stp, task.st - execution_threshold_, task.st + execution_threshold_);
    constraint task_dur = std::make_tuple(new_stp, new_etp, std::max(0.0,task.duration-execution_threshold_), task.duration+execution_threshold_);
    constraint head_seq = std::make_tuple(slot_st, new_stp, 0, inf);
    constraint tail_seq = std::make_tuple(new_etp, slot_et, 0, inf);

    stn.add_timepoint(new_stp);
    stn.add_timepoint(new_etp);

    bool status = stn.add_constraint("cz_" + new_stp + "_assignment", start_seq);
    status = status && stn.add_constraint(slot_st + "_" + new_stp + "_seq", head_seq);
    status = status && stn.add_constraint(new_stp + "_" + new_etp + "_dur", task_dur);
    status = status && stn.add_constraint(new_etp + "_" + slot_et + "_seq", tail_seq);

    if (!status) {
        stn.del_all_constraints(new_stp, new_etp);
        stn.del_all_constraints("cz",new_stp);
        stn.del_timepoint(new_stp);
        stn.del_timepoint(new_etp);
        constraint old_seq = std::make_tuple(slot_st, slot_et, 0, inf);
        stn.add_constraint(slot_st + "_" + slot_et + "_seq", old_seq);
    } else {
        TNode* new_task = new TNode(task.id, new_stp, new_etp);
        TNode* tmp = curr->next;
        curr->next = new_task;
        new_task->next = tmp;
    }

    return status;
}
/*
 * Callback function to process task messages that correspond to auctions
 * Input: Task that represents either an auction or auction winner
 * Output: Bid for task IF unowned, 
 */
void Agent::new_tasks_cb(const ma_interfaces::msg::Task task) {
    if (task.owner == "" && bid_map.find(task.id) == bid_map.end()) {
        // Generate a bid for the unowned task, first by searching for a slot
        std::vector<TNode*> slots = find_slots(task.duration);
        
        for (TNode* slot : slots) {
            double slack = 10;
            double st = max((double)curr_time_,-1*std::get<0>(stn.get_feasible_values(slot->etp_))) + slack;
            double et = std::get<1>(stn.get_feasible_values(slot->next->stp_));
            if (et-st >= task.duration) {
                // Build bid message
                ma_interfaces::msg::Bid bid = build_bid_msg(id_,task.id,0,st,et,10);
                
                // Publish bid
                if (agent_verbose_1) RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Publishing bid for auction %s: (%f,%f)", bid.auction_id.c_str(), bid.st, bid.et);
                task_bid_publisher_->publish(bid);
            }
        }
    } else if (task.owner == id_) {
        // Agent won the bid for the task, now want to schedule it
        if (agent_verbose_1) RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Won the bid for auction %s, duration = %f, times=(%f,%f)", task.id.c_str(), task.duration, task.st, task.et);

        if (schedule_task(task)) {
            // Able to add, send confirmation to auctioneer            
            auto msg = build_bid_msg(id_,task.id,1,0,0,0);
            if (agent_verbose_1) RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Publishing scheduling confirmation of task: %s", task.id.c_str());
            task_bid_publisher_->publish(msg);
            if (agent_verbose_1) print_timeline();
            // Check to see if there are any tasks to dispatch
        } else {
            // Unable to add message, send failure to auctioneer
            auto msg = build_bid_msg(id_,task.id,-1,0,task.duration,task.value);

            if (agent_verbose_1) RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Publishing scheduling failure of task: %s", task.id.c_str());
            task_bid_publisher_->publish(msg);
        }
    }
}

void Agent::check_dispatch() {
    if (timeline->status == TNode::COMPLETE) {
        // Action exists to dispatch
        TNode* curr = timeline->next;
        auto st = stn.get_feasible_values(curr->stp_);
        if (curr->name_ != "tail" && curr->status == TNode::WAITING && -1*std::get<0>(st) <= curr_time_ && curr_time_ <= std::get<1>(st)) {
            if (agent_verbose_2) RCLCPP_INFO(this->get_logger(), "Found task to dispatch: %s", curr->name_.c_str());
            ma_interfaces::msg::ActionDispatch msg = ma_interfaces::msg::ActionDispatch();
            msg.action_id = curr->name_;
            msg.agent_id = id_;
            msg.name = curr->name_;

            auto stp = stn.get_feasible_values(curr->stp_);
            auto etp = stn.get_feasible_values(curr->etp_);

            msg.duration = -1*(std::get<0>(etp) - std::get<0>(stp));
            msg.start_time = curr_time_;

            if (agent_verbose_1) RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Dispatching action: %s", msg.action_id.c_str());
            action_dispatch_publisher_->publish(msg);

            // Move timeline so that we are now on the current task
            curr->status = TNode::EXECUTING;
            task_map[curr->name_] = curr;
        }
    }
}

void Agent::new_bids_cb(const ma_interfaces::msg::Bid bid) {
    if (bid_map.find(bid.auction_id) != bid_map.end()) {
        if (bid.status < 0) {
            // Agent was unable to schedule task, cancel current set and choose next
            // std::vector<ma_interfaces::msg::Bid> invalid_winners = winner_map[bid.auction_id][0];
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Agent %s was unable to schedule task %s", bid.agent_id.c_str(), bid.auction_id.c_str());
            
            if (winner_map.find(bid.auction_id) != winner_map.end()) {
                for (ma_interfaces::msg::Bid wbid : winner_map[bid.auction_id][0]) {
                    ma_interfaces::msg::Task task = ma_interfaces::msg::Task();
                    task.owner = bid.agent_id;
                    task.st = bid.st;
                    task.duration = bid.et - bid.st;
                    task.et = bid.et;
                    if (agent_verbose_1) RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Publishing new winner for auction %s: agent %s (%f,%f)", task.id.c_str(), task.owner.c_str(), bid.st, bid.et);

                    task_auction_publisher_->publish(task);
                }
            }
        } else if (bid.status > 0 && (winner_map.find(bid.auction_id) != winner_map.end())) {
            // Task was scheduled, can now erase and close auction
            // bid_map.erase(bid.auction_id);
            bool all_scheduled = true;
            for (size_t i = 0; i < winner_map[bid.auction_id][0].size(); i++){
                ma_interfaces::msg::Bid wbid = winner_map[bid.auction_id][0][i];
                if (wbid.status < 0){
                    if (wbid.agent_id == bid.agent_id){
                        if (agent_verbose_1) RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Task <%s> was successfuly scheduled by agent %s, closing auction.", bid.auction_id.c_str(), bid.agent_id.c_str());
                        wbid.status = bid.status;
                    } else {
                        all_scheduled = false;
                    }
                }
            }
            if (all_scheduled) {
                if (agent_verbose_1) RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Task <%s> was successfully scheduled by all agents, closing auction", bid.auction_id.c_str());
                winner_map.erase(bid.auction_id);
            } else {
                winner_map[bid.auction_id].erase(winner_map[bid.auction_id].begin());
            }
        } else {
            // Auction is receiving bids
            if (bid_map[bid.auction_id].find(bid.agent_id) == bid_map[bid.auction_id].end()) {
                bid_map[bid.auction_id][bid.agent_id] = std::vector<ma_interfaces::msg::Bid>();
            }
            bid_map[bid.auction_id][bid.agent_id].push_back(bid);

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
                timeline = curr;
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
