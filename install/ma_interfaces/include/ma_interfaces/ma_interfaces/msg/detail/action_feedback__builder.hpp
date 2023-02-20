// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ma_interfaces:msg/ActionFeedback.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__MSG__DETAIL__ACTION_FEEDBACK__BUILDER_HPP_
#define MA_INTERFACES__MSG__DETAIL__ACTION_FEEDBACK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ma_interfaces/msg/detail/action_feedback__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ma_interfaces
{

namespace msg
{

namespace builder
{

class Init_ActionFeedback_action_failed
{
public:
  explicit Init_ActionFeedback_action_failed(::ma_interfaces::msg::ActionFeedback & msg)
  : msg_(msg)
  {}
  ::ma_interfaces::msg::ActionFeedback action_failed(::ma_interfaces::msg::ActionFeedback::_action_failed_type arg)
  {
    msg_.action_failed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ma_interfaces::msg::ActionFeedback msg_;
};

class Init_ActionFeedback_action_completed
{
public:
  explicit Init_ActionFeedback_action_completed(::ma_interfaces::msg::ActionFeedback & msg)
  : msg_(msg)
  {}
  Init_ActionFeedback_action_failed action_completed(::ma_interfaces::msg::ActionFeedback::_action_completed_type arg)
  {
    msg_.action_completed = std::move(arg);
    return Init_ActionFeedback_action_failed(msg_);
  }

private:
  ::ma_interfaces::msg::ActionFeedback msg_;
};

class Init_ActionFeedback_action_started
{
public:
  explicit Init_ActionFeedback_action_started(::ma_interfaces::msg::ActionFeedback & msg)
  : msg_(msg)
  {}
  Init_ActionFeedback_action_completed action_started(::ma_interfaces::msg::ActionFeedback::_action_started_type arg)
  {
    msg_.action_started = std::move(arg);
    return Init_ActionFeedback_action_completed(msg_);
  }

private:
  ::ma_interfaces::msg::ActionFeedback msg_;
};

class Init_ActionFeedback_st
{
public:
  explicit Init_ActionFeedback_st(::ma_interfaces::msg::ActionFeedback & msg)
  : msg_(msg)
  {}
  Init_ActionFeedback_action_started st(::ma_interfaces::msg::ActionFeedback::_st_type arg)
  {
    msg_.st = std::move(arg);
    return Init_ActionFeedback_action_started(msg_);
  }

private:
  ::ma_interfaces::msg::ActionFeedback msg_;
};

class Init_ActionFeedback_name
{
public:
  explicit Init_ActionFeedback_name(::ma_interfaces::msg::ActionFeedback & msg)
  : msg_(msg)
  {}
  Init_ActionFeedback_st name(::ma_interfaces::msg::ActionFeedback::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_ActionFeedback_st(msg_);
  }

private:
  ::ma_interfaces::msg::ActionFeedback msg_;
};

class Init_ActionFeedback_agent_id
{
public:
  explicit Init_ActionFeedback_agent_id(::ma_interfaces::msg::ActionFeedback & msg)
  : msg_(msg)
  {}
  Init_ActionFeedback_name agent_id(::ma_interfaces::msg::ActionFeedback::_agent_id_type arg)
  {
    msg_.agent_id = std::move(arg);
    return Init_ActionFeedback_name(msg_);
  }

private:
  ::ma_interfaces::msg::ActionFeedback msg_;
};

class Init_ActionFeedback_action_id
{
public:
  Init_ActionFeedback_action_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ActionFeedback_agent_id action_id(::ma_interfaces::msg::ActionFeedback::_action_id_type arg)
  {
    msg_.action_id = std::move(arg);
    return Init_ActionFeedback_agent_id(msg_);
  }

private:
  ::ma_interfaces::msg::ActionFeedback msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ma_interfaces::msg::ActionFeedback>()
{
  return ma_interfaces::msg::builder::Init_ActionFeedback_action_id();
}

}  // namespace ma_interfaces

#endif  // MA_INTERFACES__MSG__DETAIL__ACTION_FEEDBACK__BUILDER_HPP_
