// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ma_interfaces:srv/Register.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__SRV__DETAIL__REGISTER__BUILDER_HPP_
#define MA_INTERFACES__SRV__DETAIL__REGISTER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ma_interfaces/srv/detail/register__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ma_interfaces
{

namespace srv
{

namespace builder
{

class Init_Register_Request_id
{
public:
  Init_Register_Request_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ma_interfaces::srv::Register_Request id(::ma_interfaces::srv::Register_Request::_id_type arg)
  {
    msg_.id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ma_interfaces::srv::Register_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ma_interfaces::srv::Register_Request>()
{
  return ma_interfaces::srv::builder::Init_Register_Request_id();
}

}  // namespace ma_interfaces


namespace ma_interfaces
{

namespace srv
{

namespace builder
{

class Init_Register_Response_status
{
public:
  Init_Register_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ma_interfaces::srv::Register_Response status(::ma_interfaces::srv::Register_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ma_interfaces::srv::Register_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ma_interfaces::srv::Register_Response>()
{
  return ma_interfaces::srv::builder::Init_Register_Response_status();
}

}  // namespace ma_interfaces

#endif  // MA_INTERFACES__SRV__DETAIL__REGISTER__BUILDER_HPP_
