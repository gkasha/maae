#include "rclcpp/rclcpp.hpp"
#include "ma_interfaces/srv/auction_srv.hpp"
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
    rclcpp::Client<ma_interfaces::srv::AddGoal>::SharedPtr client = 
        node->create_client<ma_interfaces::srv::AddGoal>("add_goal");

    int num_tasks = 10;

    for (int i = 0; i < num_tasks; i++) {


        ma_interfaces::msg::Goal g;

        g.name = "task" + std::to_string(i);
        auto req = std::make_shared<ma_interfaces::srv::AddGoal::Request>();
        req->g = g;

        while (!client->wait_for_service(1s)){
            if (!rclcpp::ok()) {
                RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting");
                return 0;
            }
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting again...");
        }

        auto res = client->async_send_request(req);

        if (rclcpp::spin_until_future_complete(node, res) ==
                rclcpp::FutureReturnCode::SUCCESS)
        {
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Added goal");
        } else {
            RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service");
        }
    }

    rclcpp::shutdown();
    return 0;
}
