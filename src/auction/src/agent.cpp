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
    stn.del_constraint("now_constraint");
    constraint c = std::make_tuple("cz", "now", curr_time_, inf);
    if (!stn.add_constraint("now_constraint", c)) {
        RCLCPP_ERROR(this->get_logger(), "[%d] Unable to add now constraint", curr_time_);
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
    winner_map[task.id] = overlaps;
    bid_map.erase(task.id);

    return winner_map[task.id][0];
}

void Agent::host_auction(ma_interfaces::msg::Goal &goal) {
    if (agent_verbose_1) RCLCPP_INFO(this->get_logger(), "Won goal %s @ (%f,%f)", goal.id.c_str(), goal.x, goal.y);

    double task_duration = 10;
    ma_interfaces::msg::Task task = build_task_msg(goal.id,"",goal.num_agents,10,task_duration,-1,goal.deadline, goal.x, goal.y);
    std::map<std::string,std::vector<ma_interfaces::msg::Bid>> new_map;
    bid_map[task.id] = new_map;

    // Send out auction
    if (agent_verbose_1) RCLCPP_INFO(this->get_logger(), "Publishing auction for task %s", task.id.c_str());
    task_auction_publisher_->publish(task);

    // Wait to collect bids
    rclcpp::sleep_for(2s);

    // Choose winner -- default is earliest start time
    std::vector<ma_interfaces::msg::Bid> winning_bids = choose_winners(task);

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
        constraint temp_from = std::make_tuple(temp_tp, curr->next_task->stp_, from_dur, inf);
        bool status = true;
        bool is_now = std::get<0>(now_seq) == curr->next->stp_ || std::get<1>(now_seq) == curr->next->etp_;

        if (is_now) {
            constraint temp_now_seq;
            if (curr->status == TNode::COMPLETE) {
                temp_now_seq = std::make_tuple("now", temp_tp, 0, inf);
            } else {
                temp_now_seq = std::make_tuple("now", curr->etp_, 0, inf);
            }
            status = stn.add_constraint("now_seq", temp_now_seq);
        }


        if (status 
            && stn.add_constraint("temp_to", temp_to)
            && stn.add_constraint("temp_from", temp_from)) {
            
            if (task.st >= 0) {
                constraint temp_st = std::make_tuple("cz", temp_tp, task.st - execution_threshold_, task.st + execution_threshold_);
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

            std::tuple<double,double> temp_vals = stn.get_feasible_values(temp_tp);
            if (status && std::get<0>(temp_vals) + std::get<1>(temp_vals) < replanning_threshold_ && task.st < 0) {
                RCLCPP_INFO(this->get_logger(), "Slot was found, but bound was too tight");
                status = false;
            }
        } else {
            status = false;
        }

        stn.del_timepoint(temp_tp);
        stn.add_timepoint(curr->next->stp_);
        stn.add_timepoint(curr->next->etp_);
        if (is_now) {
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

    if (!slot) slot = std::get<1>(*std::min_element(slots.begin(),slots.end(),cmp));

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

    constraint travel_to_st_c = std::make_tuple(slot->etp_, new_travel_to_stp, 0, inf);
    constraint travel_to_c = std::make_tuple(new_travel_to_stp, new_travel_to_etp, travel_to_dur, inf);
    constraint travel_to_et_c = std::make_tuple(new_travel_to_etp, new_task_stp, 0, inf);
    constraint task_dur_c = std::make_tuple(new_task_stp, new_task_etp, task.duration, inf);

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
        travel_to->task = build_task_msg(slot->name_ + "_" + task.id + "_travel", "", 0, 0, compute_dist(slot->task,task)/speed_, 0,0,0,0);
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
            travel_from->task = build_task_msg(task.id + "_" + new_task->next_task->name_ + "_travel", "", 0, 0, compute_dist(task,new_task->next_task->task)/speed_,0,0,0,0);
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
            double slack = 3;
            double travel_to = compute_dist(slot->task,task)/speed_;
            double travel_from = compute_dist(task,slot->next_task->task)/speed_;
            double st = max((double)curr_time_,-1*std::get<0>(stn.get_feasible_values(slot->etp_))) + travel_to + slack;
            double et = std::get<1>(stn.get_feasible_values(slot->next->stp_)) - travel_from;
            if (et-st >= task.duration) {
                // Build bid message
                ma_interfaces::msg::Bid bid = build_bid_msg(id_,task.id,0,st,et,st-travel_to);
                
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

            // auto stp = stn.get_feasible_values(curr->stp_);
            // auto etp = stn.get_feasible_values(curr->etp_);

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
                if (agent_verbose_2) RCLCPP_INFO(this->get_logger(), "Action executing: %s", msg.action_id.c_str());
            } else {
                if (agent_verbose_2) RCLCPP_INFO(this->get_logger(),"Unable to add start constraint to timeline for action %s", msg.action_id.c_str());
            }
        }
    } else if (timeline->status == TNode::EXECUTING && timeline->located) {
        TNode* curr = timeline->next_task;
        auto st = stn.get_feasible_values(curr->stp_);

        if (std::get<1>(st) + std::get<0>(st) < replanning_threshold_ && curr->name_ != "tail" && curr->task.st < 0) {
            RCLCPP_INFO(this->get_logger(), "Bound is tight (%f,%f), starting auction to replan for task %s", -1*std::get<0>(st), std::get<1>(st), curr->name_.c_str());
            // Bound is too tight, may be unable to achieve next task. First, unschedule task
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
            new_travel->task = build_task_msg(timeline->name_ + "_" + timeline->next_task->name_ + "_travel", "", 0, 0, compute_dist(timeline->task,timeline->next_task->task)/speed_,0,0,0,0);
            timeline->next = new_travel;
            new_travel->next = timeline->next_task;
            new_travel->next_task = timeline->next_task;


            ma_interfaces::msg::Goal goal = ma_interfaces::msg::Goal();
            goal.id = curr->task.id;
            goal.owner = id_;
            goal.num_agents = 1;
            goal.deadline = curr->task.st;
            goal.x = curr->task.x;
            goal.y = curr->task.y;

            goal_auction_publisher_->publish(goal);

        }
    }
}

