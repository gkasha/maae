// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ma_interfaces:srv/AuctionSrv.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__SRV__DETAIL__AUCTION_SRV__TRAITS_HPP_
#define MA_INTERFACES__SRV__DETAIL__AUCTION_SRV__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ma_interfaces/srv/detail/auction_srv__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ma_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const AuctionSrv_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AuctionSrv_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AuctionSrv_Request & msg, bool use_flow_style = false)
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
  const ma_interfaces::srv::AuctionSrv_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  ma_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ma_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const ma_interfaces::srv::AuctionSrv_Request & msg)
{
  return ma_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ma_interfaces::srv::AuctionSrv_Request>()
{
  return "ma_interfaces::srv::AuctionSrv_Request";
}

template<>
inline const char * name<ma_interfaces::srv::AuctionSrv_Request>()
{
  return "ma_interfaces/srv/AuctionSrv_Request";
}

template<>
struct has_fixed_size<ma_interfaces::srv::AuctionSrv_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ma_interfaces::srv::AuctionSrv_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ma_interfaces::srv::AuctionSrv_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace ma_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const AuctionSrv_Response & msg,
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
  const AuctionSrv_Response & msg,
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

inline std::string to_yaml(const AuctionSrv_Response & msg, bool use_flow_style = false)
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
  const ma_interfaces::srv::AuctionSrv_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  ma_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ma_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const ma_interfaces::srv::AuctionSrv_Response & msg)
{
  return ma_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ma_interfaces::srv::AuctionSrv_Response>()
{
  return "ma_interfaces::srv::AuctionSrv_Response";
}

template<>
inline const char * name<ma_interfaces::srv::AuctionSrv_Response>()
{
  return "ma_interfaces/srv/AuctionSrv_Response";
}

template<>
struct has_fixed_size<ma_interfaces::srv::AuctionSrv_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ma_interfaces::srv::AuctionSrv_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ma_interfaces::srv::AuctionSrv_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<ma_interfaces::srv::AuctionSrv>()
{
  return "ma_interfaces::srv::AuctionSrv";
}

template<>
inline const char * name<ma_interfaces::srv::AuctionSrv>()
{
  return "ma_interfaces/srv/AuctionSrv";
}

template<>
struct has_fixed_size<ma_interfaces::srv::AuctionSrv>
  : std::integral_constant<
    bool,
    has_fixed_size<ma_interfaces::srv::AuctionSrv_Request>::value &&
    has_fixed_size<ma_interfaces::srv::AuctionSrv_Response>::value
  >
{
};

template<>
struct has_bounded_size<ma_interfaces::srv::AuctionSrv>
  : std::integral_constant<
    bool,
    has_bounded_size<ma_interfaces::srv::AuctionSrv_Request>::value &&
    has_bounded_size<ma_interfaces::srv::AuctionSrv_Response>::value
  >
{
};

template<>
struct is_service<ma_interfaces::srv::AuctionSrv>
  : std::true_type
{
};

template<>
struct is_service_request<ma_interfaces::srv::AuctionSrv_Request>
  : std::true_type
{
};

template<>
struct is_service_response<ma_interfaces::srv::AuctionSrv_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MA_INTERFACES__SRV__DETAIL__AUCTION_SRV__TRAITS_HPP_
