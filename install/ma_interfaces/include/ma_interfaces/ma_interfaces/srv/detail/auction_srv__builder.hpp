// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ma_interfaces:srv/AuctionSrv.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__SRV__DETAIL__AUCTION_SRV__BUILDER_HPP_
#define MA_INTERFACES__SRV__DETAIL__AUCTION_SRV__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ma_interfaces/srv/detail/auction_srv__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ma_interfaces
{

namespace srv
{

namespace builder
{

class Init_AuctionSrv_Request_name
{
public:
  Init_AuctionSrv_Request_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ma_interfaces::srv::AuctionSrv_Request name(::ma_interfaces::srv::AuctionSrv_Request::_name_type arg)
  {
    msg_.name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ma_interfaces::srv::AuctionSrv_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ma_interfaces::srv::AuctionSrv_Request>()
{
  return ma_interfaces::srv::builder::Init_AuctionSrv_Request_name();
}

}  // namespace ma_interfaces


namespace ma_interfaces
{

namespace srv
{

namespace builder
{

class Init_AuctionSrv_Response_status
{
public:
  Init_AuctionSrv_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ma_interfaces::srv::AuctionSrv_Response status(::ma_interfaces::srv::AuctionSrv_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ma_interfaces::srv::AuctionSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ma_interfaces::srv::AuctionSrv_Response>()
{
  return ma_interfaces::srv::builder::Init_AuctionSrv_Response_status();
}

}  // namespace ma_interfaces

#endif  // MA_INTERFACES__SRV__DETAIL__AUCTION_SRV__BUILDER_HPP_
