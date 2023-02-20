#include "auction/execution_interface.hpp"


void Executor::action_dispatch_cb(const ma_interfaces::msg::ActionDispatch action) {
    ActionNode* a_node = new ActionNode(action);
    action_map[a_node->to_string()] = a_node;

    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Added action to map: %s", a_node->to_string().c_str());
}

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);

    rclcpp::executors::MultiThreadedExecutor executor;
    auto execution_node = std::make_shared<Executor>();
    auto monitor_node = std::make_shared<Monitor>();

    executor.add_node(execution_node);
    executor.add_node(monitor_node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}
