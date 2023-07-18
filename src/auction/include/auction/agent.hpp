#ifndef __AGENT

#define __AGENT

#include "rclcpp/rclcpp.hpp"
#include "auction/stn.hpp"

#include "ma_interfaces/msg/action_dispatch.hpp"
#include "ma_interfaces/msg/action_feedback.hpp"
#include "ma_interfaces/msg/goal.hpp"
#include "ma_interfaces/msg/task.hpp"
#include "ma_interfaces/msg/bid.hpp"
#include "ma_interfaces/msg/slot.hpp"
#include "std_msgs/msg/int64.hpp"

#include <algorithm>
#include <chrono>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std::chrono_literals;

class TNode
{

    public:
        enum TNodeStatus {
            WAITING = 0,
            EXECUTING = 1,
            COMPLETE = 2
        };
        TNode(std::string name, std::string tp1, std::string tp2) {
            name_ = name;
            stp_ = tp1;
            etp_ = tp2;
            next = nullptr;
            status = WAITING;
            located = false;
        };
        bool located;
        TNodeStatus status;
        ma_interfaces::msg::Task task;
        std::string stp_;
        std::string etp_;
        std::string name_;
        TNode* next;
        TNode* next_task;
        TNode* prev;
};

class Agent : public rclcpp::Node
{
    public:
        Agent(std::string id, double deadline, double scheduling_range, double coordination_range, double auction_time, double speed) : Node("agent_"+id)
        {
            std::string topic = "agent_topic_" + id;
            id_ = id;
            deadline_ = deadline;
            scheduling_range_ = scheduling_range; // double representing how much % we can be delayed
            coordination_range_ = coordination_range;
            auction_time_ = auction_time;
            speed_ = speed;

            goal_auction_publisher_ = this->create_publisher<ma_interfaces::msg::Goal>("new_goals_topic", 10);
            goal_bid_publisher_ = this->create_publisher<ma_interfaces::msg::Bid>("goal_bids_topic", 10);
            task_auction_publisher_ = this->create_publisher<ma_interfaces::msg::Task>("new_tasks_topic", 10);
            task_bid_publisher_ = this->create_publisher<ma_interfaces::msg::Bid>("task_bids_topic", 10);
            slot_auction_publisher_ = this->create_publisher<ma_interfaces::msg::Slot>("new_slots_topic", 10);
            slot_bid_publisher_ = this->create_publisher<ma_interfaces::msg::Task>("slot_bids_topic", 10);
            action_dispatch_publisher_ = this->create_publisher<ma_interfaces::msg::ActionDispatch>("action_dispatch_topic", 10);
            action_modification_publisher_ = this->create_publisher<ma_interfaces::msg::ActionFeedback>("action_feedback_topic", 10);

            cbgs_new_goals_ = this->create_callback_group(
                    rclcpp::CallbackGroupType::MutuallyExclusive);
            cbgs_new_tasks_ = this->create_callback_group(
                    rclcpp::CallbackGroupType::MutuallyExclusive);
            cbgs_new_bids_ = this->create_callback_group(
                    rclcpp::CallbackGroupType::MutuallyExclusive);
            cbgs_new_slots_ = this->create_callback_group(
                    rclcpp::CallbackGroupType::MutuallyExclusive);
            cbgs_slot_bids_ = this->create_callback_group(
                    rclcpp::CallbackGroupType::MutuallyExclusive);
            cbgs_action_feedback_ = this->create_callback_group(
                    rclcpp::CallbackGroupType::MutuallyExclusive);
            cbgs_clock_ = this->create_callback_group(
                rclcpp::CallbackGroupType::MutuallyExclusive);

            auto new_goals_opt = rclcpp::SubscriptionOptions();
            new_goals_opt.callback_group = cbgs_new_goals_;
            auto new_tasks_opt = rclcpp::SubscriptionOptions();
            new_tasks_opt.callback_group = cbgs_new_tasks_;
            auto new_bids_opt = rclcpp::SubscriptionOptions();
            new_bids_opt.callback_group = cbgs_new_bids_;
            auto new_slots_opt = rclcpp::SubscriptionOptions();
            new_slots_opt.callback_group = cbgs_new_slots_;
            auto slot_bids_opt = rclcpp::SubscriptionOptions();
            slot_bids_opt.callback_group = cbgs_slot_bids_;
            auto action_feedback_opt = rclcpp::SubscriptionOptions();
            action_feedback_opt.callback_group = cbgs_action_feedback_;
            auto clock_opt = rclcpp::SubscriptionOptions();
            clock_opt.callback_group = cbgs_clock_;

            new_goals_ = this->create_subscription<ma_interfaces::msg::Goal>(
                    "new_goals_topic",
                    rclcpp::QoS(10),
                    std::bind(
                        &Agent::new_goals_cb,
                        this,
                        std::placeholders::_1),
                    new_goals_opt);
            new_tasks_ = this->create_subscription<ma_interfaces::msg::Task>(
                    "new_tasks_topic",
                    rclcpp::QoS(10),
                    std::bind(
                        &Agent::new_tasks_cb,
                        this,
                        std::placeholders::_1),
                    new_tasks_opt);
            new_bids_ = this->create_subscription<ma_interfaces::msg::Bid>(
                    "task_bids_topic",
                    rclcpp::QoS(10),
                    std::bind(
                        &Agent::new_bids_cb,
                        this,
                        std::placeholders::_1),
                    new_bids_opt);
            new_slots_ = this->create_subscription<ma_interfaces::msg::Slot>(
                    "new_slots_topic",
                    rclcpp::QoS(10),
                    std::bind(
                        &Agent::new_slots_cb,
                        this,
                        std::placeholders::_1),
                    new_slots_opt);
            slot_bids_ = this->create_subscription<ma_interfaces::msg::Task>(
                    "slot_bids_topic",
                    rclcpp::QoS(10),
                    std::bind(
                        &Agent::slot_bids_cb,
                        this,
                        std::placeholders::_1),
                    slot_bids_opt);
            action_feedback_ = this->create_subscription<ma_interfaces::msg::ActionFeedback>(
                    "action_feedback_topic",
                    rclcpp::QoS(10),
                    std::bind(
                        &Agent::action_feedback_cb,
                        this,
                        std::placeholders::_1),
                    action_feedback_opt);
            clock_ = this->create_subscription<std_msgs::msg::Int64>(
                "clock_topic",
                rclcpp::QoS(10),
                std::bind(
                    &Agent::clock_cb,
                    this,
                    std::placeholders::_1),
                    clock_opt);
            

            // STN and Timeline info

            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Building STN");
            
            stn = STN();
            stn.init();
            stn.add_timepoint("start");
            stn.add_timepoint("now");
            stn.add_timepoint("end");
            constraint now_c = std::make_tuple("cz", "now", 0, inf);
            constraint now_seq_c = std::make_tuple("now","start",0,inf);
            constraint start_c = std::make_tuple("cz", "start", 0, inf);
            constraint end_c = std::make_tuple("cz", "end", 0, deadline_);
            constraint seq_c = std::make_tuple("start", "end", 0, inf);

            stn.add_constraint("cz_start_seq", start_c);
            stn.add_constraint("deadline", end_c);
            stn.add_constraint("start_end_seq", seq_c);
            stn.add_constraint("now_seq", now_seq_c);
            stn.add_constraint("now_constraint", now_c);
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Done, building timeline");

            timeline = new TNode("head", "start", "start");
            timeline->task = build_task_msg("head_task","",0,0,0,0,0,0,0,0);
            timeline->located = true;
            timeline->status = TNode::COMPLETE;
            timeline_head = timeline;
            TNode* tail = new TNode("tail", "end", "end");
            tail->task = build_task_msg("tail","",0,0,0,0,0,0,0,0);
            tail->located = false;
            tail->prev = timeline;
            tail->next = nullptr;
            tail->next_task = nullptr;
    
            timeline->next = tail;
            timeline->next_task = tail;
            timeline->prev = nullptr;
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Done");
        }
        
