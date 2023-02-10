// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ma_interfaces:srv/AuctionResult.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__SRV__DETAIL__AUCTION_RESULT__BUILDER_HPP_
#define MA_INTERFACES__SRV__DETAIL__AUCTION_RESULT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ma_interfaces/srv/detail/auction_result__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ma_interfaces
{

namespace srv
{

namespace builder
{

class Init_AuctionResult_Request_b
{
public:
  explicit Init_AuctionResult_Request_b(::ma_interfaces::srv::AuctionResult_Request & msg)
  : msg_(msg)
  {}
  ::ma_interfaces::srv::AuctionResult_Request b(::ma_interfaces::srv::AuctionResult_Request::_b_type arg)
  {
    msg_.b = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ma_interfaces::srv::AuctionResult_Request msg_;
};

class Init_AuctionResult_Request_t
{
public:
  Init_AuctionResult_Request_t()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AuctionResult_Request_b t(::ma_interfaces::srv::AuctionResult_Request::_t_type arg)
  {
    msg_.t = std::move(arg);
    return Init_AuctionResult_Request_b(msg_);
  }

private:
  ::ma_interfaces::srv::AuctionResult_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ma_interfaces::srv::AuctionResult_Request>()
{
  return ma_interfaces::srv::builder::Init_AuctionResult_Request_t();
}

}  // namespace ma_interfaces


namespace ma_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ma_interfaces::srv::AuctionResult_Response>()
{
  return ::ma_interfaces::srv::AuctionResult_Response(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace ma_interfaces

#endif  // MA_INTERFACES__SRV__DETAIL__AUCTION_RESULT__BUILDER_HPP_
