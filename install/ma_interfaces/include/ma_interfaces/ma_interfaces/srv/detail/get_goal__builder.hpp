// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ma_interfaces:srv/GetGoal.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__SRV__DETAIL__GET_GOAL__BUILDER_HPP_
#define MA_INTERFACES__SRV__DETAIL__GET_GOAL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ma_interfaces/srv/detail/get_goal__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ma_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetGoal_Request_id
{
public:
  Init_GetGoal_Request_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ma_interfaces::srv::GetGoal_Request id(::ma_interfaces::srv::GetGoal_Request::_id_type arg)
  {
    msg_.id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ma_interfaces::srv::GetGoal_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ma_interfaces::srv::GetGoal_Request>()
{
  return ma_interfaces::srv::builder::Init_GetGoal_Request_id();
}

}  // namespace ma_interfaces


namespace ma_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetGoal_Response_num_agents
{
public:
  explicit Init_GetGoal_Response_num_agents(::ma_interfaces::srv::GetGoal_Response & msg)
  : msg_(msg)
  {}
  ::ma_interfaces::srv::GetGoal_Response num_agents(::ma_interfaces::srv::GetGoal_Response::_num_agents_type arg)
  {
    msg_.num_agents = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ma_interfaces::srv::GetGoal_Response msg_;
};

class Init_GetGoal_Response_g
{
public:
  Init_GetGoal_Response_g()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetGoal_Response_num_agents g(::ma_interfaces::srv::GetGoal_Response::_g_type arg)
  {
    msg_.g = std::move(arg);
    return Init_GetGoal_Response_num_agents(msg_);
  }

private:
  ::ma_interfaces::srv::GetGoal_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ma_interfaces::srv::GetGoal_Response>()
{
  return ma_interfaces::srv::builder::Init_GetGoal_Response_g();
}

}  // namespace ma_interfaces

#endif  // MA_INTERFACES__SRV__DETAIL__GET_GOAL__BUILDER_HPP_
