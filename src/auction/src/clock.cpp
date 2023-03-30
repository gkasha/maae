#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int64.hpp"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */

class CentralClock : public rclcpp::Node
{
  public:
    CentralClock()
    : Node("central_clock"), count_(0)
    {
      publisher_ = this->create_publisher<std_msgs::msg::Int64>("clock_topic", 10);
      timer_ = this->create_wall_timer(
      1000ms, std::bind(&CentralClock::timer_callback, this));
    }

  private:
    void timer_callback()
    {
      auto message = std_msgs::msg::Int64();
      message.data = count_++;
      RCLCPP_INFO(this->get_logger(), "Publishing: '%ld'", message.data);
      publisher_->publish(message);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::Int64>::SharedPtr publisher_;
    size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<CentralClock>());
  rclcpp::shutdown();
  return 0;
}