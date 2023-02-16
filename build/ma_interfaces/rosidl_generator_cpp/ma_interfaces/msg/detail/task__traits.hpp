// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ma_interfaces:msg/Task.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__MSG__DETAIL__TASK__TRAITS_HPP_
#define MA_INTERFACES__MSG__DETAIL__TASK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ma_interfaces/msg/detail/task__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ma_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Task & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: owner
  {
    out << "owner: ";
    rosidl_generator_traits::value_to_yaml(msg.owner, out);
    out << ", ";
  }

  // member: duration
  {
    out << "duration: ";
    rosidl_generator_traits::value_to_yaml(msg.duration, out);
    out << ", ";
  }

  // member: value
  {
    out << "value: ";
    rosidl_generator_traits::value_to_yaml(msg.value, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Task & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: owner
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "owner: ";
    rosidl_generator_traits::value_to_yaml(msg.owner, out);
    out << "\n";
  }

  // member: duration
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "duration: ";
    rosidl_generator_traits::value_to_yaml(msg.duration, out);
    out << "\n";
  }

  // member: value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "value: ";
    rosidl_generator_traits::value_to_yaml(msg.value, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Task & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace ma_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use ma_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ma_interfaces::msg::Task & msg,
  std::ostream & out, size_t indentation = 0)
{
  ma_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ma_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const ma_interfaces::msg::Task & msg)
{
  return ma_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ma_interfaces::msg::Task>()
{
  return "ma_interfaces::msg::Task";
}

template<>
inline const char * name<ma_interfaces::msg::Task>()
{
  return "ma_interfaces/msg/Task";
}

template<>
struct has_fixed_size<ma_interfaces::msg::Task>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ma_interfaces::msg::Task>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ma_interfaces::msg::Task>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MA_INTERFACES__MSG__DETAIL__TASK__TRAITS_HPP_
