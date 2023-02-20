// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ma_interfaces:msg/ActionFeedback.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__MSG__DETAIL__ACTION_FEEDBACK__TRAITS_HPP_
#define MA_INTERFACES__MSG__DETAIL__ACTION_FEEDBACK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ma_interfaces/msg/detail/action_feedback__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ma_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ActionFeedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: action_id
  {
    out << "action_id: ";
    rosidl_generator_traits::value_to_yaml(msg.action_id, out);
    out << ", ";
  }

  // member: agent_id
  {
    out << "agent_id: ";
    rosidl_generator_traits::value_to_yaml(msg.agent_id, out);
    out << ", ";
  }

  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: st
  {
    out << "st: ";
    rosidl_generator_traits::value_to_yaml(msg.st, out);
    out << ", ";
  }

  // member: action_started
  {
    out << "action_started: ";
    rosidl_generator_traits::value_to_yaml(msg.action_started, out);
    out << ", ";
  }

  // member: action_completed
  {
    out << "action_completed: ";
    rosidl_generator_traits::value_to_yaml(msg.action_completed, out);
    out << ", ";
  }

  // member: action_failed
  {
    out << "action_failed: ";
    rosidl_generator_traits::value_to_yaml(msg.action_failed, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ActionFeedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: action_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "action_id: ";
    rosidl_generator_traits::value_to_yaml(msg.action_id, out);
    out << "\n";
  }

  // member: agent_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "agent_id: ";
    rosidl_generator_traits::value_to_yaml(msg.agent_id, out);
    out << "\n";
  }

  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
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

  // member: action_started
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "action_started: ";
    rosidl_generator_traits::value_to_yaml(msg.action_started, out);
    out << "\n";
  }

  // member: action_completed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "action_completed: ";
    rosidl_generator_traits::value_to_yaml(msg.action_completed, out);
    out << "\n";
  }

  // member: action_failed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "action_failed: ";
    rosidl_generator_traits::value_to_yaml(msg.action_failed, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ActionFeedback & msg, bool use_flow_style = false)
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
  const ma_interfaces::msg::ActionFeedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  ma_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ma_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const ma_interfaces::msg::ActionFeedback & msg)
{
  return ma_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ma_interfaces::msg::ActionFeedback>()
{
  return "ma_interfaces::msg::ActionFeedback";
}

template<>
inline const char * name<ma_interfaces::msg::ActionFeedback>()
{
  return "ma_interfaces/msg/ActionFeedback";
}

template<>
struct has_fixed_size<ma_interfaces::msg::ActionFeedback>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ma_interfaces::msg::ActionFeedback>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ma_interfaces::msg::ActionFeedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MA_INTERFACES__MSG__DETAIL__ACTION_FEEDBACK__TRAITS_HPP_
