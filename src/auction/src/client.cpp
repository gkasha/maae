#include "rclcpp/rclcpp.hpp"
#include "ma_interfaces/msg/node.hpp"
#include <chrono>
#include <cstdlib>
#include <vector>

#include "ma_interfaces/srv/add_goal.hpp"

#include "ma_interfaces/msg/goal.hpp"

using namespace std::chrono_literals;

ma_interfaces::msg::Goal build_goal_msg(std::string id, int num_agents, double x, double y) {
    ma_interfaces::msg::Goal g = ma_interfaces::msg::Goal();
    g.id = id;
    g.num_agents = num_agents;
    g.x = x;
    g.y = y;
    return g;
}

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);

    /*
    if (argc != ) {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "usage: signal auction X");
        return 1;
    }
    */

    std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("goal_client");
    rclcpp::Publisher<ma_interfaces::msg::Goal>::SharedPtr publisher = 
        node->create_publisher<ma_interfaces::msg::Goal>("add_goals_topic", 10);

    // int num_tasks = std::stod(argv[1]);

    ma_interfaces::msg::Goal g1 = build_goal_msg("task1", 1, 1.0, 1.0);
    ma_interfaces::msg::Goal g2 = build_goal_msg("task2", 1, 1.0, -1.0);
    ma_interfaces::msg::Goal g3 = build_goal_msg("task3", 1, 2.0, 0.0);
    ma_interfaces::msg::Goal g4 = build_goal_msg("task4", 1, 2.0, 1.0);
    ma_interfaces::msg::Goal g5 = build_goal_msg("task5", 2, 3.0, 1.0);
    ma_interfaces::msg::Goal g6 = build_goal_msg("task6", 1, 6.0, 2.0);

    std::vector<ma_interfaces::msg::Goal> goals{g1,g2,g3,g4,g5,g6};



    for (size_t i = 0; i < goals.size(); i++) {
        rclcpp::sleep_for(3s);
        ma_interfaces::msg::Goal g = goals[i];

        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Goal at (%f,%f)", g.x, g.y);
        publisher->publish(g);
    }

    rclcpp::shutdown();
    return 0;
}
