#include "rclcpp/rclcpp.hpp"

#include "ma_interfaces/msg/goal.hpp"
#include "ma_interfaces/msg/task.hpp"
#include "ma_interfaces/msg/bid.hpp"

#include <chrono>
#include <map>
#include <vector>
#include <queue>

using namespace std::chrono_literals;

std::map<std::string, std::vector<ma_interfaces::msg::Bid>> goal_map;

class ListenerNode : public rclcpp::Node
{
    public:
        ListenerNode()
        : Node("ListenerNode")
        {
            publisher_ = this->create_publisher<ma_interfaces::msg::Goal>("new_goals_topic", 10);
            cbgs_goal_bids_ = this->create_callback_group(
                    rclcpp::CallbackGroupType::MutuallyExclusive); // Necessary to ensure safe access of map
            cbgs_add_goals_ = this->create_callback_group(
                    rclcpp::CallbackGroupType::MutuallyExclusive);

            auto goal_bids_opt = rclcpp::SubscriptionOptions();
            goal_bids_opt.callback_group = cbgs_goal_bids_;
            auto add_goals_opt = rclcpp::SubscriptionOptions();
            add_goals_opt.callback_group = cbgs_add_goals_;

            goal_bids_ = this->create_subscription<ma_interfaces::msg::Bid>(
                    "goal_bids_topic",
                    rclcpp::QoS(10),
                    std::bind(
                        &ListenerNode::goal_bids_cb,
                        this,
                        std::placeholders::_1),
                    goal_bids_opt);

            add_goals_ = this->create_subscription<ma_interfaces::msg::Goal>(
                    "add_goals_topic",
                    rclcpp::QoS(10),
                    std::bind(
                        &ListenerNode::add_goals_cb,
                        this,
                        std::placeholders::_1),
                    add_goals_opt);
        }

    private:
        rclcpp::Publisher<ma_interfaces::msg::Goal>::SharedPtr publisher_;
        rclcpp::CallbackGroup::SharedPtr cbgs_goal_bids_;
        rclcpp::CallbackGroup::SharedPtr cbgs_add_goals_;
        rclcpp::Subscription<ma_interfaces::msg::Bid>::SharedPtr goal_bids_;
        rclcpp::Subscription<ma_interfaces::msg::Goal>::SharedPtr add_goals_;

        void goal_bids_cb(const ma_interfaces::msg::Bid bid)
        {
            if (goal_map.find(bid.auction_id) != goal_map.end()) {
                goal_map[bid.auction_id].push_back(bid);
            }
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Added bid from agent %s for goal %s", bid.agent_id.c_str(), bid.auction_id.c_str());
        }

        void add_goals_cb(const ma_interfaces::msg::Goal goal)
        {
            goal_map[goal.id] = std::vector<ma_interfaces::msg::Bid>();
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Starting goal auction for %s, collecting bids...", goal.id.c_str());
            publisher_->publish(goal);

            rclcpp::sleep_for(2s);

            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Bid collection phase ended.");

            ma_interfaces::msg::Bid winning_bid = goal_map[goal.id][0]; // Get first bid
            for (auto bid : goal_map[goal.id]) {
                if (bid.agent_id == "0") {
                    winning_bid = bid;
                    break;
                }
            }
            goal_map.erase(goal.id);

            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Goal %s won by agent %s", goal.id.c_str(), winning_bid.agent_id.c_str());

            ma_interfaces::msg::Goal new_goal = ma_interfaces::msg::Goal();
            new_goal.id = goal.id;
            new_goal.num_agents = goal.num_agents;
            new_goal.owner = winning_bid.agent_id;
            new_goal.duration = goal.duration;
            new_goal.execution_range = goal.execution_range;
            new_goal.deadline = -1;
            new_goal.x = goal.x;
            new_goal.y = goal.y;
            // new_goal.deadline = 
            publisher_->publish(new_goal);
        }
};


int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);

    rclcpp::executors::MultiThreadedExecutor executor;
    auto gm = std::make_shared<ListenerNode>();

    executor.add_node(gm);
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Goal manager started");

    executor.spin();
    rclcpp::shutdown();
    return 0;
}
