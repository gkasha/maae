#ifndef __EXECUTOR

#define __EXECUTOR

#include "rclcpp/rclcpp.hpp"

#include "ma_interfaces/msg/action_dispatch.hpp"
#include "ma_interfaces/msg/action_feedback.hpp"
#include "std_msgs/msg/int64.hpp"

#include <chrono>
#include <vector>
#include <string>
#include <random>

using namespace std::chrono_literals;


class ActionNode
{

    public:
        enum ActionStatus {
            WAITING = 0,
            EXECUTING = 1,
            COMPLETE = 2,
            FAILED = 3
        };

        ActionNode(ma_interfaces::msg::ActionDispatch action)
        {
            action_id_ = action.action_id;
            agent_id_ = action.agent_id;
            name_ = action.name;
            duration_ = action.duration;
            st_ = action.start_time;
            status_ = WAITING;
        }

        std::string to_string() {
            return action_id_ + "_" + agent_id_ + "_" + name_;
        }

        std::string get_action_id() {
            return action_id_;
        }

        std::string get_agent_id() {
            return agent_id_;
        }

        void set_status(ActionStatus status) {
            status_ = status;
        }

        ActionStatus get_status() {
            return status_;
        }

        void set_start_time(int tp) {
            st_ = tp;
        }

        int get_start_time(){
            return st_;
        }

        void set_duration(double x) {
            duration_ = x;
        }

        float get_duration(){
            return duration_;
        }

        ma_interfaces::msg::ActionFeedback to_feedback_msg(int curr_time) {
            auto msg = ma_interfaces::msg::ActionFeedback();
            msg.action_id = action_id_;
            msg.agent_id = agent_id_;
            msg.name = name_;
            msg.time = curr_time;
            if (status_ == ActionStatus::EXECUTING) {
                msg.action_started = 1;
            } else if (status_ == ActionStatus::COMPLETE) {
                msg.action_completed = 1;
            } else {
                msg.action_failed = 1;
            }
            
            return msg;
        }

    private:
        std::string action_id_;
        std::string agent_id_;
        std::string name_;
        int duration_;
        int st_;
        ActionStatus status_;
};

class Monitor : public rclcpp::Node
{
    public:
        Monitor() : Node("MonitorNode")
        {
            publisher_ = this->create_publisher<ma_interfaces::msg::ActionFeedback>("action_feedback_topic", 10);

            cbgs_clock_ = this->create_callback_group(
                rclcpp::CallbackGroupType::MutuallyExclusive);
            cbgs_action_dispatch_ = this->create_callback_group(
                    rclcpp::CallbackGroupType::MutuallyExclusive);
            cbgs_action_modification_ = this->create_callback_group(
                    rclcpp::CallbackGroupType::MutuallyExclusive);


            auto clock_opt = rclcpp::SubscriptionOptions();
            clock_opt.callback_group = cbgs_clock_;
            clock_ = this->create_subscription<std_msgs::msg::Int64>(
                "clock_topic",
                rclcpp::QoS(10),
                std::bind(
                    &Monitor::clock_cb,
                    this,
                    std::placeholders::_1),
                    clock_opt);
            
            auto action_dispatch_opt = rclcpp::SubscriptionOptions();
            action_dispatch_opt.callback_group = cbgs_action_dispatch_;
            auto action_modification_opt = rclcpp::SubscriptionOptions();
            action_modification_opt.callback_group = cbgs_action_modification_;

            action_dispatch_ = this->create_subscription<ma_interfaces::msg::ActionDispatch>(
                    "action_dispatch_topic",
                    rclcpp::QoS(10),
                    std::bind(
                        &Monitor::action_dispatch_cb,
                        this,
                        std::placeholders::_1),
                    action_dispatch_opt);
            action_modification_ = this->create_subscription<ma_interfaces::msg::ActionFeedback>(
                    "action_modification_topic",
                    rclcpp::QoS(10),
                    std::bind(
                        &Monitor::action_modification_cb,
                        this,
                        std::placeholders::_1),
                    action_modification_opt);
        }

    private:
        void clock_cb(const std_msgs::msg::Int64::SharedPtr msg) {
            mtx.lock();
            std::vector<std::string> completed_actions;
            curr_time_ = msg->data;
            mtx.unlock();
            for (auto const& x : action_map) {
                ActionNode* action = x.second;
                if (action->get_status() == ActionNode::EXECUTING) {
                    int execution_span = curr_time_ - action->get_start_time();
                    if (execution_span  >= action->get_duration()) {
                        // Action has completed execution, continue
                        action->set_status(ActionNode::COMPLETE);
                        publisher_->publish(action->to_feedback_msg(curr_time_));

                        RCLCPP_INFO(this->get_logger(), "\n\t[%d] Action completed: %s", curr_time_, action->to_string().c_str());
                        bool travel = action->get_action_id().find("travel") != std::string::npos;

                        if (action_counter.find(action->get_agent_id()) != action_counter.end()) {
                            action_counter[action->get_agent_id()][1] = curr_time_;
                            if (travel) {
                                action_counter[action->get_agent_id()][2] += execution_span;
                            } else {
                                action_counter[action->get_agent_id()][0]++;
                            }
                        } else {
                            std::vector<int> tmp{0,0,0};
                            if (travel) {
                                tmp[2] = execution_span;
                            } else {
                                tmp[0] = 1;
                            }
                            action_counter[action->get_agent_id()] = tmp;
                        }
                        print_action_counter();
                        completed_actions.push_back(action->to_string());
                    }
                } else if (action->get_status() == ActionNode::WAITING && action->get_start_time() <= curr_time_) {
                    // action->set_start_time(curr_time_);
                    // action->set_status(ActionNode::EXECUTING);

                    // publisher_->publish(action->to_feedback_msg(curr_time_));
                    // RCLCPP_INFO(this->get_logger(), "Action started: %s", action->to_string().c_str());
                } else if (action->get_status() == ActionNode::FAILED) {
                    publisher_->publish(action->to_feedback_msg(curr_time_));
                    RCLCPP_INFO(this->get_logger(), "Action failed: %s", action->to_string().c_str());
                    completed_actions.push_back(action->to_string());
                }
            }
            for (auto s : completed_actions) {
                action_map.erase(s);
            }
        }

        std::mutex mtx;

        std::map<std::string, std::vector<int>> action_counter;
        std::map<std::string, ActionNode*> action_map;
        std::map<std::string, std::vector<ActionNode*>> joint_map;

        rclcpp::Publisher<ma_interfaces::msg::ActionFeedback>::SharedPtr publisher_;
        rclcpp::CallbackGroup::SharedPtr cbgs_clock_;
        rclcpp::Subscription<std_msgs::msg::Int64>::SharedPtr clock_;
        int curr_time_;

        rclcpp::Subscription<ma_interfaces::msg::ActionDispatch>::SharedPtr action_dispatch_;
        rclcpp::Subscription<ma_interfaces::msg::ActionFeedback>::SharedPtr action_modification_;

        rclcpp::CallbackGroup::SharedPtr cbgs_action_dispatch_;
        rclcpp::CallbackGroup::SharedPtr cbgs_action_modification_;

        void print_action_counter();
        
        void action_dispatch_cb(const ma_interfaces::msg::ActionDispatch action);
        void action_modification_cb(const ma_interfaces::msg::ActionFeedback action);
};


#endif
