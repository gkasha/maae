#include "auction/execution_interface.hpp"


void Executor::action_dispatch_cb(const ma_interfaces::msg::ActionDispatch action) {
    ActionNode* a_node = new ActionNode(action);
    action_map[a_node->to_string()] = a_node;

    // RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Added action to map: %s", a_node->to_string().c_str());
}

void Executor::action_modification_cb(const ma_interfaces::msg::ActionFeedback action) {
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
    auto execution_node = std::make_shared<Executor>();
    auto monitor_node = std::make_shared<Monitor>();

    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Execution interface started");

    executor.add_node(execution_node);
    executor.add_node(monitor_node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}