void Agent::new_bids_cb(const ma_interfaces::msg::Bid bid) {
    if (bid_map.find(bid.auction_id) != bid_map.end()) {
        if (bid.status < 0) {
            // Agent was unable to schedule task, cancel current set and choose next
            // std::vector<ma_interfaces::msg::Bid> invalid_winners = winner_map[bid.auction_id][0];
            RCLCPP_INFO(this->get_logger(), "Agent %s was unable to schedule task %s", bid.agent_id.c_str(), bid.auction_id.c_str());
            
            if (winner_map.find(bid.auction_id) != winner_map.end()) {
                for (ma_interfaces::msg::Bid wbid : winner_map[bid.auction_id][0]) {
                    ma_interfaces::msg::Task task = ma_interfaces::msg::Task();
                    task.owner = bid.agent_id;
                    task.st = bid.st;
                    task.duration = bid.et - bid.st;
                    task.et = bid.et;
                    if (agent_verbose_1) RCLCPP_INFO(this->get_logger(), "Publishing new winner for auction %s: agent %s (%f,%f)", task.id.c_str(), task.owner.c_str(), bid.st, bid.et);

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
                winner_map[bid.auction_id].erase(winner_map[bid.auction_id].begin());
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

void Agent::action_feedback_cb(const ma_interfaces::msg::ActionFeedback action) {
    mtx.lock();
    if (action.agent_id == id_) {
        if (task_map.find(action.action_id) != task_map.end()) {
            TNode* curr = task_map[action.action_id];
            auto end_fv = stn.get_feasible_values(curr->etp_);
            if (action.action_started) {
                RCLCPP_INFO(this->get_logger(), "[%d] Received feedback that action %s started", curr_time_, action.action_id.c_str());
            } else if (action.action_completed) {
                stn.del_constraint("now_seq");
                constraint now_seq = std::make_tuple("now", curr->next->stp_, 0, inf);
                if (!stn.add_constraint("now_seq", now_seq)) {
                    RCLCPP_ERROR(this->get_logger(), "[%d] Unable to add now_seq constraint", curr_time_);
                }

                constraint c = std::make_tuple("cz", curr->etp_, action.time, action.time);
                bool status = stn.add_constraint(curr->etp_ + "_actual", c);
                if (status) {
                    curr->status = TNode::COMPLETE;
                    stn.gen_dot_file("/home/gkasha/Documents/maae/data/dot_files/agent_stn_" + id_ + "_t_" + std::to_string(curr_time_) + ".dot");
                    gen_timeline_dot("/home/gkasha/Documents/maae/data/dot_files/agent_timeline_" + id_ + "_t_" + std::to_string(curr_time_) + ".dot");
                    if (agent_verbose_2) RCLCPP_INFO(this->get_logger(), "Action complete: %s", action.action_id.c_str());
                } else {
                    if (agent_verbose_2) RCLCPP_INFO(this->get_logger(), "Unable to add end constraint to timeline for action %s, expected: (%f, %f),  actual: %f", 
                            action.action_id.c_str(), std::get<0>(end_fv), std::get<1>(end_fv), action.time);
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
    auto agent_node = std::make_shared<Agent>(argv[1], std::stod(argv[2]), std::stod(argv[3]), std::stod(argv[4]), std::stod(argv[5]));

    RCLCPP_INFO(agent_node->get_logger(), "Agent %s started", argv[1]);

    executor.add_node(agent_node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}