    private:
        ma_interfaces::msg::Bid build_bid_msg(
            std::string agent_id, 
            std::string auction_id,
            int status,
            double st,
            double et,
            double value
        );
        ma_interfaces::msg::Task build_task_msg(
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
        );

        std::mutex mtx;

        rclcpp::Publisher<ma_interfaces::msg::Goal>::SharedPtr goal_auction_publisher_;
        rclcpp::Publisher<ma_interfaces::msg::Bid>::SharedPtr goal_bid_publisher_;
        rclcpp::Publisher<ma_interfaces::msg::Task>::SharedPtr task_auction_publisher_;
        rclcpp::Publisher<ma_interfaces::msg::Bid>::SharedPtr task_bid_publisher_;
        rclcpp::Publisher<ma_interfaces::msg::Slot>::SharedPtr slot_auction_publisher_;
        rclcpp::Publisher<ma_interfaces::msg::Task>::SharedPtr slot_bid_publisher_;
        rclcpp::Publisher<ma_interfaces::msg::ActionDispatch>::SharedPtr action_dispatch_publisher_;
        rclcpp::Publisher<ma_interfaces::msg::ActionFeedback>::SharedPtr action_modification_publisher_;

        rclcpp::CallbackGroup::SharedPtr cbgs_new_goals_;
        rclcpp::CallbackGroup::SharedPtr cbgs_new_tasks_;
        rclcpp::CallbackGroup::SharedPtr cbgs_new_bids_;
        rclcpp::CallbackGroup::SharedPtr cbgs_new_slots_;
        rclcpp::CallbackGroup::SharedPtr cbgs_slot_bids_;
        rclcpp::CallbackGroup::SharedPtr cbgs_action_feedback_;
        rclcpp::CallbackGroup::SharedPtr cbgs_clock_;

