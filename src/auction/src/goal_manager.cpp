#include "rclcpp/rclcpp.hpp"

#include "ma_interfaces/srv/register.hpp"
#include "ma_interfaces/srv/add_goal.hpp"
#include "ma_interfaces/srv/get_goal.hpp"

#include "ma_interfaces/msg/goal.hpp"
#include "ma_interfaces/msg/task.hpp"

#include <vector>
#include <queue>


std::queue<ma_interfaces::msg::Goal> goals;
int num_agents;

void register_agent(const std::shared_ptr<ma_interfaces::srv::Register::Request> request,
                        std::shared_ptr<ma_interfaces::srv::Register::Response> response)
{
    num_agents += 1;
    response->status = true;
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Registered new agent: %s", request->id.c_str());
}

void add_goal(const std::shared_ptr<ma_interfaces::srv::AddGoal::Request> request,
                std::shared_ptr<ma_interfaces::srv::AddGoal::Response> response)
{
    goals.push(request->g);
    response->status = true;
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Added new goal: %s", request->g.name.c_str());
}
 
void get_goal(const std::shared_ptr<ma_interfaces::srv::GetGoal::Request> request,
                std::shared_ptr<ma_interfaces::srv::GetGoal::Response> response)
{
    if (goals.size() > 0) {
        response->g = goals.front();
        goals.pop();
        response->num_agents = num_agents;
    } else {
        response->num_agents = -1;
    }
}

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    num_agents = 0;

    std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("goal_server");

    rclcpp::Service<ma_interfaces::srv::Register>::SharedPtr register_service = 
        node->create_service<ma_interfaces::srv::Register>("register_agent", &register_agent);
    rclcpp::Service<ma_interfaces::srv::AddGoal>::SharedPtr add_service =
        node->create_service<ma_interfaces::srv::AddGoal>("add_goal", &add_goal);
    rclcpp::Service<ma_interfaces::srv::GetGoal>::SharedPtr get_service = 
        node->create_service<ma_interfaces::srv::GetGoal>("get_goal", &get_goal);

    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Goal manager started");

    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
