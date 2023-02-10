// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ma_interfaces:msg/AuctionMsg.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__MSG__DETAIL__AUCTION_MSG__TRAITS_HPP_
#define MA_INTERFACES__MSG__DETAIL__AUCTION_MSG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ma_interfaces/msg/detail/auction_msg__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'graph'
#include "ma_interfaces/msg/detail/node__traits.hpp"

namespace ma_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const AuctionMsg & msg,
  std::ostream & out)
{
  out << "{";
  // member: graph
  {
    if (msg.graph.size() == 0) {
      out << "graph: []";
    } else {
      out << "graph: [";
      size_t pending_items = msg.graph.size();
      for (auto item : msg.graph) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AuctionMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: graph
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.graph.size() == 0) {
      out << "graph: []\n";
    } else {
      out << "graph:\n";
      for (auto item : msg.graph) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AuctionMsg & msg, bool use_flow_style = false)
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
  const ma_interfaces::msg::AuctionMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  ma_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ma_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const ma_interfaces::msg::AuctionMsg & msg)
{
  return ma_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ma_interfaces::msg::AuctionMsg>()
{
  return "ma_interfaces::msg::AuctionMsg";
}

template<>
inline const char * name<ma_interfaces::msg::AuctionMsg>()
{
  return "ma_interfaces/msg/AuctionMsg";
}

template<>
struct has_fixed_size<ma_interfaces::msg::AuctionMsg>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ma_interfaces::msg::AuctionMsg>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ma_interfaces::msg::AuctionMsg>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MA_INTERFACES__MSG__DETAIL__AUCTION_MSG__TRAITS_HPP_
