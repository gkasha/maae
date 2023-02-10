// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ma_interfaces:srv/AuctionResult.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__SRV__DETAIL__AUCTION_RESULT__TRAITS_HPP_
#define MA_INTERFACES__SRV__DETAIL__AUCTION_RESULT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ma_interfaces/srv/detail/auction_result__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 't'
#include "ma_interfaces/msg/detail/task__traits.hpp"
// Member 'b'
#include "ma_interfaces/msg/detail/bid__traits.hpp"

namespace ma_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const AuctionResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: t
  {
    out << "t: ";
    to_flow_style_yaml(msg.t, out);
    out << ", ";
  }

  // member: b
  {
    out << "b: ";
    to_flow_style_yaml(msg.b, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AuctionResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: t
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "t:\n";
    to_block_style_yaml(msg.t, out, indentation + 2);
  }

  // member: b
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "b:\n";
    to_block_style_yaml(msg.b, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AuctionResult_Request & msg, bool use_flow_style = false)
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
  const ma_interfaces::srv::AuctionResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  ma_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ma_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const ma_interfaces::srv::AuctionResult_Request & msg)
{
  return ma_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ma_interfaces::srv::AuctionResult_Request>()
{
  return "ma_interfaces::srv::AuctionResult_Request";
}

template<>
inline const char * name<ma_interfaces::srv::AuctionResult_Request>()
{
  return "ma_interfaces/srv/AuctionResult_Request";
}

template<>
struct has_fixed_size<ma_interfaces::srv::AuctionResult_Request>
  : std::integral_constant<bool, has_fixed_size<ma_interfaces::msg::Bid>::value && has_fixed_size<ma_interfaces::msg::Task>::value> {};

template<>
struct has_bounded_size<ma_interfaces::srv::AuctionResult_Request>
  : std::integral_constant<bool, has_bounded_size<ma_interfaces::msg::Bid>::value && has_bounded_size<ma_interfaces::msg::Task>::value> {};

template<>
struct is_message<ma_interfaces::srv::AuctionResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace ma_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const AuctionResult_Response & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AuctionResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AuctionResult_Response & msg, bool use_flow_style = false)
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
  const ma_interfaces::srv::AuctionResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  ma_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ma_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const ma_interfaces::srv::AuctionResult_Response & msg)
{
  return ma_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ma_interfaces::srv::AuctionResult_Response>()
{
  return "ma_interfaces::srv::AuctionResult_Response";
}

template<>
inline const char * name<ma_interfaces::srv::AuctionResult_Response>()
{
  return "ma_interfaces/srv/AuctionResult_Response";
}

template<>
struct has_fixed_size<ma_interfaces::srv::AuctionResult_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ma_interfaces::srv::AuctionResult_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ma_interfaces::srv::AuctionResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<ma_interfaces::srv::AuctionResult>()
{
  return "ma_interfaces::srv::AuctionResult";
}

template<>
inline const char * name<ma_interfaces::srv::AuctionResult>()
{
  return "ma_interfaces/srv/AuctionResult";
}

template<>
struct has_fixed_size<ma_interfaces::srv::AuctionResult>
  : std::integral_constant<
    bool,
    has_fixed_size<ma_interfaces::srv::AuctionResult_Request>::value &&
    has_fixed_size<ma_interfaces::srv::AuctionResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<ma_interfaces::srv::AuctionResult>
  : std::integral_constant<
    bool,
    has_bounded_size<ma_interfaces::srv::AuctionResult_Request>::value &&
    has_bounded_size<ma_interfaces::srv::AuctionResult_Response>::value
  >
{
};

template<>
struct is_service<ma_interfaces::srv::AuctionResult>
  : std::true_type
{
};

template<>
struct is_service_request<ma_interfaces::srv::AuctionResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<ma_interfaces::srv::AuctionResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MA_INTERFACES__SRV__DETAIL__AUCTION_RESULT__TRAITS_HPP_
