// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ma_interfaces:msg/Node.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__MSG__DETAIL__NODE__BUILDER_HPP_
#define MA_INTERFACES__MSG__DETAIL__NODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ma_interfaces/msg/detail/node__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ma_interfaces
{

namespace msg
{

namespace builder
{

class Init_Node_value
{
public:
  explicit Init_Node_value(::ma_interfaces::msg::Node & msg)
  : msg_(msg)
  {}
  ::ma_interfaces::msg::Node value(::ma_interfaces::msg::Node::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ma_interfaces::msg::Node msg_;
};

class Init_Node_next
{
public:
  explicit Init_Node_next(::ma_interfaces::msg::Node & msg)
  : msg_(msg)
  {}
  Init_Node_value next(::ma_interfaces::msg::Node::_next_type arg)
  {
    msg_.next = std::move(arg);
    return Init_Node_value(msg_);
  }

private:
  ::ma_interfaces::msg::Node msg_;
};

class Init_Node_children
{
public:
  explicit Init_Node_children(::ma_interfaces::msg::Node & msg)
  : msg_(msg)
  {}
  Init_Node_next children(::ma_interfaces::msg::Node::_children_type arg)
  {
    msg_.children = std::move(arg);
    return Init_Node_next(msg_);
  }

private:
  ::ma_interfaces::msg::Node msg_;
};

class Init_Node_name
{
public:
  Init_Node_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Node_children name(::ma_interfaces::msg::Node::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_Node_children(msg_);
  }

private:
  ::ma_interfaces::msg::Node msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ma_interfaces::msg::Node>()
{
  return ma_interfaces::msg::builder::Init_Node_name();
}

}  // namespace ma_interfaces

#endif  // MA_INTERFACES__MSG__DETAIL__NODE__BUILDER_HPP_
