// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ma_interfaces:msg/Slot.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__MSG__DETAIL__SLOT__BUILDER_HPP_
#define MA_INTERFACES__MSG__DETAIL__SLOT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ma_interfaces/msg/detail/slot__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ma_interfaces
{

namespace msg
{

namespace builder
{

class Init_Slot_speed
{
public:
  explicit Init_Slot_speed(::ma_interfaces::msg::Slot & msg)
  : msg_(msg)
  {}
  ::ma_interfaces::msg::Slot speed(::ma_interfaces::msg::Slot::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ma_interfaces::msg::Slot msg_;
};

class Init_Slot_y2
{
public:
  explicit Init_Slot_y2(::ma_interfaces::msg::Slot & msg)
  : msg_(msg)
  {}
  Init_Slot_speed y2(::ma_interfaces::msg::Slot::_y2_type arg)
  {
    msg_.y2 = std::move(arg);
    return Init_Slot_speed(msg_);
  }

private:
  ::ma_interfaces::msg::Slot msg_;
};

class Init_Slot_x2
{
public:
  explicit Init_Slot_x2(::ma_interfaces::msg::Slot & msg)
  : msg_(msg)
  {}
  Init_Slot_y2 x2(::ma_interfaces::msg::Slot::_x2_type arg)
  {
    msg_.x2 = std::move(arg);
    return Init_Slot_y2(msg_);
  }

private:
  ::ma_interfaces::msg::Slot msg_;
};

class Init_Slot_y1
{
public:
  explicit Init_Slot_y1(::ma_interfaces::msg::Slot & msg)
  : msg_(msg)
  {}
  Init_Slot_x2 y1(::ma_interfaces::msg::Slot::_y1_type arg)
  {
    msg_.y1 = std::move(arg);
    return Init_Slot_x2(msg_);
  }

private:
  ::ma_interfaces::msg::Slot msg_;
};

class Init_Slot_x1
{
public:
  explicit Init_Slot_x1(::ma_interfaces::msg::Slot & msg)
  : msg_(msg)
  {}
  Init_Slot_y1 x1(::ma_interfaces::msg::Slot::_x1_type arg)
  {
    msg_.x1 = std::move(arg);
    return Init_Slot_y1(msg_);
  }

private:
  ::ma_interfaces::msg::Slot msg_;
};

class Init_Slot_et
{
public:
  explicit Init_Slot_et(::ma_interfaces::msg::Slot & msg)
  : msg_(msg)
  {}
  Init_Slot_x1 et(::ma_interfaces::msg::Slot::_et_type arg)
  {
    msg_.et = std::move(arg);
    return Init_Slot_x1(msg_);
  }

private:
  ::ma_interfaces::msg::Slot msg_;
};

class Init_Slot_st
{
public:
  explicit Init_Slot_st(::ma_interfaces::msg::Slot & msg)
  : msg_(msg)
  {}
  Init_Slot_et st(::ma_interfaces::msg::Slot::_st_type arg)
  {
    msg_.st = std::move(arg);
    return Init_Slot_et(msg_);
  }

private:
  ::ma_interfaces::msg::Slot msg_;
};

class Init_Slot_task_id
{
public:
  explicit Init_Slot_task_id(::ma_interfaces::msg::Slot & msg)
  : msg_(msg)
  {}
  Init_Slot_st task_id(::ma_interfaces::msg::Slot::_task_id_type arg)
  {
    msg_.task_id = std::move(arg);
    return Init_Slot_st(msg_);
  }

private:
  ::ma_interfaces::msg::Slot msg_;
};

class Init_Slot_owner_id
{
public:
  explicit Init_Slot_owner_id(::ma_interfaces::msg::Slot & msg)
  : msg_(msg)
  {}
  Init_Slot_task_id owner_id(::ma_interfaces::msg::Slot::_owner_id_type arg)
  {
    msg_.owner_id = std::move(arg);
    return Init_Slot_task_id(msg_);
  }

private:
  ::ma_interfaces::msg::Slot msg_;
};

class Init_Slot_agent_id
{
public:
  Init_Slot_agent_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Slot_owner_id agent_id(::ma_interfaces::msg::Slot::_agent_id_type arg)
  {
    msg_.agent_id = std::move(arg);
    return Init_Slot_owner_id(msg_);
  }

private:
  ::ma_interfaces::msg::Slot msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ma_interfaces::msg::Slot>()
{
  return ma_interfaces::msg::builder::Init_Slot_agent_id();
}

}  // namespace ma_interfaces

#endif  // MA_INTERFACES__MSG__DETAIL__SLOT__BUILDER_HPP_
