// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ma_interfaces:msg/Goal.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__MSG__DETAIL__GOAL__BUILDER_HPP_
#define MA_INTERFACES__MSG__DETAIL__GOAL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ma_interfaces/msg/detail/goal__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ma_interfaces
{

namespace msg
{

namespace builder
{

class Init_Goal_owner
{
public:
  explicit Init_Goal_owner(::ma_interfaces::msg::Goal & msg)
  : msg_(msg)
  {}
  ::ma_interfaces::msg::Goal owner(::ma_interfaces::msg::Goal::_owner_type arg)
  {
    msg_.owner = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ma_interfaces::msg::Goal msg_;
};

class Init_Goal_id
{
public:
  Init_Goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Goal_owner id(::ma_interfaces::msg::Goal::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Goal_owner(msg_);
  }

private:
  ::ma_interfaces::msg::Goal msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ma_interfaces::msg::Goal>()
{
  return ma_interfaces::msg::builder::Init_Goal_id();
}

}  // namespace ma_interfaces

#endif  // MA_INTERFACES__MSG__DETAIL__GOAL__BUILDER_HPP_
