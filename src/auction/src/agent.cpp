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
    double et,
    double x,
    double y
) {
    ma_interfaces::msg::Task task = ma_interfaces::msg::Task();
    task.id = id;
    task.owner = owner;
    task.num_agents = num_agents;
    task.value = value;
    task.duration = duration;
    task.st = st;
    task.et = et;
    task.x = x;
    task.y = y;
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
        {return (left[0].value < right[0].value) || (left[0].value == right[0].value && left[0].st < right[0].st);};
    
    std::sort(overlaps.begin(),overlaps.end(),cmp);

    // Erase the bid map entry, add the winner map
    winner_map[task.id] = overlaps;
    bid_map.erase(task.id);

    return winner_map[task.id][0];
}

void Agent::host_auction(ma_interfaces::msg::Goal &goal) {
    if (agent_verbose_1) RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Won goal %s @ (%f,%f)", goal.id.c_str(), goal.x, goal.y);

    double task_duration = 10;
    ma_interfaces::msg::Task task = build_task_msg(goal.id,"",goal.num_agents,10,task_duration,-1,goal.deadline, goal.x, goal.y);
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
void Agent::new_goals_cb(ma_interfaces::msg::Goal goal) {
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
 * Function to compute distance between two tasks. Returns 0 if second task is the tail
 */
double Agent::compute_dist(ma_interfaces::msg::Task &t1, ma_interfaces::msg::Task &t2) {
    if (t2.id == "tail") return 0;
    
    return round(sqrt(pow(t2.x-t1.x,2) + pow(t2.y-t1.y,2)));
}

/*
 * Function to unschedule a task on the timeline
 *
 * Input: TNode t that consists of a start and end timepoint. Function deletes all the constraints
 * that connect to these timepoints, therefore "unscheduling" the task
 * 
 * Output: All relevant constraints that were deleted
 */
std::vector<std::tuple<std::string,constraint>> Agent::unschedule_task(TNode* t) {
    map<string, constraint> constraints = stn.get_constraints();
    std::vector<std::tuple<std::string,constraint>> relevant_constraints;
    for (auto const& elt : constraints) {
        constraint c = elt.second;
        if (std::get<0>(c) == t->stp_ || std::get<1>(c) == t->etp_ || std::get<1>(c) == t->stp_ || std::get<0>(c) == t->etp_) {
            relevant_constraints.push_back(std::make_tuple(elt.first,c));
            stn.del_constraint(elt.first);
        }
    }

    stn.del_timepoint(t->stp_);
    stn.del_timepoint(t->etp_);

    return relevant_constraints;
}


/*
 * Function to find a slot that fits the given task, starting at the input
 * root node
 */
TNode* Agent::find_slot(TNode* root, ma_interfaces::msg::Task &task) {
    TNode* curr = root;

    while (curr->next_task) {
        TNode* next_task = curr->next_task;
        TNode* next_travel = curr->next;
        if (curr->next->name_ != "tail") {
            std::vector<std::tuple<std::string,constraint>> constraints = unschedule_task(next_travel);
            double total_dur = compute_dist(curr->task,task) + task.duration + compute_dist(task, next_task->task);
            constraint temp_c = std::make_tuple(curr->etp_,next_task->stp_,total_dur, inf);
            std::string temp_c_name = task.id + "_temp_c";

            bool status = stn.add_constraint(temp_c_name, temp_c);
            // Undo changes
            stn.del_constraint(temp_c_name);
            stn.add_timepoint(next_travel->stp_);
            stn.add_timepoint(next_travel->etp_);
            for (auto elt : constraints) {
                if (!stn.add_constraint(std::get<0>(elt), std::get<1>(elt))){
                    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Error re-adding constraints");
                }
            }
            if (status) break;
        } else {
            double st = -1*std::get<0>(stn.get_feasible_values(curr->etp_)); 
            double et = std::get<1>(stn.get_feasible_values(curr->next->stp_));
            double total_dur = compute_dist(curr->task,task) + task.duration; // Travel time to task
            if (et-st >= total_dur) {
                break;
            }
        }
        curr = curr->next_task;
    }

    return curr;
}

/*
 * Function to find all slots on an agent timeline that can accomplish the task.
 * Tasks are now located, have to only search between non-travel nodes. In particular,
 * we search for a slot by looking at a TNode curr, and examining its next and next_travel
 * nodes. If both exist, then this means that we need to travel from curr->task to curr->next->task,
 * so to check for a slot we "unschedule" the travel task, and see if a new constraint with lower bound
 * travel_time + task.duration fits on the timeline. If it does, then we have found a slot,
 * so we undo our changes and save the slot.
 * 
 * As an edge case, if our curr->next is the tail, we do a simple check to see if the task
 * and travel_to times can fit between our current node and the tail.
 *
 * Input: Duration representing size of slot
 * Output: TNode curr, where the slot is between curr and curr->next
 */
std::vector<TNode*> Agent::find_slots(ma_interfaces::msg::Task &task) {
    std::vector<TNode*> slots;
    TNode* curr = timeline;
    print_timeline();

    while (curr) {
        TNode* temp = find_slot(curr,task);
        if (temp->name_ != "tail") slots.push_back(temp);

        curr = temp->next_task;
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
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "---------------------\nPrinting timeline...");

    while (curr) {
        if (curr->name_ != "tail" && (curr->next != curr->next_task || curr->next_task->name_ == "tail")) {
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "%s: (%s, %s) @ (%f,%f)->\n", curr->name_.c_str(), curr->stp_.c_str(), curr->etp_.c_str(), curr->task.x, curr->task.y);
        } else {
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "%s: (%s, %s)->\n", curr->name_.c_str(), curr->stp_.c_str(), curr->etp_.c_str());
        }
        curr = curr->next;
    }
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "---------------------\n");
}

