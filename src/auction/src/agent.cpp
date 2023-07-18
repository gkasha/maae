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
    double execution_range,
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
    task.execution_range = execution_range;
    task.st = st;
    task.et = et;
    task.x = x;
    task.y = y;
    return task;
}

void Agent::gen_timeline_dot(std::string filename) {
    cout << "Printing dot file: " << filename << endl;
    ofstream fout(filename);
    fout << "digraph timeline {" << std::endl;
    TNode* curr = timeline_head;
    
    while (curr) {
        fout << curr->name_ << "[label=";
        fout << "\"" << curr->name_ << "\"";
        if (curr->status == TNode::EXECUTING) {
            fout << ",style=filled,fillcolor=orange,fontcolor=black];" << std::endl;
        } else if (curr->status == TNode::WAITING) {
            fout << ",style=filled,fillcolor=gray,fontcolor=black];" << std::endl;
        } else {
            fout << ",style=filled,fillcolor=green,fontcolor=black];" << std::endl;
        }
        curr = curr->next;
    }

    curr = timeline_head;
    while (curr->next) {
        fout << "\"" << curr->name_ << "\""
            << "->"
            << "\"" << curr->next->name_ << "\""
            << "[color=black];" << std::endl;
        curr = curr->next;
    }
    
    fout << "}" << std::endl;
    fout.close();
    cout << "Done creating dot file" << std::endl;
}

void Agent::clock_cb(const std_msgs::msg::Int64::SharedPtr msg) {
    mtx.lock();
    curr_time_ = msg->data;
    constraint orig_c = stn.get_constraint("now_constraint");
    stn.del_constraint("now_constraint");
    constraint c = std::make_tuple("cz", "now", curr_time_, inf);
    if (!stn.add_constraint("now_constraint", c)) {
        // If task is still in execution, try increasing length. If this is a fix, then 
        // that means we are inconsistent because we are outside the expected bounds.
        // If it not a fit, then that means there is a different violation, possibly due to start times,
        // so we should try replanning the next task
        stn.add_constraint("now_constraint", orig_c);

        if (timeline->status == TNode::EXECUTING) {
            
            // Remove task time and replace with current
            double action_st = std::get<1>(stn.get_feasible_values(timeline->stp_));
            std::string c_name = timeline->task.id + "_task_dur";
            constraint orig_task_c = stn.get_constraint(c_name);
            stn.del_constraint(c_name);
            constraint new_dur = std::make_tuple(timeline->stp_, timeline->etp_, curr_time_ - action_st, (curr_time_ - action_st)*(1+scheduling_range_));
            
            if (!stn.add_constraint(c_name, new_dur)) {
                RCLCPP_ERROR(this->get_logger(), "[%d] Unable to replace task duration with actual, possibly due to too little slack, attempting to replan future task", curr_time_);
                // Use original range
                stn.add_constraint(c_name, orig_task_c);

                TNode* next_task = timeline->next_task;

                if (next_task->name_ != "tail") {
                    bool safe = true;
                    if (next_task->task.st >= 0) {
                        // Next task is a joint activity, window might be too tight to replan
                        std::string start_name = next_task->name_ + "_start_seq";
                        constraint start_c = stn.get_constraint(start_name);
                        std::get<3>(start_c) += coordination_range_;
                        stn.del_constraint(start_name);
                        if (!stn.add_constraint(start_name, start_c)) {
                            // Can't shift the start time, next next task is constrained, try to replan
                            if (next_task->next_task->name_ != "tail") {
                                multi_agent_replan(next_task->next_task);
                                // single_agent_replan(next_task->next_task);
                            } else {
                                RCLCPP_ERROR(this->get_logger(), "[%d] Can't replan future task", curr_time_);
                                safe = false;
                            }
                        } else {
                            // Able to shift start time, should be ok
                            RCLCPP_INFO(this->get_logger(), "[%d] Shifted start time of activity %s", curr_time_, next_task->name_.c_str());
                        }
                    } else {
                        if (!timeline->located) {
                            // Moving to a new task, can't handle next task
                            if (next_task->name_ != "tail") {
                                next_task = timeline->next_task;
                                multi_agent_replan(next_task);
                                // single_agent_replan(next_task);
                            } else {
                                RCLCPP_ERROR(this->get_logger(), "[%d] No tasks to replan", curr_time_);
                                safe = false;
                            }
                        } else {
                            multi_agent_replan(next_task);
                            // single_agent_replan(next_task);
                        }
                    }
                    if (safe) {
                        stn.del_constraint(c_name);
                        if (!stn.add_constraint(c_name, new_dur)) {
                            RCLCPP_ERROR(this->get_logger(), "[%d] Couldn't extend task after creating slack", curr_time_);
                        } else {
                            stn.del_constraint("now_constraint");
                            if (!stn.add_constraint("now_constraint", c)) {
                                RCLCPP_ERROR(this->get_logger(), "[%d] Couldn't update now constraint after creating slack", curr_time_);
                            } else {
                                RCLCPP_INFO(this->get_logger(), "[%d] Successfully handled now constraint update", curr_time_);
                            }
                        }
                    } else {
                        RCLCPP_ERROR(this->get_logger(), "[%d] Unable to safely handle now constraint update", curr_time_);
                    }
                } else {
                    RCLCPP_ERROR(this->get_logger(), "[%d] Nothing else to replan", curr_time_);
                }
            } else {
                RCLCPP_INFO(this->get_logger(), "[%d] Task %s is delayed", curr_time_, timeline->name_.c_str());
                if (!stn.add_constraint("now_constraint", c)) {
                    RCLCPP_ERROR(this->get_logger(), "[%d] Couldn't update now constraint after updating task duration", curr_time_);
                }
            }
        }
    }

    check_dispatch();
    mtx.unlock();
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
                        if (task.st >= 0) {
                            if (task.st >= st){
                                st = task.st;
                            } else {
                                continue;
                            }
                        }
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
            bid.status = -1;
            overlaps.push_back({bid});
        }    
    }
    

    // Choose best interval by earliest start time
    auto cmp = [](
        std::vector<ma_interfaces::msg::Bid> left,
        std::vector<ma_interfaces::msg::Bid> right)
        {
            double left_val = 0;
            double right_val = 0;
            for (ma_interfaces::msg::Bid bid : left) {
                left_val += bid.value;
            }
            for (ma_interfaces::msg::Bid bid : right) {
                right_val += bid.value;
            }
            return (left_val < right_val) || (left_val == right_val && left[0].st < right[0].st);
        };
    
    std::sort(overlaps.begin(),overlaps.end(),cmp);

    // Erase the bid map entry, add the winner map
    winner_map[task.id] = std::make_tuple(task,overlaps);

    if (std::get<1>(winner_map[task.id]).empty()) {
        return std::vector<ma_interfaces::msg::Bid>();
    }
    return std::get<1>(winner_map[task.id])[0];
}

