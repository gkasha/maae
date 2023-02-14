#include "rclcpp/rclcpp.hpp"

#include "ma_interfaces/srv/register.hpp"
#include "ma_interfaces/srv/auction_srv.hpp"
#include "ma_interfaces/srv/auction_result.hpp"
#include "ma_interfaces/srv/get_goal.hpp"
#include "ma_interfaces/srv/get_bid.hpp"

#include "ma_interfaces/msg/goal.hpp"
#include "ma_interfaces/msg/task.hpp"
#include "ma_interfaces/msg/bid.hpp"

#include <chrono>
#include <vector>
#include <string>

/*
 * Code for the agent class of the auction package
 *
 * The agent class provides 2 services to others: the bid service and
 * the auction service
 *
 * These run under the same node, and allow other agents and users to interface
 * with the agent
 *
 * The agent class also occasionally acts as a client for other services, 
 * either when asking for a goal from the goal manager or when asking for bids
 * from other agents. This is done dynamically. In particular, each time
 * the agent wants to act as a client, it creates a client node, and conducts
 * the necessary operations.
 */

using namespace std::chrono_literals;

class TNode
{
    public:
        TNode(int st, int et, bool scheduled, std::string name) {
            st_ = st;
            et_ = et;
            scheduled_ = scheduled;
            name_ = name;
            next = nullptr;
        };
        int st_; // Node start time
        int et_; // Node end time
        bool scheduled_;
        std::string name_;
        TNode* next;
};


class Agent : public rclcpp::Node
{
    public:
        Agent(std::string id) : Node("agent_"+id)
        {
            std::string topic = "agent_topic_" + id;
            id_ = id;

            publisher_ = this->create_publisher<ma_interfaces::msg::Bid>("goal_bids_topic", 10);

            cbgs_new_goals_ = this->create_callback_group(
                    rclcpp::CallbackGroupType::MutuallyExclusive);

            auto new_goals_opt = rclcpp::SubscriptionOptions();
            new_goals_opt.callback_group = cbgs_new_goals_;

            new_goals_ = this->create_subscription<ma_interfaces::msg::Goal>(
                    "new_goals_topic",
                    rclcpp::QoS(10),
                    std::bind(
                        &Agent::new_goals_cb,
                        this,
                        std::placeholders::_1),
                        new_goals_opt);
        }

    private:
        rclcpp::Publisher<ma_interfaces::msg::Bid>::SharedPtr publisher_;
        rclcpp::CallbackGroup::SharedPtr cbgs_new_goals_;
        rclcpp::Subscription<ma_interfaces::msg::Goal>::SharedPtr new_goals_;
        std::string id_;

        void new_goals_cb(const ma_interfaces::msg::Goal goal) {
            ma_interfaces::msg::Bid bid = ma_interfaces::msg::Bid();
            bid.agent_id = id_;
            bid.auction_id = goal.id;
            bid.value = 10;

            publisher_->publish(bid);
        }
};


int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);

    rclcpp::executors::MultiThreadedExecutor executor;
    auto agent_node = std::make_shared<Agent>(argv[1]);

    executor.add_node(agent_node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}
