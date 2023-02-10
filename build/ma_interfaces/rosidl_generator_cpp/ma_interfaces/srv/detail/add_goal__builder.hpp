// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ma_interfaces:srv/AddGoal.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__SRV__DETAIL__ADD_GOAL__BUILDER_HPP_
#define MA_INTERFACES__SRV__DETAIL__ADD_GOAL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ma_interfaces/srv/detail/add_goal__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ma_interfaces
{

namespace srv
{

namespace builder
{

class Init_AddGoal_Request_g
{
public:
  Init_AddGoal_Request_g()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ma_interfaces::srv::AddGoal_Request g(::ma_interfaces::srv::AddGoal_Request::_g_type arg)
  {
    msg_.g = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ma_interfaces::srv::AddGoal_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ma_interfaces::srv::AddGoal_Request>()
{
  return ma_interfaces::srv::builder::Init_AddGoal_Request_g();
}

}  // namespace ma_interfaces


namespace ma_interfaces
{

namespace srv
{

namespace builder
{

class Init_AddGoal_Response_status
{
public:
  Init_AddGoal_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ma_interfaces::srv::AddGoal_Response status(::ma_interfaces::srv::AddGoal_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ma_interfaces::srv::AddGoal_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ma_interfaces::srv::AddGoal_Response>()
{
  return ma_interfaces::srv::builder::Init_AddGoal_Response_status();
}

}  // namespace ma_interfaces

#endif  // MA_INTERFACES__SRV__DETAIL__ADD_GOAL__BUILDER_HPP_
