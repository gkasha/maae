// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ma_interfaces:msg/ActionDispatch.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__MSG__DETAIL__ACTION_DISPATCH__BUILDER_HPP_
#define MA_INTERFACES__MSG__DETAIL__ACTION_DISPATCH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ma_interfaces/msg/detail/action_dispatch__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ma_interfaces
{

namespace msg
{

namespace builder
{

class Init_ActionDispatch_start_time
{
public:
  explicit Init_ActionDispatch_start_time(::ma_interfaces::msg::ActionDispatch & msg)
  : msg_(msg)
  {}
  ::ma_interfaces::msg::ActionDispatch start_time(::ma_interfaces::msg::ActionDispatch::_start_time_type arg)
  {
    msg_.start_time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ma_interfaces::msg::ActionDispatch msg_;
};

class Init_ActionDispatch_duration
{
public:
  explicit Init_ActionDispatch_duration(::ma_interfaces::msg::ActionDispatch & msg)
  : msg_(msg)
  {}
  Init_ActionDispatch_start_time duration(::ma_interfaces::msg::ActionDispatch::_duration_type arg)
  {
    msg_.duration = std::move(arg);
    return Init_ActionDispatch_start_time(msg_);
  }

private:
  ::ma_interfaces::msg::ActionDispatch msg_;
};

class Init_ActionDispatch_execution_range
{
public:
  explicit Init_ActionDispatch_execution_range(::ma_interfaces::msg::ActionDispatch & msg)
  : msg_(msg)
  {}
  Init_ActionDispatch_duration execution_range(::ma_interfaces::msg::ActionDispatch::_execution_range_type arg)
  {
    msg_.execution_range = std::move(arg);
    return Init_ActionDispatch_duration(msg_);
  }

private:
  ::ma_interfaces::msg::ActionDispatch msg_;
};

class Init_ActionDispatch_num_agents
{
public:
  explicit Init_ActionDispatch_num_agents(::ma_interfaces::msg::ActionDispatch & msg)
  : msg_(msg)
  {}
  Init_ActionDispatch_execution_range num_agents(::ma_interfaces::msg::ActionDispatch::_num_agents_type arg)
  {
    msg_.num_agents = std::move(arg);
    return Init_ActionDispatch_execution_range(msg_);
  }

private:
  ::ma_interfaces::msg::ActionDispatch msg_;
};

class Init_ActionDispatch_name
{
public:
  explicit Init_ActionDispatch_name(::ma_interfaces::msg::ActionDispatch & msg)
  : msg_(msg)
  {}
  Init_ActionDispatch_num_agents name(::ma_interfaces::msg::ActionDispatch::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_ActionDispatch_num_agents(msg_);
  }

private:
  ::ma_interfaces::msg::ActionDispatch msg_;
};

class Init_ActionDispatch_agent_id
{
public:
  explicit Init_ActionDispatch_agent_id(::ma_interfaces::msg::ActionDispatch & msg)
  : msg_(msg)
  {}
  Init_ActionDispatch_name agent_id(::ma_interfaces::msg::ActionDispatch::_agent_id_type arg)
  {
    msg_.agent_id = std::move(arg);
    return Init_ActionDispatch_name(msg_);
  }

private:
  ::ma_interfaces::msg::ActionDispatch msg_;
};

class Init_ActionDispatch_action_id
{
public:
  Init_ActionDispatch_action_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ActionDispatch_agent_id action_id(::ma_interfaces::msg::ActionDispatch::_action_id_type arg)
  {
    msg_.action_id = std::move(arg);
    return Init_ActionDispatch_agent_id(msg_);
  }

private:
  ::ma_interfaces::msg::ActionDispatch msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ma_interfaces::msg::ActionDispatch>()
{
  return ma_interfaces::msg::builder::Init_ActionDispatch_action_id();
}

}  // namespace ma_interfaces

#endif  // MA_INTERFACES__MSG__DETAIL__ACTION_DISPATCH__BUILDER_HPP_