/*
 * Function to schedule task.
 * There are two possiblities: 1) the task has a start time and 2) the task does not.
 * The two cases are similar, except that in the latter case, we need to
 * assert that the task can be started at its specified time.
 * 
 * Therefore, the search process should be as follows: When looking for a slot
 * that has a start time, we create a temporary task node that represents
 * our task. We tie this to "CZ" with a strict constraint of (st-thresh,st+thresh).
 * We then iterate through the timeline, each time attempting to unschedule
 * the travel task between two nodes. We then connect these two nodes with
 * the temporary task node with a (travel_to, inf) bound coming in, and a
 * (travel_from + dur, inf) bound leaving. If adding these constraints 
 * is valid, then we have found a slot, and are done.
 * 
 * OTOH, if the task does not have a start time, then we can simply
 * look for a slot that can fit the task, similar to our find_slot
 * method.
 *
 * Input: Task to be scheduled
 * Output: Boolean value describing whether or not scheduling was successful
 */
bool Agent::schedule_task(ma_interfaces::msg::Task &task) {
    // Search for slot that covers task
    TNode* curr = timeline;
    std::vector<std::tuple<std::string, constraint>> constraints;
    TNode* slot;
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"),"Attempting to schedule task");
    print_timeline();
    stn.gen_dot_file("/home/gkasha/Documents/maae/data/agent_" + id_ + "_t_" + std::to_string(curr_time_) + ".dot");
    while (curr) {
        slot = find_slot(curr, task);
        if (slot->name_ != "tail") {
            if (task.st >= 0) {
                // Need to check that slot actually matches start time
                double to_dur = compute_dist(slot->task, task);
                double from_dur = task.duration;

                if (slot->next->name_ != "tail") {
                    TNode* next_travel = slot->next;
                    constraints = unschedule_task(next_travel);
                    from_dur += compute_dist(task, slot->next_task->task);
                }

                std::string temp_tp = "temp_task";
                stn.add_timepoint(temp_tp);
                constraint temp_to = std::make_tuple(slot->etp_,temp_tp, to_dur, inf);
                constraint temp_from = std::make_tuple(temp_tp, slot->next_task->stp_, from_dur, inf);
                constraint temp_st = std::make_tuple("cz", temp_tp, task.et-execution_threshold_, task.et+execution_threshold_);
                
                if (stn.add_constraint("temp_to", temp_to) 
                    && stn.add_constraint("temp_from", temp_from)
                    && stn.add_constraint("temp_st", temp_st)) {
                    // Task can fit within slot, break with this slot
                    stn.del_timepoint(temp_tp);
                    break;
                } else {
                    // Task can't fit, undo changes and continue
                    stn.del_timepoint(temp_tp);
                    stn.add_timepoint(slot->next->stp_);
                    stn.add_timepoint(slot->next->etp_);
                    for (auto elt : constraints) {
                        stn.add_constraint(std::get<0>(elt), std::get<1>(elt));
                    }
                }
            } else {
                // Just need to unschedule travel task, if it exists
                if (slot->next->name_ != "tail") {
                    constraints = unschedule_task(slot->next);
                }
                break;
            }
        }
        curr = slot->next_task;
    }

    // At this point, we either have a pointer to our current slot, or our pointer is null
    if (!curr){
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Unable to find slot to schedule task...");
        return false;
    }

    // Attempt to schedule slot. First, create travel to slot
    std::string new_travel_to_stp = slot->name_ + "_" + task.id + "_travel_st";
    std::string new_travel_to_etp = slot->name_ + "_" + task.id + "_travel_et";

    std::string new_task_stp = task.id + "_st";
    std::string new_task_etp = task.id + "_et";

    std::string new_travel_from_stp = task.id + "_" + slot->next->name_ + "_travel__st";
    std::string new_travel_from_etp = task.id + "_" + slot->next->name_ + "_travel_et";


    stn.add_timepoint(new_travel_to_stp);
    stn.add_timepoint(new_travel_to_etp);
    stn.add_timepoint(new_task_stp);
    stn.add_timepoint(new_task_etp);
    stn.add_timepoint(new_travel_from_stp);
    stn.add_timepoint(new_travel_from_etp);

    // At this point, there should only be sequencing constraints between
    // adjacent timepoints, which we don't really care about
    double travel_to_dur = compute_dist(slot->task,task)/speed_;

    constraint travel_to_st_c = std::make_tuple(slot->etp_, new_travel_to_stp, 0, inf);
    constraint travel_to_c = std::make_tuple(new_travel_to_stp, new_travel_to_etp, travel_to_dur, inf);
    constraint travel_to_et_c = std::make_tuple(new_travel_to_etp, new_task_stp, 0, inf);
    constraint task_dur_c = std::make_tuple(new_task_stp, new_task_etp, task.duration-execution_threshold_, task.duration+execution_threshold_);

    int status = 0;
    if (!stn.add_constraint(slot->name_ + "_" + task.id + "_travel_st", travel_to_st_c)
        || !stn.add_constraint(slot->name_ + "_" + task.id + "_travel_dur", travel_to_c)
        || !stn.add_constraint(task.id + "_travel_et", travel_to_et_c)
        || !stn.add_constraint(task.id + "_task_dur", task_dur_c)) 
    {
        
        status = -1;
    } else {
        status = 1;
    }

    if (status >= 1) {
        if (task.st >= 0) {
            constraint start_seq = std::make_tuple("cz", new_task_stp, task.st-execution_threshold_, task.st+execution_threshold_);
            if (!stn.add_constraint(task.id + "_start_seq", start_seq)) {
                status = -2;
            } else {
                status = 2;
            }
        }
    }

    
    if (status >= 1){
        if (slot->next->name_ != "tail") {
            double travel_from_dur = compute_dist(task, slot->next->task)/speed_;
            constraint travel_from_st_c = std::make_tuple(new_task_etp, new_travel_from_stp, 0, inf);
            constraint travel_from_c = std::make_tuple(new_travel_from_stp, new_travel_from_etp, travel_from_dur, inf);
            constraint travel_from_et_c = std::make_tuple(new_travel_from_etp, slot->next->stp_, 0, inf);

            if (!stn.add_constraint(task.id + "_" + slot->next->name_ + "_travel_st", travel_from_st_c)
                || !stn.add_constraint(task.id + "_" + slot->next->name_ + "travel_dur", travel_from_c)
                || !stn.add_constraint(task.id + "_" + slot->next->name_ + "_travel_et", travel_from_et_c))
            {
                status = -3;
            } else {
                status = 3;
            }
        } else {
            constraint end_seq = std::make_tuple(new_task_etp, slot->next->stp_, 0, inf);
            if (!stn.add_constraint(new_task_etp + "_" + slot->next->stp_ + "_seq", end_seq)) {
                status = -2;
            } else {
                status = 2;
            }
        }
    }
    
    if (status >= 1) {
        TNode* travel_to = new TNode(slot->name_ + "_" + task.id + "_travel", new_travel_to_stp, new_travel_to_etp);
        travel_to->task = build_task_msg(slot->name_ + "_" + task.id + "_travel", "", 0, 0, compute_dist(slot->task,task)/speed_, 0,0,0,0);
        slot->next = travel_to;

        TNode* new_task = new TNode(task.id, new_task_stp, new_task_etp);
        new_task->task = task;
        new_task->next = slot->next_task;
        new_task->next_task = slot->next_task;
        travel_to->next = new_task;
        travel_to->next_task = new_task;
        slot->next_task = new_task;

        if (status >= 3) {
            TNode* travel_from = new TNode(task.id + "_" + slot->next_task->name_ + "_travel", new_travel_from_stp, new_travel_from_etp);
            travel_from->task = build_task_msg(task.id + "_" + slot->next_task->name_ + "_travel", "", 0, 0, compute_dist(task,slot->next_task->task)/speed_,0,0,0,0);
            travel_from->next = new_task->next_task;
            travel_from->next_task = new_task->next_task;
            new_task->next = travel_from;
        } else {
            stn.del_timepoint(new_travel_from_stp);
            stn.del_timepoint(new_travel_from_etp);
        }
        return true;
    } else {
        stn.del_timepoint(new_travel_to_stp);
        stn.del_timepoint(new_travel_to_etp);
        stn.del_timepoint(new_task_stp);
        stn.del_timepoint(new_task_etp);
        stn.del_timepoint(new_travel_from_stp);
        stn.del_timepoint(new_travel_from_etp);
        
        stn.add_timepoint(slot->next->stp_);
        stn.add_timepoint(slot->next->etp_);
        for (auto elt : constraints) {
            stn.add_constraint(std::get<0>(elt), std::get<1>(elt));
        }
        return false;
    }
}
/*
 * Callback function to process task messages that correspond to auctions
 * Input: Task that represents either an auction or auction winner
 * Output: Bid for task IF unowned, 
 */
void Agent::new_tasks_cb(ma_interfaces::msg::Task task) {
    if (task.owner == "" && bid_map.find(task.id) == bid_map.end()) {
        // Generate a bid for the unowned task, first by searching for a slot
        std::vector<TNode*> slots = find_slots(task);
        
        for (TNode* slot : slots) {
            double slack = 10;
            double travel_to = compute_dist(slot->task,task)/speed_;
            double travel_from = compute_dist(task,slot->next_task->task)/speed_;
            double st = max((double)curr_time_,-1*std::get<0>(stn.get_feasible_values(slot->etp_))) + travel_to + slack;
            double et = std::get<1>(stn.get_feasible_values(slot->next->stp_)) - travel_from;
            if (et-st >= task.duration) {
                // Build bid message
                ma_interfaces::msg::Bid bid = build_bid_msg(id_,task.id,0,st,et,travel_to);
                
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
    auto agent_node = std::make_shared<Agent>(argv[1], std::stod(argv[2]), std::stod(argv[3]), std::stod(argv[4]));

    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Agent %s started", argv[1]);

    executor.add_node(agent_node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}
