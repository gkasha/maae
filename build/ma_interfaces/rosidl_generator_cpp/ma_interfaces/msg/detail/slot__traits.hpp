// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ma_interfaces:msg/Slot.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__MSG__DETAIL__SLOT__TRAITS_HPP_
#define MA_INTERFACES__MSG__DETAIL__SLOT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ma_interfaces/msg/detail/slot__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ma_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Slot & msg,
  std::ostream & out)
{
  out << "{";
  // member: agent_id
  {
    out << "agent_id: ";
    rosidl_generator_traits::value_to_yaml(msg.agent_id, out);
    out << ", ";
  }

  // member: owner_id
  {
    out << "owner_id: ";
    rosidl_generator_traits::value_to_yaml(msg.owner_id, out);
    out << ", ";
  }

  // member: task_id
  {
    out << "task_id: ";
    rosidl_generator_traits::value_to_yaml(msg.task_id, out);
    out << ", ";
  }

  // member: st
  {
    out << "st: ";
    rosidl_generator_traits::value_to_yaml(msg.st, out);
    out << ", ";
  }

  // member: et
  {
    out << "et: ";
    rosidl_generator_traits::value_to_yaml(msg.et, out);
    out << ", ";
  }

  // member: x1
  {
    out << "x1: ";
    rosidl_generator_traits::value_to_yaml(msg.x1, out);
    out << ", ";
  }

  // member: y1
  {
    out << "y1: ";
    rosidl_generator_traits::value_to_yaml(msg.y1, out);
    out << ", ";
  }

  // member: x2
  {
    out << "x2: ";
    rosidl_generator_traits::value_to_yaml(msg.x2, out);
    out << ", ";
  }

  // member: y2
  {
    out << "y2: ";
    rosidl_generator_traits::value_to_yaml(msg.y2, out);
    out << ", ";
  }

  // member: speed
  {
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Slot & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: agent_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "agent_id: ";
    rosidl_generator_traits::value_to_yaml(msg.agent_id, out);
    out << "\n";
  }

  // member: owner_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "owner_id: ";
    rosidl_generator_traits::value_to_yaml(msg.owner_id, out);
    out << "\n";
  }

  // member: task_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task_id: ";
    rosidl_generator_traits::value_to_yaml(msg.task_id, out);
    out << "\n";
  }

  // member: st
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "st: ";
    rosidl_generator_traits::value_to_yaml(msg.st, out);
    out << "\n";
  }

  // member: et
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "et: ";
    rosidl_generator_traits::value_to_yaml(msg.et, out);
    out << "\n";
  }

  // member: x1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x1: ";
    rosidl_generator_traits::value_to_yaml(msg.x1, out);
    out << "\n";
  }

  // member: y1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y1: ";
    rosidl_generator_traits::value_to_yaml(msg.y1, out);
    out << "\n";
  }

  // member: x2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x2: ";
    rosidl_generator_traits::value_to_yaml(msg.x2, out);
    out << "\n";
  }

  // member: y2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y2: ";
    rosidl_generator_traits::value_to_yaml(msg.y2, out);
    out << "\n";
  }

  // member: speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Slot & msg, bool use_flow_style = false)
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
  const ma_interfaces::msg::Slot & msg,
  std::ostream & out, size_t indentation = 0)
{
  ma_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ma_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const ma_interfaces::msg::Slot & msg)
{
  return ma_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ma_interfaces::msg::Slot>()
{
  return "ma_interfaces::msg::Slot";
}

template<>
inline const char * name<ma_interfaces::msg::Slot>()
{
  return "ma_interfaces/msg/Slot";
}

template<>
struct has_fixed_size<ma_interfaces::msg::Slot>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ma_interfaces::msg::Slot>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ma_interfaces::msg::Slot>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MA_INTERFACES__MSG__DETAIL__SLOT__TRAITS_HPP_
