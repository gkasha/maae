// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ma_interfaces:srv/AuctionResult.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__SRV__DETAIL__AUCTION_RESULT__STRUCT_HPP_
#define MA_INTERFACES__SRV__DETAIL__AUCTION_RESULT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 't'
#include "ma_interfaces/msg/detail/task__struct.hpp"
// Member 'b'
#include "ma_interfaces/msg/detail/bid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__ma_interfaces__srv__AuctionResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__ma_interfaces__srv__AuctionResult_Request __declspec(deprecated)
#endif

namespace ma_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct AuctionResult_Request_
{
  using Type = AuctionResult_Request_<ContainerAllocator>;

  explicit AuctionResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : t(_init),
    b(_init)
  {
    (void)_init;
  }

  explicit AuctionResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : t(_alloc, _init),
    b(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _t_type =
    ma_interfaces::msg::Task_<ContainerAllocator>;
  _t_type t;
  using _b_type =
    ma_interfaces::msg::Bid_<ContainerAllocator>;
  _b_type b;

  // setters for named parameter idiom
  Type & set__t(
    const ma_interfaces::msg::Task_<ContainerAllocator> & _arg)
  {
    this->t = _arg;
    return *this;
  }
  Type & set__b(
    const ma_interfaces::msg::Bid_<ContainerAllocator> & _arg)
  {
    this->b = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ma_interfaces::srv::AuctionResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const ma_interfaces::srv::AuctionResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ma_interfaces::srv::AuctionResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ma_interfaces::srv::AuctionResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ma_interfaces::srv::AuctionResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ma_interfaces::srv::AuctionResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ma_interfaces::srv::AuctionResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ma_interfaces::srv::AuctionResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ma_interfaces::srv::AuctionResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ma_interfaces::srv::AuctionResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ma_interfaces__srv__AuctionResult_Request
    std::shared_ptr<ma_interfaces::srv::AuctionResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ma_interfaces__srv__AuctionResult_Request
    std::shared_ptr<ma_interfaces::srv::AuctionResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AuctionResult_Request_ & other) const
  {
    if (this->t != other.t) {
      return false;
    }
    if (this->b != other.b) {
      return false;
    }
    return true;
  }
  bool operator!=(const AuctionResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AuctionResult_Request_

// alias to use template instance with default allocator
using AuctionResult_Request =
  ma_interfaces::srv::AuctionResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ma_interfaces


#ifndef _WIN32
# define DEPRECATED__ma_interfaces__srv__AuctionResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__ma_interfaces__srv__AuctionResult_Response __declspec(deprecated)
#endif

namespace ma_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct AuctionResult_Response_
{
  using Type = AuctionResult_Response_<ContainerAllocator>;

  explicit AuctionResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit AuctionResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    ma_interfaces::srv::AuctionResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const ma_interfaces::srv::AuctionResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ma_interfaces::srv::AuctionResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ma_interfaces::srv::AuctionResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ma_interfaces::srv::AuctionResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ma_interfaces::srv::AuctionResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ma_interfaces::srv::AuctionResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ma_interfaces::srv::AuctionResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ma_interfaces::srv::AuctionResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ma_interfaces::srv::AuctionResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ma_interfaces__srv__AuctionResult_Response
    std::shared_ptr<ma_interfaces::srv::AuctionResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ma_interfaces__srv__AuctionResult_Response
    std::shared_ptr<ma_interfaces::srv::AuctionResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AuctionResult_Response_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const AuctionResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AuctionResult_Response_

// alias to use template instance with default allocator
using AuctionResult_Response =
  ma_interfaces::srv::AuctionResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ma_interfaces

namespace ma_interfaces
{

namespace srv
{

struct AuctionResult
{
  using Request = ma_interfaces::srv::AuctionResult_Request;
  using Response = ma_interfaces::srv::AuctionResult_Response;
};

}  // namespace srv

}  // namespace ma_interfaces

#endif  // MA_INTERFACES__SRV__DETAIL__AUCTION_RESULT__STRUCT_HPP_
