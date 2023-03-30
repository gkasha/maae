#ifndef __EXECUTOR

#define __EXECUTOR

#include "rclcpp/rclcpp.hpp"

#include "ma_interfaces/msg/action_dispatch.hpp"
#include "ma_interfaces/msg/action_feedback.hpp"
#include "std_msgs/msg/int64.hpp"

#include <chrono>
#include <vector>
#include <string>

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

std::map<std::string, ActionNode*> action_map;

class Monitor : public rclcpp::Node
{
    public:
        Monitor() : Node("MonitorNode")
        {
            publisher_ = this->create_publisher<ma_interfaces::msg::ActionFeedback>("action_feedback_topic", 10);

            cbgs_clock_ = this->create_callback_group(
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
        }

    private:
        void clock_cb(const std_msgs::msg::Int64::SharedPtr msg) {
            std::vector<std::string> completed_actions;
            curr_time_ = msg->data;
            for (auto const& x : action_map) {
                ActionNode* action = x.second;
                if (action->get_status() == ActionNode::EXECUTING) {
                    int execution_span = curr_time_ - action->get_start_time();
                    if (execution_span  >= action->get_duration()) {
                        // Action has completed execution, continue
                        action->set_status(ActionNode::COMPLETE);
                        publisher_->publish(action->to_feedback_msg(curr_time_));

                        RCLCPP_INFO(this->get_logger(), "Action completed: %s", action->to_string().c_str());
                        completed_actions.push_back(action->to_string());
                    }
                } else if (action->get_status() == ActionNode::WAITING) {
                    action->set_start_time(curr_time_);
                    action->set_status(ActionNode::EXECUTING);

                    publisher_->publish(action->to_feedback_msg(curr_time_));
                    RCLCPP_INFO(this->get_logger(), "Action started: %s", action->to_string().c_str());
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
        int curr_time_;
        rclcpp::Publisher<ma_interfaces::msg::ActionFeedback>::SharedPtr publisher_;
        rclcpp::CallbackGroup::SharedPtr cbgs_clock_;
        rclcpp::Subscription<std_msgs::msg::Int64>::SharedPtr clock_;
};

class Executor : public rclcpp::Node
{
    public:
        Executor() : Node("executor")
        {
            cbgs_action_dispatch_ = this->create_callback_group(
                    rclcpp::CallbackGroupType::MutuallyExclusive);
            cbgs_action_modification_ = this->create_callback_group(
                    rclcpp::CallbackGroupType::MutuallyExclusive);

            auto action_dispatch_opt = rclcpp::SubscriptionOptions();
            action_dispatch_opt.callback_group = cbgs_action_dispatch_;
            auto action_modification_opt = rclcpp::SubscriptionOptions();
            action_modification_opt.callback_group = cbgs_action_modification_;

            action_dispatch_ = this->create_subscription<ma_interfaces::msg::ActionDispatch>(
                    "action_dispatch_topic",
                    rclcpp::QoS(10),
                    std::bind(
                        &Executor::action_dispatch_cb,
                        this,
                        std::placeholders::_1),
                    action_dispatch_opt);
            action_modification_ = this->create_subscription<ma_interfaces::msg::ActionFeedback>(
                    "action_modification_topic",
                    rclcpp::QoS(10),
                    std::bind(
                        &Executor::action_modification_cb,
                        this,
                        std::placeholders::_1),
                    action_modification_opt);

        }

    private:
        rclcpp::Subscription<ma_interfaces::msg::ActionDispatch>::SharedPtr action_dispatch_;
        rclcpp::Subscription<ma_interfaces::msg::ActionFeedback>::SharedPtr action_modification_;

        rclcpp::CallbackGroup::SharedPtr cbgs_action_dispatch_;
        rclcpp::CallbackGroup::SharedPtr cbgs_action_modification_;
        
        void action_dispatch_cb(const ma_interfaces::msg::ActionDispatch action);
        void action_modification_cb(const ma_interfaces::msg::ActionFeedback action);
};

#endif
