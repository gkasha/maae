#include "rclcpp/rclcpp.hpp"
#include "ma_interfaces/srv/auction_srv.hpp"
#include "ma_interfaces/msg/auction_msg.hpp"
#include "ma_interfaces/msg/node.hpp"
#include <vector>


class Auctioneer : public rclcpp::Node
{
    public:
        Auctioneer(int id) : Node("auction_server_"+std::to_string(id))
        {
            std::string topic = "auction_topic_" + std::to_string(id);
            publisher_ = this->create_publisher<ma_interfaces::msg::AuctionMsg>(
                    topic, 10);
            id_ = id;
        }

        rclcpp::Publisher<ma_interfaces::msg::AuctionMsg>::SharedPtr publisher_;
        int id_;

};

std::vector<Auctioneer*> auctions;

void start_auction(
        const std::shared_ptr<ma_interfaces::srv::AuctionSrv::Request> req,
        std::shared_ptr<ma_interfaces::srv::AuctionSrv::Response> rep)
{
    /*
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Starting auction for  %s", req->name.c_str());
    auto msg = ma_interfaces::msg::AuctionMsg();
    msg.graph = std::vector<ma_interfaces::msg::Node>();
    for (ma_interfaces::msg::Node v : req->graph) {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Graph has node: %s", v.name.c_str());
        msg.graph.push_back(v);
    }
    Auctioneer* a = new Auctioneer(auctions.size());
    auctions.push_back(a);
    
    // Publish task network onto the auction topic
    a->publisher_->publish(msg);
    rep->status = "Auction started";

    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Current auctions: %ld", auctions.size());
    */
}

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);

    std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("auction_server");

    rclcpp::Service<ma_interfaces::srv::AuctionSrv>::SharedPtr service = 
        node->create_service<ma_interfaces::srv::AuctionSrv>("start_auction", start_auction);

    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to start auction.");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
};
