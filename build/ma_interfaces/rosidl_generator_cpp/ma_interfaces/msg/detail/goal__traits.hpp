// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ma_interfaces:msg/Goal.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__MSG__DETAIL__GOAL__TRAITS_HPP_
#define MA_INTERFACES__MSG__DETAIL__GOAL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ma_interfaces/msg/detail/goal__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ma_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Goal & msg,
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

  // member: num_agents
  {
    out << "num_agents: ";
    rosidl_generator_traits::value_to_yaml(msg.num_agents, out);
    out << ", ";
  }

  // member: duration
  {
    out << "duration: ";
    rosidl_generator_traits::value_to_yaml(msg.duration, out);
    out << ", ";
  }

  // member: execution_range
  {
    out << "execution_range: ";
    rosidl_generator_traits::value_to_yaml(msg.execution_range, out);
    out << ", ";
  }

  // member: deadline
  {
    out << "deadline: ";
    rosidl_generator_traits::value_to_yaml(msg.deadline, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Goal & msg,
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

  // member: num_agents
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "num_agents: ";
    rosidl_generator_traits::value_to_yaml(msg.num_agents, out);
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

  // member: execution_range
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "execution_range: ";
    rosidl_generator_traits::value_to_yaml(msg.execution_range, out);
    out << "\n";
  }

  // member: deadline
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "deadline: ";
    rosidl_generator_traits::value_to_yaml(msg.deadline, out);
    out << "\n";
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Goal & msg, bool use_flow_style = false)
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
  const ma_interfaces::msg::Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  ma_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ma_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const ma_interfaces::msg::Goal & msg)
{
  return ma_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ma_interfaces::msg::Goal>()
{
  return "ma_interfaces::msg::Goal";
}

template<>
inline const char * name<ma_interfaces::msg::Goal>()
{
  return "ma_interfaces/msg/Goal";
}

template<>
struct has_fixed_size<ma_interfaces::msg::Goal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ma_interfaces::msg::Goal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ma_interfaces::msg::Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MA_INTERFACES__MSG__DETAIL__GOAL__TRAITS_HPP_
