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
        Agent(int id) : Node("agent_server_"+std::to_string(id))
        {
            std::string topic = "agent_topic_" + std::to_string(id);
            id_ = id;
        }
        rclcpp::Service<ma_interfaces::srv::GetBid>::SharedPtr bid_service_;
        rclcpp::Service<ma_interfaces::srv::AuctionSrv>::SharedPtr auction_service_;
        rclcpp::Service<ma_interfaces::srv::AuctionResult>::SharedPtr auction_result_service_;
        int id_;
        TNode* root_;
    

};


std::shared_ptr<Agent> master;

// Function to print agent's timeline to RCLCPP logger
void print_timeline() {
    TNode* curr = master->root_;
    std::string timeline = "";

    while(curr) {
        std::string temp = "(" + curr->name_ 
                        + ", " + std::to_string(curr->st_)
                        + ", " + std::to_string(curr->et_)
                        + ", scheduled=" + std::to_string(curr->scheduled_)
                        + ") --> \n";
        timeline += temp;
        curr = curr->next;
    }
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"),"Agent %d timeline:\n%s", master->id_, timeline.c_str()); 
}

// Service provided to auctioneers that allows them to publish results of auction
void send_auction_result(
        const std::shared_ptr<ma_interfaces::srv::AuctionResult::Request> req,
        std::shared_ptr<ma_interfaces::srv::AuctionResult::Response> rep)
{
    // Look for the task on our timeline
    TNode* prev = nullptr;
    TNode* curr = master->root_;
    while (curr) {
        if (curr->name_ == req->b.name) {
            // Found task, see if we schedule or remove it
            if (std::to_string(master->id_) == req->b.id) {
                // We won the auction
                curr->scheduled_ = true;
                RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Scheduled task %s", req->b.name.c_str());
            } else  {
                if (prev) {
                    prev->next = curr->next;
                    delete curr;
                } else {
                    master->root_ = curr->next;
                    delete curr;
                }
                RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Unscheduled task %s", req->b.name.c_str());
            }
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    print_timeline();
}

// Service provided to auctioneers that allows them to query the agent for a bid
void get_bid(
        const std::shared_ptr<ma_interfaces::srv::GetBid::Request> req,
        std::shared_ptr<ma_interfaces::srv::GetBid::Response> rep)
{
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Generating a bid for %s", req->t.name.c_str());

    // Look at timeline -- For now, we will always create a bid
    TNode* bid_node;

    if (!master->root_) {
        // Nothing on timeline, can schedule on timeline immediately
        bid_node = new TNode(0, req->t.duration, false, req->t.name);
        master->root_ = bid_node;
    } else {
        // Stuff on timeline, need to find first slot
        TNode* curr = master->root_;
        while (curr->next) {
            // See if we can fit in the task between already scheduled tasks
            if (curr->next->st_ - curr->et_ >= req->t.duration) {
                bid_node = new TNode(curr->et_, curr->et_+req->t.duration, false, req->t.name);
                TNode* temp = curr->next;
                curr->next = bid_node;
                bid_node->next = temp;
                break;
            }
            curr = curr->next;
        }
        if (!curr->next) {
            // We reached the end, and we didn't find a slot yet
            bid_node = new TNode(curr->et_, curr->et_+req->t.duration, false, req->t.name);
            curr->next = bid_node;
        }   
    }

    auto bid = ma_interfaces::msg::Bid();
    bid.id = std::to_string(master->id_);
    bid.name = req->t.name;
    bid.st = bid_node->st_;
    bid.et = bid_node->et_; 
    bid.value = req->t.value;
    rep->b = bid;

    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Generated a bid of value %ld for task %s", bid.value, bid.name.c_str());
    print_timeline();
}

std::vector<ma_interfaces::msg::Bid> get_agent_bids(std::shared_ptr<rclcpp::Node> client_node, ma_interfaces::msg::Task t, int num_agents) {

    std::vector<ma_interfaces::msg::Bid> bids;
    
    auto bid_req = std::make_shared<ma_interfaces::srv::GetBid::Request>();
    
    bid_req->t = t;

    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Getting bids");
    for (int i = 0; i < num_agents; i++) {
        if (i != master->id_) {
            // Get bids, eventually try to do asynchronously
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Waiting for bid service: %d",i);
            rclcpp::Client<ma_interfaces::srv::GetBid>::SharedPtr bid_client = 
                client_node->create_client<ma_interfaces::srv::GetBid>("get_bid_"+std::to_string(i));
            
            while (!bid_client->wait_for_service(1s)) {
                if (!rclcpp::ok()) {
                    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for bid");
                    break;
                }
                RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Service not available, waiting again.");
            }

            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Sending bid request");
            auto bid_res = bid_client->async_send_request(bid_req);
            if (rclcpp::spin_until_future_complete(client_node, bid_res) ==
                rclcpp::FutureReturnCode::SUCCESS)
            {
                bids.push_back(bid_res.get()->b);
                RCLCPP_INFO(rclcpp::get_logger("rclcpp"),"Received bid");
            } else {
                RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call bid service for %d", i);
            }
        }
    }
    return bids;
}

void publish_auction_winner(std::shared_ptr<rclcpp::Node> client_node,
                            ma_interfaces::msg::Task t, 
                            std::vector<ma_interfaces::msg::Bid> bids,
                            ma_interfaces::msg::Bid winning_bid)
{
    auto auction_result = std::make_shared<ma_interfaces::srv::AuctionResult::Request>();
    auction_result->t = t;
    auction_result->b = winning_bid;

    for (auto bid : bids) {
        rclcpp::Client<ma_interfaces::srv::AuctionResult>::SharedPtr result_client = 
            client_node->create_client<ma_interfaces::srv::AuctionResult>("send_auction_result_"+bid.id);

        while (!result_client->wait_for_service(1s)) {
            if (!rclcpp::ok()) {
                RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for bid");
                break;
            }
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Service not available, waiting again.");
        }
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Sending auction result");
        auto res = result_client->async_send_request(auction_result);
        if (rclcpp::spin_until_future_complete(client_node, res) ==
            rclcpp::FutureReturnCode::SUCCESS)
        {
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"),"Sent result");
        } else {
            RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to send result to %d", bid.id);
        }
    }
}
                    

// Service to allow manual trigger for auction
void start_auction(
        const std::shared_ptr<ma_interfaces::srv::AuctionSrv::Request> tmp_req,
        std::shared_ptr<ma_interfaces::srv::AuctionSrv::Response> tmp_rep)
{
    
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Attempting to grab new goal");

    // Create request, check service availability
    auto request = std::make_shared<ma_interfaces::srv::GetGoal::Request>();
    request->id = master->id_;

    // Create client node
    std::shared_ptr<rclcpp::Node> client_node = rclcpp::Node::make_shared("agent_client_" + std::to_string(master->id_));
    rclcpp::Client<ma_interfaces::srv::GetGoal>::SharedPtr goal_client = 
        client_node->create_client<ma_interfaces::srv::GetGoal>("get_goal");

    while (!goal_client->wait_for_service(1s)) {
        if (!rclcpp::ok()) {
            RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for goal service");
            return;
        }
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Service not available, waiting again");
    }

    // Send request
    auto result = goal_client->async_send_request(request);
    int status = 0;

    // Wait for result
    if (rclcpp::spin_until_future_complete(client_node, result) ==
            rclcpp::FutureReturnCode::SUCCESS)
    {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Received goal, starting auction");
        status = 1;

        auto goal_res = result.get();
        ma_interfaces::msg::Task t = ma_interfaces::msg::Task();
        t.name = goal_res->g.name;
        t.duration = 10; // Default duration
        t.value = 10; // Default value

        // Want to start an auction
        std::vector<ma_interfaces::msg::Bid> bids = get_agent_bids(client_node, t, goal_res->num_agents);

        // Determine winner by start time, tie-break by value
        if (bids.size() > 0) {
            ma_interfaces::msg::Bid winning_bid = bids[0];
            for (auto bid : bids) {
                if (bid.st < winning_bid.st) {
                    winning_bid = bid;
                } else if (bid.st == winning_bid.st && bid.value < winning_bid.value) {
                    winning_bid = bid;
                }
                
            }
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), 
                "Winner for task %s is agent %s, with a value of %ld", 
                    t.name.c_str(), winning_bid.id.c_str(), winning_bid.value);
            publish_auction_winner(client_node, t, bids, winning_bid);
        }
    }
}

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    master = std::make_shared<Agent>(atoll(argv[1]));
    
    // Register with GM
    rclcpp::Client<ma_interfaces::srv::Register>::SharedPtr client = 
        master->create_client<ma_interfaces::srv::Register>("register_agent");
    
    auto req = std::make_shared<ma_interfaces::srv::Register::Request>();
    req->id = std::to_string(master->id_);
    while (!client->wait_for_service(1s)) {
        if (!rclcpp::ok()) {
            RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while registering");
            return -1;
        }
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Register service not available, waiting...");
    }
    auto res = client->async_send_request(req);
    if (rclcpp::spin_until_future_complete(master, res) !=
            rclcpp::FutureReturnCode::SUCCESS)
    {
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to register");
        return -1;
    }

    // Create services
    master->bid_service_ = 
        master->create_service<ma_interfaces::srv::GetBid>(
                "get_bid_"+std::to_string(master->id_), &get_bid);
    master->auction_service_ = 
        master->create_service<ma_interfaces::srv::AuctionSrv>(
                "start_auction_"+std::to_string(master->id_), &start_auction);
    master->auction_result_service_ = 
        master->create_service<ma_interfaces::srv::AuctionResult>(
                "send_auction_result_"+std::to_string(master->id_), &send_auction_result);


    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Agent ready: %s", argv[1]);
    rclcpp::spin(master);
    rclcpp::shutdown();
    return 0;
}
