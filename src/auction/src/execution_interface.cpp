#include "auction/execution_interface.hpp"


void Monitor::action_dispatch_cb(const ma_interfaces::msg::ActionDispatch action) {
    ActionNode* a_node = new ActionNode(action);
    action_map[a_node->to_string()] = a_node;

    if (action.num_agents <= 1) {
        a_node->set_start_time(curr_time_);
        a_node->set_status(ActionNode::EXECUTING);
        
        publisher_->publish(a_node->to_feedback_msg(curr_time_));
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "[%d] Action started: %s, duration=[%f]", curr_time_, a_node->to_string().c_str(), action.duration);
    } else {
        if (joint_map.find(action.action_id) != joint_map.end()) {
            joint_map[action.action_id].push_back(a_node);
            int curr_agents = joint_map[action.action_id].size();
            if (curr_agents == action.num_agents) {
                for (ActionNode* node : joint_map[action.action_id]) {
                    node->set_start_time(curr_time_);
                    node->set_status(ActionNode::EXECUTING);

                    publisher_->publish(node->to_feedback_msg(curr_time_));
                    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "[%d] Action started: %s, duration=[%f]", curr_time_, node->to_string().c_str(), node->get_duration());
                }
                joint_map.erase(action.action_id);
            }
        } else {
            joint_map[action.action_id] = std::vector<ActionNode*>{a_node};
        }
    }
}

void Monitor::action_modification_cb(const ma_interfaces::msg::ActionFeedback action) {
    std::string key = action.action_id + "_" + action.agent_id + "_" + action.name;

    if (action_map.find(key) != action_map.end()) {
        if (action.action_failed) {
            action_map[key]->set_status(ActionNode::FAILED);
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"),"Failing action %s", action_map[key]->to_string().c_str());
        } else {
            action_map[key]->set_duration(action_map[key]->get_duration() + action.time);
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"),"Delaying action %s by %f", action_map[key]->to_string().c_str(), action.time);
        }
    }   
}

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);

    rclcpp::executors::MultiThreadedExecutor executor;
    auto monitor_node = std::make_shared<Monitor>();

    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Execution interface started");

    executor.add_node(monitor_node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}