        rclcpp::Subscription<ma_interfaces::msg::Goal>::SharedPtr new_goals_;
        rclcpp::Subscription<ma_interfaces::msg::Task>::SharedPtr new_tasks_;
        rclcpp::Subscription<ma_interfaces::msg::Bid>::SharedPtr new_bids_;
        rclcpp::Subscription<ma_interfaces::msg::Slot>::SharedPtr new_slots_;
        rclcpp::Subscription<ma_interfaces::msg::Task>::SharedPtr slot_bids_;
        rclcpp::Subscription<ma_interfaces::msg::ActionFeedback>::SharedPtr action_feedback_;

        rclcpp::Subscription<std_msgs::msg::Int64>::SharedPtr clock_;

        std::string id_;
        std::vector<ma_interfaces::msg::Task> slot_bids;
        std::map<std::string,TNode*> task_map;
        std::map<std::string,std::map<std::string,std::vector<ma_interfaces::msg::Bid>>> bid_map;
        std::map<std::string,std::tuple<ma_interfaces::msg::Task,std::vector<std::vector<ma_interfaces::msg::Bid>>>> winner_map;

        bool hosting_auction;
        double scheduling_range_;
        double coordination_range_;
        double auction_time_;
        double start_time_;
        int curr_time_;
        double deadline_;
        double speed_;
        int pr_count;
        int nr_count;
        STN stn;
        TNode* timeline;
        TNode* timeline_head;
        std::vector<TNode*> plans;

        void print_timeline();
        void gen_timeline_dot(std::string filename);
        double compute_dist(ma_interfaces::msg::Task &t1, ma_interfaces::msg::Task &t2);
        double compute_dist(double x1, double y1, double x2, double y2);

        std::tuple<double,TNode*> find_slot(TNode* root, ma_interfaces::msg::Task &task);
        std::vector<std::tuple<double,TNode*>> find_slots(ma_interfaces::msg::Task &task);
        std::vector<std::tuple<std::string,constraint>> unschedule_task(TNode* t);
        bool schedule_task(ma_interfaces::msg::Task &task, TNode* slot);
        
        std::vector<ma_interfaces::msg::Bid> choose_winners(ma_interfaces::msg::Task task);
        bool host_auction(ma_interfaces::msg::Goal &goal);
        void check_dispatch();
        void single_agent_replan(TNode* curr);
        void multi_agent_replan(TNode* curr);
        void multi_agent_positive_replan(ma_interfaces::msg::Task task);
        
        void clock_cb(const std_msgs::msg::Int64::SharedPtr msg);
        void new_goals_cb(ma_interfaces::msg::Goal goal);
        void new_tasks_cb(const ma_interfaces::msg::Task task);
        void new_bids_cb(const ma_interfaces::msg::Bid bid);
        void new_slots_cb(ma_interfaces::msg::Slot slot);
        void slot_bids_cb(ma_interfaces::msg::Task task);
        void action_feedback_cb(const ma_interfaces::msg::ActionFeedback action);


};

#endif