bool Agent::host_auction(ma_interfaces::msg::Goal &goal) {

    // if (goal.id == "task1") task_duration += 20;
    // if (goal.id == "task2") task_duration -= ;
    ma_interfaces::msg::Task task = build_task_msg(goal.id,"",goal.num_agents,10,goal.duration,goal.execution_range,goal.deadline,-1, goal.x, goal.y);
    std::map<std::string,std::vector<ma_interfaces::msg::Bid>> new_map;
    bid_map[task.id] = new_map;

    // Send out auction
    if (agent_verbose_1) RCLCPP_INFO(this->get_logger(), "Publishing auction for task %s", task.id.c_str());
    task_auction_publisher_->publish(task);

    // Wait to collect bids
    rclcpp::sleep_for(std::chrono::duration_cast<std::chrono::seconds>(std::chrono::duration<double>(auction_time_)));

    // Choose winner -- default is earliest start time
    std::vector<ma_interfaces::msg::Bid> winning_bids = choose_winners(task);

    if (winning_bids.empty()) {
        RCLCPP_INFO(this->get_logger(), "Not enough bids for task %s", task.id.c_str());
        return false;
    }
    // Send out winners
    for (ma_interfaces::msg::Bid bid : winning_bids) {
        task.owner = bid.agent_id;
        if (agent_verbose_1) RCLCPP_INFO(this->get_logger(), "Publishing winner for auction %s: agent %s (%f,%f)", task.id.c_str(), task.owner.c_str(), bid.st, bid.et);
        if (task.num_agents > 1) {
            task.st = bid.st;
            task.et = task.st + task.duration;
        }
        task_auction_publisher_->publish(task);
    }
    return true;
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
        if (agent_verbose_1) RCLCPP_INFO(this->get_logger(), "Publishing bid for goal %s", goal.id.c_str());

        ma_interfaces::msg::Bid bid = build_bid_msg(id_,goal.id,0,0,0,10);
        goal_bid_publisher_->publish(bid);
    } else if (goal.owner == id_) {
        if (agent_verbose_1) RCLCPP_INFO(this->get_logger(), "Won goal %s @ (%f,%f)", goal.id.c_str(), goal.x, goal.y);
        host_auction(goal);
    }
}

/*
 * Function to compute distance between two tasks. Returns 0 if second task is the tail
 */
double Agent::compute_dist(ma_interfaces::msg::Task &t1, ma_interfaces::msg::Task &t2) {
    if (t2.id == "tail") return 0;

    double res = round(sqrt(pow(t2.x-t1.x,2) + pow(t2.y-t1.y,2)));
    
    return res;
}

