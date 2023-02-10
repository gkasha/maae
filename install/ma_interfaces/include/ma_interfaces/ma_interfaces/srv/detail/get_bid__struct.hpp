// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ma_interfaces:srv/GetBid.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__SRV__DETAIL__GET_BID__STRUCT_HPP_
#define MA_INTERFACES__SRV__DETAIL__GET_BID__STRUCT_HPP_

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

#ifndef _WIN32
# define DEPRECATED__ma_interfaces__srv__GetBid_Request __attribute__((deprecated))
#else
# define DEPRECATED__ma_interfaces__srv__GetBid_Request __declspec(deprecated)
#endif

namespace ma_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetBid_Request_
{
  using Type = GetBid_Request_<ContainerAllocator>;

  explicit GetBid_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : t(_init)
  {
    (void)_init;
  }

  explicit GetBid_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : t(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _t_type =
    ma_interfaces::msg::Task_<ContainerAllocator>;
  _t_type t;

  // setters for named parameter idiom
  Type & set__t(
    const ma_interfaces::msg::Task_<ContainerAllocator> & _arg)
  {
    this->t = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ma_interfaces::srv::GetBid_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const ma_interfaces::srv::GetBid_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ma_interfaces::srv::GetBid_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ma_interfaces::srv::GetBid_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ma_interfaces::srv::GetBid_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ma_interfaces::srv::GetBid_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ma_interfaces::srv::GetBid_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ma_interfaces::srv::GetBid_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ma_interfaces::srv::GetBid_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ma_interfaces::srv::GetBid_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ma_interfaces__srv__GetBid_Request
    std::shared_ptr<ma_interfaces::srv::GetBid_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ma_interfaces__srv__GetBid_Request
    std::shared_ptr<ma_interfaces::srv::GetBid_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetBid_Request_ & other) const
  {
    if (this->t != other.t) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetBid_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetBid_Request_

// alias to use template instance with default allocator
using GetBid_Request =
  ma_interfaces::srv::GetBid_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ma_interfaces


// Include directives for member types
// Member 'b'
#include "ma_interfaces/msg/detail/bid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__ma_interfaces__srv__GetBid_Response __attribute__((deprecated))
#else
# define DEPRECATED__ma_interfaces__srv__GetBid_Response __declspec(deprecated)
#endif

namespace ma_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetBid_Response_
{
  using Type = GetBid_Response_<ContainerAllocator>;

  explicit GetBid_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : b(_init)
  {
    (void)_init;
  }

  explicit GetBid_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : b(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _b_type =
    ma_interfaces::msg::Bid_<ContainerAllocator>;
  _b_type b;

  // setters for named parameter idiom
  Type & set__b(
    const ma_interfaces::msg::Bid_<ContainerAllocator> & _arg)
  {
    this->b = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ma_interfaces::srv::GetBid_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const ma_interfaces::srv::GetBid_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ma_interfaces::srv::GetBid_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ma_interfaces::srv::GetBid_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ma_interfaces::srv::GetBid_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ma_interfaces::srv::GetBid_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ma_interfaces::srv::GetBid_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ma_interfaces::srv::GetBid_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ma_interfaces::srv::GetBid_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ma_interfaces::srv::GetBid_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ma_interfaces__srv__GetBid_Response
    std::shared_ptr<ma_interfaces::srv::GetBid_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ma_interfaces__srv__GetBid_Response
    std::shared_ptr<ma_interfaces::srv::GetBid_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetBid_Response_ & other) const
  {
    if (this->b != other.b) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetBid_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetBid_Response_

// alias to use template instance with default allocator
using GetBid_Response =
  ma_interfaces::srv::GetBid_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ma_interfaces

namespace ma_interfaces
{

namespace srv
{

struct GetBid
{
  using Request = ma_interfaces::srv::GetBid_Request;
  using Response = ma_interfaces::srv::GetBid_Response;
};

}  // namespace srv

}  // namespace ma_interfaces

#endif  // MA_INTERFACES__SRV__DETAIL__GET_BID__STRUCT_HPP_
