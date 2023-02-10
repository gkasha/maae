// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ma_interfaces:srv/GetBid.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__SRV__DETAIL__GET_BID__BUILDER_HPP_
#define MA_INTERFACES__SRV__DETAIL__GET_BID__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ma_interfaces/srv/detail/get_bid__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ma_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetBid_Request_t
{
public:
  Init_GetBid_Request_t()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ma_interfaces::srv::GetBid_Request t(::ma_interfaces::srv::GetBid_Request::_t_type arg)
  {
    msg_.t = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ma_interfaces::srv::GetBid_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ma_interfaces::srv::GetBid_Request>()
{
  return ma_interfaces::srv::builder::Init_GetBid_Request_t();
}

}  // namespace ma_interfaces


namespace ma_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetBid_Response_b
{
public:
  Init_GetBid_Response_b()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ma_interfaces::srv::GetBid_Response b(::ma_interfaces::srv::GetBid_Response::_b_type arg)
  {
    msg_.b = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ma_interfaces::srv::GetBid_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ma_interfaces::srv::GetBid_Response>()
{
  return ma_interfaces::srv::builder::Init_GetBid_Response_b();
}

}  // namespace ma_interfaces

#endif  // MA_INTERFACES__SRV__DETAIL__GET_BID__BUILDER_HPP_
