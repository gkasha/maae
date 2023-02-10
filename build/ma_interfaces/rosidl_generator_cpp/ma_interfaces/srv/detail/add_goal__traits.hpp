// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ma_interfaces:srv/AddGoal.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__SRV__DETAIL__ADD_GOAL__TRAITS_HPP_
#define MA_INTERFACES__SRV__DETAIL__ADD_GOAL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ma_interfaces/srv/detail/add_goal__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'g'
#include "ma_interfaces/msg/detail/goal__traits.hpp"

namespace ma_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const AddGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: g
  {
    out << "g: ";
    to_flow_style_yaml(msg.g, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AddGoal_Request & msg,
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AddGoal_Request & msg, bool use_flow_style = false)
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
  const ma_interfaces::srv::AddGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  ma_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ma_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const ma_interfaces::srv::AddGoal_Request & msg)
{
  return ma_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ma_interfaces::srv::AddGoal_Request>()
{
  return "ma_interfaces::srv::AddGoal_Request";
}

template<>
inline const char * name<ma_interfaces::srv::AddGoal_Request>()
{
  return "ma_interfaces/srv/AddGoal_Request";
}

template<>
struct has_fixed_size<ma_interfaces::srv::AddGoal_Request>
  : std::integral_constant<bool, has_fixed_size<ma_interfaces::msg::Goal>::value> {};

template<>
struct has_bounded_size<ma_interfaces::srv::AddGoal_Request>
  : std::integral_constant<bool, has_bounded_size<ma_interfaces::msg::Goal>::value> {};

template<>
struct is_message<ma_interfaces::srv::AddGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace ma_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const AddGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AddGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AddGoal_Response & msg, bool use_flow_style = false)
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
  const ma_interfaces::srv::AddGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  ma_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ma_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const ma_interfaces::srv::AddGoal_Response & msg)
{
  return ma_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ma_interfaces::srv::AddGoal_Response>()
{
  return "ma_interfaces::srv::AddGoal_Response";
}

template<>
inline const char * name<ma_interfaces::srv::AddGoal_Response>()
{
  return "ma_interfaces/srv/AddGoal_Response";
}

template<>
struct has_fixed_size<ma_interfaces::srv::AddGoal_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ma_interfaces::srv::AddGoal_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ma_interfaces::srv::AddGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<ma_interfaces::srv::AddGoal>()
{
  return "ma_interfaces::srv::AddGoal";
}

template<>
inline const char * name<ma_interfaces::srv::AddGoal>()
{
  return "ma_interfaces/srv/AddGoal";
}

template<>
struct has_fixed_size<ma_interfaces::srv::AddGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<ma_interfaces::srv::AddGoal_Request>::value &&
    has_fixed_size<ma_interfaces::srv::AddGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<ma_interfaces::srv::AddGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<ma_interfaces::srv::AddGoal_Request>::value &&
    has_bounded_size<ma_interfaces::srv::AddGoal_Response>::value
  >
{
};

template<>
struct is_service<ma_interfaces::srv::AddGoal>
  : std::true_type
{
};

template<>
struct is_service_request<ma_interfaces::srv::AddGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<ma_interfaces::srv::AddGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MA_INTERFACES__SRV__DETAIL__ADD_GOAL__TRAITS_HPP_
