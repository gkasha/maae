// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ma_interfaces:msg/AuctionMsg.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__MSG__DETAIL__AUCTION_MSG__BUILDER_HPP_
#define MA_INTERFACES__MSG__DETAIL__AUCTION_MSG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ma_interfaces/msg/detail/auction_msg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ma_interfaces
{

namespace msg
{

namespace builder
{

class Init_AuctionMsg_graph
{
public:
  Init_AuctionMsg_graph()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ma_interfaces::msg::AuctionMsg graph(::ma_interfaces::msg::AuctionMsg::_graph_type arg)
  {
    msg_.graph = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ma_interfaces::msg::AuctionMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ma_interfaces::msg::AuctionMsg>()
{
  return ma_interfaces::msg::builder::Init_AuctionMsg_graph();
}

}  // namespace ma_interfaces

#endif  // MA_INTERFACES__MSG__DETAIL__AUCTION_MSG__BUILDER_HPP_
