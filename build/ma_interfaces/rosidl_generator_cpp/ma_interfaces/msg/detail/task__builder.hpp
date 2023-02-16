// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ma_interfaces:msg/Task.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__MSG__DETAIL__TASK__BUILDER_HPP_
#define MA_INTERFACES__MSG__DETAIL__TASK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ma_interfaces/msg/detail/task__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ma_interfaces
{

namespace msg
{

namespace builder
{

class Init_Task_value
{
public:
  explicit Init_Task_value(::ma_interfaces::msg::Task & msg)
  : msg_(msg)
  {}
  ::ma_interfaces::msg::Task value(::ma_interfaces::msg::Task::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ma_interfaces::msg::Task msg_;
};

class Init_Task_duration
{
public:
  explicit Init_Task_duration(::ma_interfaces::msg::Task & msg)
  : msg_(msg)
  {}
  Init_Task_value duration(::ma_interfaces::msg::Task::_duration_type arg)
  {
    msg_.duration = std::move(arg);
    return Init_Task_value(msg_);
  }

private:
  ::ma_interfaces::msg::Task msg_;
};

class Init_Task_owner
{
public:
  explicit Init_Task_owner(::ma_interfaces::msg::Task & msg)
  : msg_(msg)
  {}
  Init_Task_duration owner(::ma_interfaces::msg::Task::_owner_type arg)
  {
    msg_.owner = std::move(arg);
    return Init_Task_duration(msg_);
  }

private:
  ::ma_interfaces::msg::Task msg_;
};

class Init_Task_id
{
public:
  Init_Task_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Task_owner id(::ma_interfaces::msg::Task::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Task_owner(msg_);
  }

private:
  ::ma_interfaces::msg::Task msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ma_interfaces::msg::Task>()
{
  return ma_interfaces::msg::builder::Init_Task_id();
}

}  // namespace ma_interfaces

#endif  // MA_INTERFACES__MSG__DETAIL__TASK__BUILDER_HPP_
