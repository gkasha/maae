// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ma_interfaces:srv/GetGoal.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__SRV__DETAIL__GET_GOAL__TRAITS_HPP_
#define MA_INTERFACES__SRV__DETAIL__GET_GOAL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ma_interfaces/srv/detail/get_goal__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ma_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetGoal_Request & msg,
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace ma_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use ma_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ma_interfaces::srv::GetGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  ma_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ma_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const ma_interfaces::srv::GetGoal_Request & msg)
{
  return ma_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ma_interfaces::srv::GetGoal_Request>()
{
  return "ma_interfaces::srv::GetGoal_Request";
}

template<>
inline const char * name<ma_interfaces::srv::GetGoal_Request>()
{
  return "ma_interfaces/srv/GetGoal_Request";
}

template<>
struct has_fixed_size<ma_interfaces::srv::GetGoal_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ma_interfaces::srv::GetGoal_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ma_interfaces::srv::GetGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'g'
#include "ma_interfaces/msg/detail/goal__traits.hpp"

namespace ma_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: g
  {
    out << "g: ";
    to_flow_style_yaml(msg.g, out);
    out << ", ";
  }

  // member: num_agents
  {
    out << "num_agents: ";
    rosidl_generator_traits::value_to_yaml(msg.num_agents, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: g
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "g:\n";
    to_block_style_yaml(msg.g, out, indentation + 2);
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace ma_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use ma_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ma_interfaces::srv::GetGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  ma_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ma_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const ma_interfaces::srv::GetGoal_Response & msg)
{
  return ma_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ma_interfaces::srv::GetGoal_Response>()
{
  return "ma_interfaces::srv::GetGoal_Response";
}

template<>
inline const char * name<ma_interfaces::srv::GetGoal_Response>()
{
  return "ma_interfaces/srv/GetGoal_Response";
}

template<>
struct has_fixed_size<ma_interfaces::srv::GetGoal_Response>
  : std::integral_constant<bool, has_fixed_size<ma_interfaces::msg::Goal>::value> {};

template<>
struct has_bounded_size<ma_interfaces::srv::GetGoal_Response>
  : std::integral_constant<bool, has_bounded_size<ma_interfaces::msg::Goal>::value> {};

template<>
struct is_message<ma_interfaces::srv::GetGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<ma_interfaces::srv::GetGoal>()
{
  return "ma_interfaces::srv::GetGoal";
}

template<>
inline const char * name<ma_interfaces::srv::GetGoal>()
{
  return "ma_interfaces/srv/GetGoal";
}

template<>
struct has_fixed_size<ma_interfaces::srv::GetGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<ma_interfaces::srv::GetGoal_Request>::value &&
    has_fixed_size<ma_interfaces::srv::GetGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<ma_interfaces::srv::GetGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<ma_interfaces::srv::GetGoal_Request>::value &&
    has_bounded_size<ma_interfaces::srv::GetGoal_Response>::value
  >
{
};

template<>
struct is_service<ma_interfaces::srv::GetGoal>
  : std::true_type
{
};

template<>
struct is_service_request<ma_interfaces::srv::GetGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<ma_interfaces::srv::GetGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MA_INTERFACES__SRV__DETAIL__GET_GOAL__TRAITS_HPP_
