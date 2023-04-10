#include "rclcpp/rclcpp.hpp"
#include "ma_interfaces/msg/node.hpp"
#include <chrono>
#include <cstdlib>
#include <vector>

#include "ma_interfaces/srv/add_goal.hpp"

#include "ma_interfaces/msg/goal.hpp"

using namespace std::chrono_literals;

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

    int num_tasks = 3;


    for (int i = 0; i < num_tasks; i++) {
        rclcpp::sleep_for(15s);
        ma_interfaces::msg::Goal g;

        g.id = "task" + std::to_string(i);
        g.num_agents = (i%2)+1;
        g.owner = "";
        g.x = (double)i+1;
        g.y = (double)i+1;

        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Goal at (%f,%f)", g.x, g.y);
        publisher->publish(g);
    }

    rclcpp::shutdown();
    return 0;
}
