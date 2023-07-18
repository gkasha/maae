#include "rclcpp/rclcpp.hpp"
#include "ma_interfaces/msg/node.hpp"
#include <chrono>
#include <cstdlib>
#include <vector>
#include <random>

#include "ma_interfaces/srv/add_goal.hpp"
#include "ma_interfaces/msg/task.hpp"
#include "ma_interfaces/msg/goal.hpp"

using namespace std::chrono_literals;

ma_interfaces::msg::Goal build_goal_msg(std::string id, int num_agents, double duration, double range, double x, double y) {
    ma_interfaces::msg::Goal g = ma_interfaces::msg::Goal();
    g.id = id;
    g.num_agents = num_agents;
    g.duration = duration;
    g.execution_range = range;
    g.x = x;
    g.y = y;
    return g;
}

ma_interfaces::msg::Task build_task_msg(
    std::string id,
    std::string owner,
    int num_agents,
    double value,
    double duration,
    double execution_range,
    double st,
    double et,
    double x,
    double y
) {
    ma_interfaces::msg::Task task = ma_interfaces::msg::Task();
    task.id = id;
    task.owner = owner;
    task.num_agents = num_agents;
    task.value = value;
    task.duration = duration;
    task.execution_range = execution_range;
    task.st = st;
    task.et = et;
    task.x = x;
    task.y = y;
    return task;
}

std::vector<double> generateRandomPointOnCircle(double x, double y, double radius) {
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_real_distribution<double> distribution(0.0,1.0);

    double angle = 2.0*M_PI*distribution(generator);

    double randomX = x + radius*cos(angle);
    double randomY = y + radius*sin(angle);

    return {randomX, randomY};
}

std::vector<double> generateRandomPointInCircle(double x, double y, double radius) {
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_real_distribution<double> distribution(-radius,radius);

    double randomX, randomY;
    do {
        randomX = distribution(generator);
        randomY = distribution(generator);
    } while (randomX*randomX + randomY*randomY > radius*radius);

    return {x+randomX, y+randomY};
}

std::vector<double> generateRandomPointInSquare(double x, double y, double length) {
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_real_distribution<double> distribution(-length/2, length/2);

    return {x+distribution(generator),y+distribution(generator)};
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
    rclcpp::Publisher<ma_interfaces::msg::Goal>::SharedPtr goal_publisher = 
        node->create_publisher<ma_interfaces::msg::Goal>("add_goals_topic", 10);
    rclcpp::Publisher<ma_interfaces::msg::Task>::SharedPtr task_publisher = 
        node->create_publisher<ma_interfaces::msg::Task>("new_tasks_topic", 10);

    std::random_device rd;
    std::mt19937 gen(rd());

    size_t num_goals = 25;

    // ma_interfaces::msg::Task t1 = build_task_msg("task1", "0", 1, 10, 20, 10, -1, -1,5,5);
    // ma_interfaces::msg::Task t2 = build_task_msg("task2", "1", 1, 10, 30, 3, -1, -1,0,5);
    // ma_interfaces::msg::Task t3 = build_task_msg("task3", "1", 1, 10, 5, 2, -1, -1, 6,6);

    // std::vector<ma_interfaces::msg::Task> tasks{t1,t2,t3};
    // rclcpp::sleep_for(3s);
    
    // for (auto t : tasks) {
    //     rclcpp::sleep_for(1s);
    //     task_publisher->publish(t);
    // }

    std::vector<std::vector<double>> grid = {{10,10}, {10,50}, {10,90}, {50,10}, {50,50}, {50,90}, {90,10}, {90,50}, {90,90}};
    std::uniform_int_distribution<int> distr(0, grid.size()-1);


    for (size_t i = 0; i < num_goals; i++) {
        rclcpp::sleep_for(2s);
        int num_agents = 1;
        if (i%5 == 0) num_agents = 2;

        // int randomIdx = distr(gen);
        std::vector<double> new_point;// = generateRandomPointInSquare(grid[randomIdx][0],grid[randomIdx][1],20);
        if (distr(gen) > 0.75) {
            new_point = generateRandomPointOnCircle(50,50,50);
        } else {
            new_point = generateRandomPointInCircle(50,50,12.5);
        }

        ma_interfaces::msg::Goal g = build_goal_msg("task" + std::to_string(i), num_agents, 100, 50, new_point[0], new_point[1]);

        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Goal at (%f,%f)", g.x, g.y);
        goal_publisher->publish(g);
    }

    rclcpp::shutdown();
    return 0;
}