double Agent::compute_dist(double x1, double y1, double x2, double y2) {
    return round(sqrt(pow(x2-x1,2) + pow(y2-y1,2)));
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
std::tuple<double,TNode*> Agent::find_slot(TNode* root, ma_interfaces::msg::Task &task) {
    TNode* curr = root;
    
    while (curr && !curr->located) {
        curr = curr->next_task;
    }

    if (!curr) return std::tuple(inf,nullptr);

    std::vector<std::tuple<std::string, constraint>> constraints;
    double makespan = 0;
    while (curr->next_task) {
        double to_dur = compute_dist(curr->task, task);
        double slack = task.duration*scheduling_range_;
        double from_dur = task.duration;

        constraint now_seq = stn.get_constraint("now_seq");

        if (curr->next_task->located) {
            TNode* next_travel = curr->next;
            constraints = unschedule_task(next_travel);
            from_dur += compute_dist(task, curr->next_task->task);
        }

        std::string temp_tp = "temp_task";
        stn.add_timepoint(temp_tp);
        constraint temp_to = std::make_tuple(curr->etp_,temp_tp, to_dur, inf);
        constraint temp_from = std::make_tuple(temp_tp, curr->next_task->stp_, from_dur - slack, from_dur + slack);
        bool status = true;
        bool is_now = std::get<0>(now_seq) == curr->next->stp_ || std::get<1>(now_seq) == curr->next->etp_;

        // If the now seq constraint points to the next travel task, we need to add it back into our STN after deleting the travel task
        if (is_now) {
            constraint temp_now_seq;
            if (curr->status == TNode::COMPLETE) {
                temp_now_seq = std::make_tuple("now", temp_tp, 0, inf);
            } else {
                temp_now_seq = std::make_tuple("now", curr->etp_, 0, inf);
            }
            status = stn.add_constraint("now_seq", temp_now_seq);
        }


        // Check if we the network is temporally consistent, including the start time constraint
        if (status 
            && stn.add_constraint("temp_to", temp_to)
            && stn.add_constraint("temp_from", temp_from)) {
            
            if (task.st >= 0) {
                constraint temp_st = std::make_tuple("cz", temp_tp, task.st - coordination_range_, task.st + coordination_range_);
                if (stn.add_constraint("temp_st", temp_st)) {
                    status = true;
                    makespan = -1*std::get<0>(stn.get_feasible_values("end"));
                } else {
                    status = false;
                }
            } else {
                makespan = -1*std::get<0>(stn.get_feasible_values("end"));
                status = true;
            }
        } else {
            status = false;
        }

        stn.del_timepoint(temp_tp);
        stn.add_timepoint(curr->next->stp_);
        stn.add_timepoint(curr->next->etp_);
        if (is_now) {
            // Delete temporary now constraint, will add in original in next loop
            stn.del_constraint("now_seq");
        }

        for (auto elt : constraints) {
            stn.add_constraint(std::get<0>(elt), std::get<1>(elt));
        }
        
        if (status) break;

        curr = curr->next_task;
    }

    return std::make_tuple(makespan,curr);
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
std::vector<std::tuple<double,TNode*>> Agent::find_slots(ma_interfaces::msg::Task &task) {
    std::vector<std::tuple<double,TNode*>> slots;
    TNode* curr = timeline;

    while (curr) {
        std::tuple<double,TNode*> temp = find_slot(curr,task);
        if (!std::get<1>(temp)) {
            break;
        } else {
            if (std::get<1>(temp)->located) slots.push_back(temp);
        }

        curr = std::get<1>(temp)->next_task;
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
    RCLCPP_INFO(this->get_logger(), "---------------------\nPrinting timeline...");

    while (curr) {
        if (curr->name_ != "tail" && (curr->next != curr->next_task || curr->next_task->name_ == "tail")) {
            RCLCPP_INFO(this->get_logger(), "%s: (%s, %s) @ (%f,%f)->\n", curr->name_.c_str(), curr->stp_.c_str(), curr->etp_.c_str(), curr->task.x, curr->task.y);
        } else {
            RCLCPP_INFO(this->get_logger(), "%s: (%s, %s)->\n", curr->name_.c_str(), curr->stp_.c_str(), curr->etp_.c_str());
        }
        curr = curr->next;
    }
    RCLCPP_INFO(this->get_logger(), "---------------------\n");
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
bool Agent::schedule_task(ma_interfaces::msg::Task &task, TNode* slot=nullptr) {
    // Search for slot that covers task
    TNode* curr = timeline;
    constraint now_seq = stn.get_constraint("now_seq");

    if (curr->status == TNode::EXECUTING || (curr->name_ != "head" && curr->next_task->name_ != "tail") || (curr->next->name_ != "tail" && !curr->located)) {
        curr = curr->next_task;
    }

    RCLCPP_INFO(this->get_logger(),"Attempting to schedule task");
    std::vector<std::tuple<double,TNode*>> slots = find_slots(task);

    auto cmp = [](std::tuple<double,TNode*> left, std::tuple<double,TNode*> right){
        return std::get<0>(left) < std::get<0>(right);
    };

    if (!slot) {
        if (slots.empty()) {
            RCLCPP_INFO(this->get_logger(), "No slot found");
            return false;
        } else {
            slot = std::get<1>(*std::min_element(slots.begin(),slots.end(),cmp));
        }
    }

    if (slot->name_ == "tail") {
        return false;
    }

    RCLCPP_INFO(this->get_logger(), "Found slot between %s and %s", slot->name_.c_str(), slot->next_task->name_.c_str());

    std::vector<std::tuple<std::string,constraint>> constraints;
    if (slot->next->name_ != "tail") {
        // Unschedule travel task
        constraints = unschedule_task(slot->next);
    }
    // Attempt to schedule slot. First, create travel to slot
    std::string new_travel_to_stp = slot->name_ + "_" + task.id + "_travel_st";
    std::string new_travel_to_etp = slot->name_ + "_" + task.id + "_travel_et";

    std::string new_task_stp = task.id + "_st";
    std::string new_task_etp = task.id + "_et";

    std::string new_travel_from_stp = task.id + "_" + slot->next_task->name_ + "_travel__st";
    std::string new_travel_from_etp = task.id + "_" + slot->next_task->name_ + "_travel_et";


    stn.add_timepoint(new_travel_to_stp);
    stn.add_timepoint(new_travel_to_etp);
    stn.add_timepoint(new_task_stp);
    stn.add_timepoint(new_task_etp);
    stn.add_timepoint(new_travel_from_stp);
    stn.add_timepoint(new_travel_from_etp);

    // At this point, there should only be sequencing constraints between
    // adjacent timepoints, which we don't really care about
    double travel_to_dur = compute_dist(slot->task,task)/speed_;
    double slack = task.duration*scheduling_range_;

    constraint travel_to_st_c = std::make_tuple(slot->etp_, new_travel_to_stp, 0, inf);
    constraint travel_to_c = std::make_tuple(new_travel_to_stp, new_travel_to_etp, travel_to_dur, inf);
    constraint travel_to_et_c = std::make_tuple(new_travel_to_etp, new_task_stp, 0, inf);
    constraint task_dur_c = std::make_tuple(new_task_stp, new_task_etp, task.duration-slack, task.duration+slack);

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
            constraint start_seq = std::make_tuple("cz", new_task_stp, task.st-coordination_range_, task.st+coordination_range_);
            if (!stn.add_constraint(task.id + "_start_seq", start_seq)) {
                status = -2;
            } else {
                status = 2;
            }
        }
    }

    
    if (status >= 1){
        if (slot->next_task->located) {
            double travel_from_dur = compute_dist(task, slot->next_task->task)/speed_;
            constraint travel_from_st_c = std::make_tuple(new_task_etp, new_travel_from_stp, 0, inf);
            constraint travel_from_c = std::make_tuple(new_travel_from_stp, new_travel_from_etp, travel_from_dur, inf);
            constraint travel_from_et_c = std::make_tuple(new_travel_from_etp, slot->next_task->stp_, 0, inf);

            if (!stn.add_constraint(task.id + "_" + slot->next_task->name_ + "_travel_st", travel_from_st_c)
                || !stn.add_constraint(task.id + "_" + slot->next_task->name_ + "travel_dur", travel_from_c)
                || !stn.add_constraint(task.id + "_" + slot->next_task->name_ + "_travel_et", travel_from_et_c))
            {
                status = -3;
            } else {
                status = 3;
            }
        } else {
            constraint end_seq = std::make_tuple(new_task_etp, slot->next_task->stp_, 0, inf);
            if (!stn.add_constraint(new_task_etp + "_" + slot->next_task->stp_ + "_seq", end_seq)) {
                status = -2;
            } else {
                status = 2;
            }
        }
    }
    
    if (status >= 1) {
        TNode* travel_to = new TNode(slot->name_ + "_" + task.id + "_travel", new_travel_to_stp, new_travel_to_etp);
        travel_to->task = build_task_msg(slot->name_ + "_" + task.id + "_travel", id_, 1, 0, compute_dist(slot->task,task)/speed_, 0, 0,0,0,0);
        slot->next = travel_to;

        TNode* new_task = new TNode(task.id, new_task_stp, new_task_etp);
        new_task->task = task;
        new_task->located = true;
        new_task->next = slot->next_task;
        new_task->next_task = slot->next_task;
        travel_to->next = new_task;
        travel_to->next_task = new_task;
        slot->next_task = new_task;

        if (status >= 3) {
            TNode* travel_from = new TNode(task.id + "_" + new_task->next_task->name_ + "_travel", new_travel_from_stp, new_travel_from_etp);
            travel_from->task = build_task_msg(task.id + "_" + new_task->next_task->name_ + "_travel", "", 1, 0, compute_dist(task,new_task->next_task->task)/speed_,0,0,0,0,0);
            travel_from->next = new_task->next_task;
            travel_from->next_task = new_task->next_task;
            new_task->next = travel_from;
        } else {
            // There was no travel_from action, so delete the timepoints
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
    mtx.lock();
    if (task.owner == "") {
        // Generate a bid for the unowned task, first by searching for a slot
        std::vector<std::tuple<double,TNode*>> slots = find_slots(task);
        RCLCPP_INFO(this->get_logger(), "Found %ld slots", slots.size());
        
        for (std::tuple<double,TNode*> slot_tuple : slots) {
            TNode* slot = std::get<1>(slot_tuple);
            double travel_to = compute_dist(slot->task,task)/speed_;
            double travel_from = compute_dist(task,slot->next_task->task)/speed_;
            double st = max((double)curr_time_,-1*std::get<0>(stn.get_feasible_values(slot->etp_))) + travel_to + auction_time_;
            double et = std::get<1>(stn.get_feasible_values(slot->next->stp_)) - travel_from;
            if (et-st >= task.duration) {
                // Build bid message
                ma_interfaces::msg::Bid bid = build_bid_msg(id_,task.id,0,st,et,-1*std::get<0>(stn.get_feasible_values("end")));
                
                // Publish bid
                if (agent_verbose_1) RCLCPP_INFO(this->get_logger(), "[%d] Publishing bid for auction %s: (%f,%f) = %f", curr_time_, bid.auction_id.c_str(), bid.st, bid.et, bid.value);
                task_bid_publisher_->publish(bid);
            }
        }
    } else if (task.owner == id_) {
        // Agent won the bid for the task, now want to schedule it
        if (agent_verbose_1) RCLCPP_INFO(this->get_logger(), "Won the bid for auction %s, duration = %f, times=(%f,%f)", task.id.c_str(), task.duration, task.st, task.et);
        if (schedule_task(task)) {
            stn.gen_dot_file("/home/gkasha/Documents/maae/data/dot_files/agent_stn_" + id_ + "_t_" + std::to_string(curr_time_) + ".dot");

            // Able to add, send confirmation to auctioneer            
            auto msg = build_bid_msg(id_,task.id,1,0,0,0);
            if (agent_verbose_1) RCLCPP_INFO(this->get_logger(), "Publishing scheduling confirmation of task: %s", task.id.c_str());
            task_bid_publisher_->publish(msg);
            // Check to see if there are any tasks to dispatch
        } else {
            // Unable to add message, send failure to auctioneer
            auto msg = build_bid_msg(id_,task.id,-1,0,task.duration,task.value);

            if (agent_verbose_1) RCLCPP_ERROR(this->get_logger(), "Publishing scheduling failure of task: %s", task.id.c_str());
            task_bid_publisher_->publish(msg);
        }
    }
    mtx.unlock();
}

// Assume curr is timeline->next
void Agent::single_agent_replan(TNode* curr) {
    
    // Negative replanning
    TNode* slot = std::get<1>(find_slot(curr, curr->task));
    if (slot->name_ != "tail") {

        // Unschedule next task and its relevant travel activities
        TNode* travel_to = timeline->next;
        std::vector<std::tuple<std::string,constraint>> constraints_to = unschedule_task(travel_to);
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Travel to task: %s = (%f,%f)", travel_to->name_.c_str(), std::get<0>(stn.get_feasible_values(travel_to->stp_)), std::get<1>(stn.get_feasible_values(travel_to->etp_)));
        std::vector<std::tuple<std::string,constraint>> constraints = unschedule_task(curr);
        std::vector<std::tuple<std::string,constraint>> constraints_from;
        if (curr->next->name_ != "tail") {
            constraints_from = unschedule_task(curr->next);
        }

        timeline->next_task = curr->next_task;

        // Schedule new travel task
        std::string stp = timeline->name_ + "_" + timeline->next_task->name_ + "_travel_st"; 
        std::string etp = timeline->name_ + "_" + timeline->next_task->name_ + "_travel_et";
        stn.add_timepoint(stp);
        stn.add_timepoint(etp);

        constraint st_c = std::make_tuple(timeline->etp_,stp,0,inf);
        constraint travel_c = std::make_tuple(stp, etp, compute_dist(timeline->task,timeline->next_task->task)/speed_,inf);
        constraint et_c = std::make_tuple(etp, timeline->next_task->stp_, 0, inf);
        bool status = stn.add_constraint(timeline->name_ + "_" + timeline->next_task->name_ + "_travel_st", st_c);
        status &= stn.add_constraint(timeline->name_ + "_" + timeline->next_task->name_ + "_travel_dur", travel_c);
        status &= stn.add_constraint(timeline->name_ + "_" + timeline->next_task->name_ + "_travel_et", et_c);
        
        if (!status) {
            RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Unable to add travel constraint between new tasks [%d]", curr_time_);
        }

        if (schedule_task(curr->task, slot)) {
            TNode* new_travel = new TNode(timeline->name_ + "_" + timeline->next_task->name_ + "_travel", stp,etp);
            new_travel->task = build_task_msg(timeline->name_ + "_" + timeline->next_task->name_ + "_travel", "", 1, 0, compute_dist(timeline->task,timeline->next_task->task)/speed_,0,0,0,0,0);
            timeline->next = new_travel;
            new_travel->next = timeline->next_task;
            new_travel->next_task = timeline->next_task;

            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Moved task down the timeline");
            gen_timeline_dot("/home/gkasha/Documents/maae/data/dot_files/agent_timeline_shuffle_" + id_ + "_t_" + std::to_string(curr_time_) + ".dot");
        } else {
            RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Unable to move task down timeline");
            if (curr->task.st >= 0) {
                std::string start_name = curr->name_ + "_start_seq";
                constraint start_c = stn.get_constraint(start_name);
                std::get<3>(start_c) += coordination_range_;
                stn.del_constraint(start_name);
                if (!stn.add_constraint(start_name, start_c)) {
                    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Unable to replan new task by shifting start time");
                } else {
                    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Replanned new task by shifting start time");
                }
            }
        }
    }
    
}

void Agent::multi_agent_replan(TNode* curr) {
    nr_count++;
    RCLCPP_INFO(this->get_logger(), "\n=============Replan Counter=============\n\t%d\t%d", pr_count, nr_count);
    ma_interfaces::msg::Goal goal = ma_interfaces::msg::Goal();
    goal.id = curr->task.id;
    goal.owner = id_;
    goal.num_agents = 1;
    goal.duration = curr->task.duration;
    goal.execution_range = curr->task.execution_range;
    goal.deadline = curr->task.st;
    goal.x = curr->task.x;
    goal.y = curr->task.y;

    if (host_auction(goal)) {
        std::vector<std::tuple<std::string,constraint>> constraints_to = unschedule_task(timeline->next);
        std::vector<std::tuple<std::string,constraint>> constraints = unschedule_task(curr);
        std::vector<std::tuple<std::string,constraint>> constraints_from;
        if (curr->next_task->name_ != "tail") {
            constraints_from = unschedule_task(curr->next);
        }

        timeline->next_task = curr->next_task;

        // Schedule new travel task
        std::string stp = timeline->name_ + "_" + timeline->next_task->name_ + "_travel_st"; 
        std::string etp = timeline->name_ + "_" + timeline->next_task->name_ + "_travel_et";
        stn.add_timepoint(stp);
        stn.add_timepoint(etp);

        constraint st_c = std::make_tuple(timeline->etp_,stp,0,inf);
        constraint travel_c = std::make_tuple(stp, etp, compute_dist(timeline->task,timeline->next_task->task)/speed_,inf);
        constraint et_c = std::make_tuple(etp, timeline->next_task->stp_, 0, inf);
        bool status = stn.add_constraint(timeline->name_ + "_" + timeline->next_task->name_ + "_travel_st", st_c);
        status &= stn.add_constraint(timeline->name_ + "_" + timeline->next_task->name_ + "_travel_dur", travel_c);
        status &= stn.add_constraint(timeline->name_ + "_" + timeline->next_task->name_ + "_travel_et", et_c);
        
        if (!status) {
            RCLCPP_ERROR(this->get_logger(), "Unable to add travel constraint between new tasks [%d]", curr_time_);
        }

        TNode* new_travel = new TNode(timeline->name_ + "_" + timeline->next_task->name_ + "_travel", stp,etp);
        new_travel->task = build_task_msg(timeline->name_ + "_" + timeline->next_task->name_ + "_travel", "", 1, 0, compute_dist(timeline->task,timeline->next_task->task)/speed_,0,0,0,0,0);
        timeline->next = new_travel;
        new_travel->next = timeline->next_task;
        new_travel->next_task = timeline->next_task;

        RCLCPP_INFO(this->get_logger(), "[%d] Successfully replanned task %s", curr_time_, curr->name_.c_str());
    } else {
        RCLCPP_INFO(this->get_logger(), "[%d] Couldn't find agent to take task %s", curr_time_, curr->task.id.c_str());
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
            msg.num_agents = curr->task.num_agents;
            // auto stp = stn.get_feasible_values(curr->stp_);
            // auto etp = stn.get_feasible_values(curr->etp_);
            msg.execution_range = curr->task.execution_range;
            msg.duration = curr->task.duration;
            msg.start_time = curr_time_;

            if (agent_verbose_1) RCLCPP_INFO(this->get_logger(), "Dispatching action: %s, duration=%f", msg.action_id.c_str(), msg.duration);
            action_dispatch_publisher_->publish(msg);

            // Move timeline so that we are now on the current task
            task_map[curr->name_] = curr;
            timeline = curr;
            curr->status = TNode::EXECUTING;
            stn.del_constraint("now_seq");
            constraint now_c = std::make_tuple("now", curr->etp_, 0, inf);
            if (!stn.add_constraint("now_seq", now_c)) {
                RCLCPP_ERROR(this->get_logger(), "[%d] Unable to add now_seq constraint", curr_time_);
            }

            constraint c = std::make_tuple("cz", curr->stp_, curr_time_, curr_time_);
            bool status = stn.add_constraint(curr->stp_ + "_actual", c);
            if (status) {
                gen_timeline_dot("/home/gkasha/Documents/maae/data/dot_files/agent_timeline_" + id_ + "_t_" + std::to_string(curr_time_) + ".dot");
                if (agent_verbose_2) RCLCPP_INFO(this->get_logger(), "[%d] Action executing: %s", curr_time_, msg.action_id.c_str());
            } else {
                if (agent_verbose_2) RCLCPP_INFO(this->get_logger(),"Unable to add start constraint to timeline for action %s", msg.action_id.c_str());
            }
        }
    } else if (timeline->status == TNode::EXECUTING && timeline->located) {
        // I don't think we do anything now, because we wait until STN is violated
        // TNode* curr = timeline->next_task;
        // auto st = stn.get_feasible_values(curr->stp_);

        // if (std::get<1>(st) + std::get<0>(st) < replanning_threshold_ && curr->name_ != "tail" ) {
        //     RCLCPP_INFO(this->get_logger(), "Bound is tight (%f,%f), Replanning for task %s", -1*std::get<0>(st), std::get<1>(st), curr->name_.c_str());
        //     if (curr->task.st < 0) {
        //         // Bound is too tight, may be unable to achieve next task. First, unschedule task
        //         single_agent_replan(curr);
        //     } else {
        //         // Bound is tight, but can no longer achieve current task. Cancel it and move on
        //         // ma_interfaces::msg::ActionFeedback fail_msg = ma_interfaces::msg::ActionFeedback();
        //         // fail_msg.action_id = timeline->task.id;
        //         // fail_msg.agent_id = id_;
        //         // fail_msg.name = timeline->task.id;

        //         // fail_msg.action_failed = 1;

        //         // action_modification_publisher_->publish(fail_msg);
        //     }
            

        // }
    }
}

void Agent::new_bids_cb(const ma_interfaces::msg::Bid bid) {
    if (bid_map.find(bid.auction_id) != bid_map.end() || winner_map.find(bid.auction_id) != winner_map.end()) {
        if (bid.status < 0) {
            // Agent was unable to schedule task, cancel current set and choose next
            // std::vector<ma_interfaces::msg::Bid> invalid_winners = winner_map[bid.auction_id][0];
            RCLCPP_INFO(this->get_logger(), "Agent %s was unable to schedule task %s", bid.agent_id.c_str(), bid.auction_id.c_str());
            
            if (winner_map.find(bid.auction_id) != winner_map.end()) {
                for (ma_interfaces::msg::Bid wbid : std::get<1>(winner_map[bid.auction_id])[0]) {
                    ma_interfaces::msg::Task task = std::get<0>(winner_map[wbid.auction_id]);
                    task.owner = bid.agent_id;
                    task.st = wbid.st;
                    task.et = wbid.et;
                    if (agent_verbose_1) RCLCPP_INFO(this->get_logger(), "Publishing new winner for auction %s: agent %s (%f,%f)", task.id.c_str(), task.owner.c_str(), bid.st, bid.et);

                    task_auction_publisher_->publish(task);
                }
            }
        } else if (bid.status > 0 && (winner_map.find(bid.auction_id) != winner_map.end())) {
            // Task was scheduled, can now erase and close auction
            // bid_map.erase(bid.auction_id);
            bool all_scheduled = true;
            for (size_t i = 0; i < std::get<1>(winner_map[bid.auction_id])[0].size(); i++){
                ma_interfaces::msg::Bid wbid = std::get<1>(winner_map[bid.auction_id])[0][i];
                if (wbid.status < 0){
                    if (wbid.agent_id == bid.agent_id){
                        if (agent_verbose_1) RCLCPP_INFO(this->get_logger(), "Task <%s> was successfuly scheduled by agent %s, closing auction.", bid.auction_id.c_str(), bid.agent_id.c_str());
                        wbid.status = bid.status;
                    } else {
                        all_scheduled = false;
                    }
                }
            }
            if (all_scheduled) {
                if (agent_verbose_1) RCLCPP_INFO(this->get_logger(), "Task <%s> was successfully scheduled by all agents, closing auction", bid.auction_id.c_str());
                winner_map.erase(bid.auction_id);
            } else {
                std::get<1>(winner_map[bid.auction_id])[0].erase(std::get<1>(winner_map[bid.auction_id])[0].begin());
            }
        } else {
            // Auction is receiving bids
            if (bid_map[bid.auction_id].find(bid.agent_id) == bid_map[bid.auction_id].end()) {
                bid_map[bid.auction_id][bid.agent_id] = std::vector<ma_interfaces::msg::Bid>();
            }
            bid_map[bid.auction_id][bid.agent_id].push_back(bid);

            if (agent_verbose_1) RCLCPP_INFO(this->get_logger(), "Added bid from agent %s to auction %s", bid.agent_id.c_str(), bid.auction_id.c_str());
        }
    }
}

/*
 * Callback function to process newly available slots form auctions
 * Input: Slot that describes start and end times, and start and end locations
 * Output: Slot whose removal minimizes the makespan 
 *
 */
void Agent::new_slots_cb(ma_interfaces::msg::Slot slot) {
    mtx.lock();
    // Behavior: Iterate throught timeline, unscheduling each task.
    // At each point, check makespan, and choose task whose
    // removal gives the minimal makespan
    if (slot.owner_id == "") {
        TNode* curr = timeline->next_task;
        if (!timeline->located || (timeline->status == TNode::COMPLETE && curr->name_ != "tail")) {
            // If current executing action is a travel activity or is complete, go to the next 
            curr = curr->next_task;
        }

        double best_val, best_et, curr_val, curr_et;
        TNode* best_slot = nullptr;
        while (curr->name_ != "tail") {
            RCLCPP_INFO(this->get_logger(), "Looking at task %s", curr->name_.c_str());
            double adj_st = slot.st + compute_dist(slot.x1,slot.y1,curr->task.x,curr->task.y)/slot.speed;
            double adj_et = slot.et;
            if (slot.x2 >= 0 && slot.y2 >= 0) {
                adj_et -= compute_dist(curr->task.x,curr->task.y,slot.x2,slot.y2)/slot.speed;
            }

            if (curr->task.duration >= 0 && adj_et - adj_st >= curr->task.duration*(1+scheduling_range_)) {
                curr_et = -std::get<0>(stn.get_feasible_values("end"));
                std::vector<std::tuple<std::string,constraint>> constraints = unschedule_task(curr);
                curr_val = curr_et + std::get<0>(stn.get_feasible_values("end"));
                RCLCPP_INFO(this->get_logger(), "Adjust st and et: %f, %f, curr_val = %f", adj_st, adj_et, curr_val);
                if (!best_slot || curr_val < best_val) {
                    best_val = curr_val;
                    best_et = curr_et;
                    best_slot = curr;
                }

                stn.add_timepoint(curr->stp_);
                stn.add_timepoint(curr->etp_);

                for (auto c : constraints) {
                    stn.add_constraint(std::get<0>(c), std::get<1>(c));
                }
            }
            curr = curr->next_task;
        }

        if (best_slot) {
            best_slot->task.value = best_val;
            best_slot->task.et = best_et;
            slot_bid_publisher_->publish(best_slot->task);
            best_slot->task.duration = -best_slot->task.duration;
        }
    } else {
        TNode* prev = timeline;
        TNode* curr = timeline->next_task;
        if (slot.owner_id == id_) {
            // We own the task that was sold
            while (curr->name_ != "tail") {
                if (curr->task.duration < 0) {
                    curr->task.duration = -curr->task.duration;
                    if (curr->name_ == slot.task_id) {
                        RCLCPP_INFO(this->get_logger(), "[%d] Task %s was sold", curr_time_, slot.task_id.c_str());

                        // Unschedule old tasks
                        if (!prev->next->located) {
                            unschedule_task(prev->next);
                        }
                        unschedule_task(curr);

                        // Schedule new travel task
                        if (curr->next_task->name_ != "tail") {                
                            std::string stp = prev->name_ + "_" + curr->next_task->name_ + "_travel_st"; 
                            std::string etp = prev->name_ + "_" + curr->next_task->name_ + "_travel_et";
                            stn.add_timepoint(stp);
                            stn.add_timepoint(etp);

                            constraint st_c = std::make_tuple(prev->etp_,stp,0,inf);
                            constraint travel_c = std::make_tuple(stp, etp, compute_dist(prev->task,curr->next_task->task)/speed_,inf);
                            constraint et_c = std::make_tuple(etp, curr->next_task->stp_, 0, inf);
                            bool status = stn.add_constraint(prev->name_ + "_" + curr->next_task->name_ + "_travel_st", st_c);
                            status &= stn.add_constraint(prev->name_ + "_" + curr->next_task->name_ + "_travel_dur", travel_c);
                            status &= stn.add_constraint(prev->name_ + "_" + curr->next_task->name_ + "_travel_et", et_c);
                            
                            TNode* new_travel = new TNode(prev->name_ + "_" + curr->next_task->name_ + "_travel", stp,etp);
                            new_travel->task = build_task_msg(prev->name_ + "_" + curr->next_task->name_ + "_travel", "", 1, 0, compute_dist(prev->task,curr->next_task->task)/speed_,0,0,0,0,0);
                            prev->next = new_travel;
                            prev->next_task = curr->next_task;
                            new_travel->next = curr->next_task;
                            new_travel->next_task = curr->next_task;
                        } else {
                            constraint new_seq = std::make_tuple(prev->etp_,"end", 0, inf);
                            stn.add_constraint(prev->etp_ + "end_seq", new_seq);
                        }
                        prev->next = curr->next;
                        curr->next = nullptr;
                        break;
                    }
                    
                }
                prev = curr;
                curr = curr->next_task;
            }
        }

        while (curr->name_ != "tail") {
            if (curr->task.duration < 0) curr->task.duration = -curr->task.duration;
            curr = curr->next_task;
        }
    }
    
    mtx.unlock();
}


void Agent::slot_bids_cb(ma_interfaces::msg::Task task) {
    if (hosting_auction) {
        RCLCPP_INFO(this->get_logger(), "Added task %s from %s", task.id.c_str(), task.owner.c_str());
        slot_bids.push_back(task);
    }
    
}
/* 
 * Function to host multi agent positive replanning reverse auctions
 */
void Agent::multi_agent_positive_replan(ma_interfaces::msg::Task task) {
    pr_count++;
    RCLCPP_INFO(this->get_logger(), "[%d] Positive replanning called", curr_time_);
    RCLCPP_INFO(this->get_logger(), "\n=============Replan Counter=============\n\t%d\t%d", pr_count, nr_count);
    ma_interfaces::msg::Slot slot = ma_interfaces::msg::Slot();
    slot.agent_id = id_;
    slot.owner_id = "";
    slot.task_id = id_;
    slot.st = curr_time_;
    slot.speed = speed_;
    slot.x1 = task.x;
    slot.y1 = task.y;
    slot.et = std::get<1>(stn.get_feasible_values(timeline->next_task->stp_));

    if (timeline->next->name_ != "tail") {
        slot.x2 = timeline->next_task->task.x;
        slot.y2 = timeline->next_task->task.y;
    } else {
        slot.x2 = -1;
        slot.y2 = -1;
    }

    RCLCPP_INFO(this->get_logger(), "Publishing slot %f, %f", slot.st, slot.et);
    hosting_auction = true;
    slot_auction_publisher_->publish(slot);
    rclcpp::sleep_for(std::chrono::duration_cast<std::chrono::seconds>(std::chrono::duration<double>(auction_time_)));

    ma_interfaces::msg::Task best_task;
    double max_val = -1;;
    std::vector<std::tuple<double,double,TNode*,ma_interfaces::msg::Task>> slots;

    RCLCPP_INFO(this->get_logger(), "Total tasks: %ld", slot_bids.size());
    auto cmp_1 = [](std::tuple<double,TNode*> left, std::tuple<double,TNode*> right){
                        return std::get<0>(left) > std::get<0>(right);
                    };
    auto cmp_2 = [](std::tuple<double,double,TNode*, ma_interfaces::msg::Task> left, std::tuple<double,double,TNode*,ma_interfaces::msg::Task> right){
        return std::get<0>(left) + std::get<1>(left) > std::get<0>(right) + std::get<1>(right);
    };

    for (ma_interfaces::msg::Task bid : slot_bids) {
        if (bid.st >= 0) RCLCPP_INFO(this->get_logger(), "Slot %s has a start time", bid.id.c_str());
        if (bid.value > max_val) max_val = bid.et;
        RCLCPP_INFO(this->get_logger(), "Published makespan for task %s is %f", bid.id.c_str(), bid.et);

        std::vector<std::tuple<double,TNode*>> temp = find_slots(bid);
        if (!temp.empty()) {
            auto temp_slot = *std::min_element(temp.begin(), temp.end(), cmp_1); // sort by makespan
            slots.push_back(std::make_tuple(bid.value,std::get<0>(temp_slot),std::get<1>(temp_slot),bid));
        }
    }

    if (!slot_bids.empty()) {
        if (!slots.empty()) {
            std::sort(slots.begin(),slots.end(), cmp_2);
            size_t i = 0;

            RCLCPP_INFO(this->get_logger(), "[%d] Found %ld slots", curr_time_, slots.size());

            while (i < slots.size()) {
                RCLCPP_INFO(this->get_logger(), "[%d] Accessing slot %ld", curr_time_, i);
                auto self_bid = slots[i];
                RCLCPP_INFO(this->get_logger(), "[%d] Comparing to max makespan", curr_time_);
                if (std::get<1>(self_bid) < max_val) {
                    // Adding the new task to our timeline doesn't decrease the overall efficiency
                    RCLCPP_INFO(this->get_logger(), "geting the task for the slot");
                    ma_interfaces::msg::Task new_task = std::get<3>(self_bid);
                    RCLCPP_INFO(this->get_logger(), "[%d] Scheduling task %s, originally owned by %s", curr_time_, new_task.id.c_str(), new_task.owner.c_str());
                    if (schedule_task(new_task, std::get<2>(self_bid))) {
                        slot.task_id = new_task.id;
                        slot.owner_id = new_task.owner;
                        slot_auction_publisher_->publish(slot);
                        RCLCPP_INFO(this->get_logger(), "Scheduling successful");
                        break;
                    } else {
                        slot.owner_id = "none";
                        slot.task_id = "";
                        slot_auction_publisher_->publish(slot);
                        RCLCPP_INFO(this->get_logger(), "Scheduling failed");
                    }
                } else {
                    RCLCPP_INFO(this->get_logger(), "Didn't schedule, doing so would increase overall makespan");
                }
                i++;
            }

            RCLCPP_INFO(this->get_logger(), "Nothing was scheduled");            
        } else {
            slot.owner_id = "none";
            slot.task_id = "";
            slot_auction_publisher_->publish(slot);
            RCLCPP_INFO(this->get_logger(), "Didn't schedule, no slots found");
        }
    } else {
        slot.owner_id = "none";
        slot.task_id = "";
        slot_auction_publisher_->publish(slot);
        RCLCPP_INFO(this->get_logger(), "Didn't schedule, no bids");
    }
    slot_bids.clear();
    hosting_auction = false;

}

void Agent::action_feedback_cb(const ma_interfaces::msg::ActionFeedback action) {
    rclcpp::sleep_for(1ms);
    mtx.lock();
    if (action.agent_id == id_) {
        if (task_map.find(action.action_id) != task_map.end()) {
            TNode* curr = task_map[action.action_id];
            double est_et = curr->task.duration;
            double action_st = std::get<1>(stn.get_feasible_values(curr->stp_));

            if (action.action_started) {
                RCLCPP_INFO(this->get_logger(), "[%d] Received feedback that action %s started", curr_time_, action.action_id.c_str());
            } else if (action.action_completed) {
                int outside_range = 0;
                bool pos_replan = false;
                if (curr_time_ - action_st < est_et*(1-scheduling_range_)) {
                    // Action finished early, can we reoptimize? Send out auction notice? Reverse auction?
                    RCLCPP_INFO(this->get_logger(), "[%d] Action %s finished earlier than expected", curr_time_, action.action_id.c_str());
                    pos_replan = true;
                    outside_range = -1;
                } else if (curr_time_ - action_st > est_et*(1+scheduling_range_)){
                    RCLCPP_INFO(this->get_logger(), "[%d] Action %s finished later than expected", curr_time_, action.action_id.c_str());
                    outside_range = 1;
                    // Remove task time and replace with current
                } else {
                    RCLCPP_INFO(this->get_logger(), "[%d] Action %s finished within expected range", curr_time_, action.action_id.c_str());
                    outside_range = 0;
                }

                stn.del_constraint("now_seq");
                constraint now_seq = std::make_tuple("now", curr->next->stp_, 0, inf);
                if (!stn.add_constraint("now_seq", now_seq)) {
                    RCLCPP_ERROR(this->get_logger(), "[%d] [Action Feedback] Unable to add now_seq constraint", curr_time_);
                }

                // Remove task time and replace with current
                if (outside_range < 0) {
                    std::string c_name = curr->task.id + "_task_dur";
                    if (!curr->located) c_name = curr->task.id + "_travel_dur";

                    stn.del_constraint(c_name);
                    constraint new_dur = std::make_tuple(curr->stp_, curr->etp_, curr_time_ - action_st, curr_time_ - action_st);
                    
                    if (!stn.add_constraint(c_name, new_dur)) {
                        RCLCPP_ERROR(this->get_logger(), "[%d] Unable to replace task duration with actual (positive)", curr_time_);
                    }

                    
                } else if (outside_range > 0) {
                    std::string c_name = curr->task.id + "_task_dur";
                    if (!curr->located) c_name = curr->task.id + "_travel_dur";
                    constraint old_dur = stn.get_constraint(c_name);
                    stn.del_constraint(c_name);
                    constraint new_dur = std::make_tuple(curr->stp_, curr->etp_, curr_time_- action_st, curr_time_ - action_st);
                    
                    if (!stn.add_constraint(c_name, new_dur)) {
                        RCLCPP_ERROR(this->get_logger(), "[%d] Unable to replace task duration with actual (negative)", curr_time_);
                        TNode* next_task = timeline->next_task;
                        if (!timeline->located) {
                            if (next_task->name_ != "tail") {
                                next_task = timeline->next_task;
                            } else {
                                RCLCPP_ERROR(this->get_logger(), "[%d] No tasks to replan", curr_time_);
                            }
                        }

                        stn.add_constraint(c_name, old_dur);
                        if (next_task->name_ != "tail") {
                            multi_agent_replan(next_task);
                            // single_agent_replan(next_task);
                            stn.del_constraint(c_name);
                            if (!stn.add_constraint(c_name, new_dur)) {
                                RCLCPP_ERROR(this->get_logger(), "[%d] [Action Feedback] Couldn't extend task after creating slack", curr_time_);
                            }
                        } else {
                            RCLCPP_ERROR(this->get_logger(), "[%d] No space to replan", curr_time_);
                        }
                    }
                }

                


                auto end_fv = stn.get_feasible_values(curr->etp_);
                RCLCPP_INFO(this->get_logger(), "[%d] Feasible values after extending task: (%f, %f)\n\tActual time: %f", curr_time_, std::get<0>(end_fv), std::get<1>(end_fv), action.time);
                // Action finished later than expected, all we can do is go to the next task
                constraint c = std::make_tuple("cz", curr->etp_, -std::get<0>(end_fv), -std::get<0>(end_fv));
                bool status = stn.add_constraint(curr->etp_ + "_actual", c);
                if (status) {
                    
                    curr->status = TNode::COMPLETE;
                    stn.gen_dot_file("/home/gkasha/Documents/maae/data/dot_files/agent_stn_" + id_ + "_t_" + std::to_string(curr_time_) + ".dot");
                    gen_timeline_dot("/home/gkasha/Documents/maae/data/dot_files/agent_timeline_" + id_ + "_t_" + std::to_string(curr_time_) + ".dot");
                    if (agent_verbose_2) RCLCPP_INFO(this->get_logger(), "[%d] Action complete: %s", curr_time_, action.action_id.c_str());
                    if (pos_replan || curr->next_task->name_ == "tail") {
                        multi_agent_positive_replan(curr->task);
                    }
                } else {
                    if (agent_verbose_2) RCLCPP_ERROR(this->get_logger(), "[%d] [Action Feedback] Unable to add end constraint to timeline for action %s", curr_time_, 
                            action.action_id.c_str());
                }
            } else if (action.action_failed) {
                if (agent_verbose_2) RCLCPP_INFO(this->get_logger(), "Action failed: %s", action.action_id.c_str());
                // Do something
            }
        }
    }
    mtx.unlock();
}

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);

    rclcpp::executors::MultiThreadedExecutor executor;
    auto agent_node = std::make_shared<Agent>(argv[1], std::stod(argv[2]), std::stod(argv[3]), std::stod(argv[4]), std::stod(argv[5]), std::stod(argv[6]));

    RCLCPP_INFO(agent_node->get_logger(), "Agent %s started", argv[1]);

    executor.add_node(agent_node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}
