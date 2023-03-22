#ifndef __EXECUTOR

#define __EXECUTOR

#include "rclcpp/rclcpp.hpp"

#include "ma_interfaces/msg/action_dispatch.hpp"
#include "ma_interfaces/msg/action_feedback.hpp"

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
            st_ = std::chrono::steady_clock::now();
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

        void set_start_time(std::chrono::steady_clock::time_point tp) {
            st_ = tp;
        }

        std::chrono::steady_clock::time_point get_start_time(){
            return st_;
        }

        void set_duration(float x) {
            duration_ = x;
        }

        float get_duration(){
            return duration_;
        }

        ma_interfaces::msg::ActionFeedback to_feedback_msg() {
            auto msg = ma_interfaces::msg::ActionFeedback();
            msg.action_id = action_id_;
            msg.agent_id = agent_id_;
            msg.name = name_;
            msg.time = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::time_point_cast<std::chrono::seconds>(std::chrono::steady_clock::now()).time_since_epoch()).count();

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
        float duration_;
        std::chrono::steady_clock::time_point st_;
        ActionStatus status_;
};

std::map<std::string, ActionNode*> action_map;

class Monitor : public rclcpp::Node
{
    public:
        Monitor() : Node("MonitorNode")
        {
            publisher_ = this->create_publisher<ma_interfaces::msg::ActionFeedback>("action_feedback_topic", 10);
            system_start_time_ = std::chrono::steady_clock::now();

            auto timer_callback = 
                [this]() -> void {
                    std::vector<std::string> completed_actions;
                    for (auto const& x : action_map) {
                        ActionNode* action = x.second;
                        if (action->get_status() == ActionNode::EXECUTING) {

                            std::chrono::duration<float> execution_span = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::steady_clock::now() - action->get_start_time());
                            if (execution_span.count() >= action->get_duration()) {
                                // Action has completed execution, continue
                                action->set_status(ActionNode::COMPLETE);
                                publisher_->publish(action->to_feedback_msg());

                                RCLCPP_INFO(this->get_logger(), "Action completed: %s", action->to_string().c_str());
                                completed_actions.push_back(action->to_string());
                            }
                        } else if (action->get_status() == ActionNode::WAITING) {
                            action->set_start_time(std::chrono::steady_clock::now());
                            action->set_status(ActionNode::EXECUTING);

                            publisher_->publish(action->to_feedback_msg());
                            RCLCPP_INFO(this->get_logger(), "Action started: %s", action->to_string().c_str());
                        } else if (action->get_status() == ActionNode::FAILED) {
                            publisher_->publish(action->to_feedback_msg());
                            RCLCPP_INFO(this->get_logger(), "Action failed: %s", action->to_string().c_str());
                            completed_actions.push_back(action->to_string());
                        }
                    }
                    for (auto s : completed_actions) {
                        action_map.erase(s);
                    }
                };
            timer_ = this->create_wall_timer(500ms, timer_callback);
        }

    private:
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Publisher<ma_interfaces::msg::ActionFeedback>::SharedPtr publisher_;
        std::chrono::steady_clock::time_point system_start_time_;
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
