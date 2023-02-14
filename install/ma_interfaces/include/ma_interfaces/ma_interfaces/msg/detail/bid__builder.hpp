// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ma_interfaces:msg/Bid.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__MSG__DETAIL__BID__BUILDER_HPP_
#define MA_INTERFACES__MSG__DETAIL__BID__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ma_interfaces/msg/detail/bid__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ma_interfaces
{

namespace msg
{

namespace builder
{

class Init_Bid_value
{
public:
  explicit Init_Bid_value(::ma_interfaces::msg::Bid & msg)
  : msg_(msg)
  {}
  ::ma_interfaces::msg::Bid value(::ma_interfaces::msg::Bid::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ma_interfaces::msg::Bid msg_;
};

class Init_Bid_et
{
public:
  explicit Init_Bid_et(::ma_interfaces::msg::Bid & msg)
  : msg_(msg)
  {}
  Init_Bid_value et(::ma_interfaces::msg::Bid::_et_type arg)
  {
    msg_.et = std::move(arg);
    return Init_Bid_value(msg_);
  }

private:
  ::ma_interfaces::msg::Bid msg_;
};

class Init_Bid_st
{
public:
  explicit Init_Bid_st(::ma_interfaces::msg::Bid & msg)
  : msg_(msg)
  {}
  Init_Bid_et st(::ma_interfaces::msg::Bid::_st_type arg)
  {
    msg_.st = std::move(arg);
    return Init_Bid_et(msg_);
  }

private:
  ::ma_interfaces::msg::Bid msg_;
};

class Init_Bid_auction_id
{
public:
  explicit Init_Bid_auction_id(::ma_interfaces::msg::Bid & msg)
  : msg_(msg)
  {}
  Init_Bid_st auction_id(::ma_interfaces::msg::Bid::_auction_id_type arg)
  {
    msg_.auction_id = std::move(arg);
    return Init_Bid_st(msg_);
  }

private:
  ::ma_interfaces::msg::Bid msg_;
};

class Init_Bid_agent_id
{
public:
  Init_Bid_agent_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Bid_auction_id agent_id(::ma_interfaces::msg::Bid::_agent_id_type arg)
  {
    msg_.agent_id = std::move(arg);
    return Init_Bid_auction_id(msg_);
  }

private:
  ::ma_interfaces::msg::Bid msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ma_interfaces::msg::Bid>()
{
  return ma_interfaces::msg::builder::Init_Bid_agent_id();
}

}  // namespace ma_interfaces

#endif  // MA_INTERFACES__MSG__DETAIL__BID__BUILDER_HPP_
