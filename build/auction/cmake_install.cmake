# Install script for directory: /home/gkasha/Documents/maae/src/auction

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/gkasha/Documents/maae/install/auction")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/auction/" TYPE DIRECTORY FILES "/home/gkasha/Documents/maae/src/auction/include/auction/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/auction/execution_interface" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/auction/execution_interface")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/auction/execution_interface"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/auction" TYPE EXECUTABLE FILES "/home/gkasha/Documents/maae/build/auction/execution_interface")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/auction/execution_interface" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/auction/execution_interface")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/auction/execution_interface"
         OLD_RPATH "/home/gkasha/ros2_humble/install/rclcpp/lib:/home/gkasha/Documents/maae/install/ma_interfaces/lib:/home/gkasha/ros2_humble/install/std_msgs/lib:/home/gkasha/ros2_humble/install/libstatistics_collector/lib:/home/gkasha/ros2_humble/install/rcl/lib:/home/gkasha/ros2_humble/install/rmw_implementation/lib:/home/gkasha/ros2_humble/install/ament_index_cpp/lib:/home/gkasha/ros2_humble/install/rcl_logging_spdlog/lib:/home/gkasha/ros2_humble/install/rcl_logging_interface/lib:/home/gkasha/ros2_humble/install/rcl_interfaces/lib:/home/gkasha/ros2_humble/install/rcl_yaml_param_parser/lib:/home/gkasha/ros2_humble/install/libyaml_vendor/lib:/home/gkasha/ros2_humble/install/rosgraph_msgs/lib:/home/gkasha/ros2_humble/install/statistics_msgs/lib:/home/gkasha/ros2_humble/install/tracetools/lib:/home/gkasha/ros2_humble/install/builtin_interfaces/lib:/home/gkasha/ros2_humble/install/rosidl_typesupport_fastrtps_c/lib:/home/gkasha/ros2_humble/install/rosidl_typesupport_fastrtps_cpp/lib:/home/gkasha/ros2_humble/install/fastcdr/lib:/home/gkasha/ros2_humble/install/rmw/lib:/home/gkasha/ros2_humble/install/rosidl_typesupport_introspection_cpp/lib:/home/gkasha/ros2_humble/install/rosidl_typesupport_introspection_c/lib:/home/gkasha/ros2_humble/install/rosidl_typesupport_cpp/lib:/home/gkasha/ros2_humble/install/rosidl_typesupport_c/lib:/home/gkasha/ros2_humble/install/rcpputils/lib:/home/gkasha/ros2_humble/install/rosidl_runtime_c/lib:/home/gkasha/ros2_humble/install/rcutils/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/auction/execution_interface")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/auction/client" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/auction/client")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/auction/client"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/auction" TYPE EXECUTABLE FILES "/home/gkasha/Documents/maae/build/auction/client")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/auction/client" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/auction/client")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/auction/client"
         OLD_RPATH "/home/gkasha/ros2_humble/install/rclcpp/lib:/home/gkasha/Documents/maae/install/ma_interfaces/lib:/home/gkasha/ros2_humble/install/std_msgs/lib:/home/gkasha/ros2_humble/install/libstatistics_collector/lib:/home/gkasha/ros2_humble/install/rcl/lib:/home/gkasha/ros2_humble/install/rmw_implementation/lib:/home/gkasha/ros2_humble/install/ament_index_cpp/lib:/home/gkasha/ros2_humble/install/rcl_logging_spdlog/lib:/home/gkasha/ros2_humble/install/rcl_logging_interface/lib:/home/gkasha/ros2_humble/install/rcl_interfaces/lib:/home/gkasha/ros2_humble/install/rcl_yaml_param_parser/lib:/home/gkasha/ros2_humble/install/libyaml_vendor/lib:/home/gkasha/ros2_humble/install/rosgraph_msgs/lib:/home/gkasha/ros2_humble/install/statistics_msgs/lib:/home/gkasha/ros2_humble/install/tracetools/lib:/home/gkasha/ros2_humble/install/builtin_interfaces/lib:/home/gkasha/ros2_humble/install/rosidl_typesupport_fastrtps_c/lib:/home/gkasha/ros2_humble/install/rosidl_typesupport_fastrtps_cpp/lib:/home/gkasha/ros2_humble/install/fastcdr/lib:/home/gkasha/ros2_humble/install/rmw/lib:/home/gkasha/ros2_humble/install/rosidl_typesupport_introspection_cpp/lib:/home/gkasha/ros2_humble/install/rosidl_typesupport_introspection_c/lib:/home/gkasha/ros2_humble/install/rosidl_typesupport_cpp/lib:/home/gkasha/ros2_humble/install/rosidl_typesupport_c/lib:/home/gkasha/ros2_humble/install/rcpputils/lib:/home/gkasha/ros2_humble/install/rosidl_runtime_c/lib:/home/gkasha/ros2_humble/install/rcutils/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/auction/client")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/auction/agent" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/auction/agent")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/auction/agent"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/auction" TYPE EXECUTABLE FILES "/home/gkasha/Documents/maae/build/auction/agent")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/auction/agent" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/auction/agent")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/auction/agent"
         OLD_RPATH "/home/gkasha/ros2_humble/install/rclcpp/lib:/home/gkasha/Documents/maae/install/ma_interfaces/lib:/home/gkasha/ros2_humble/install/std_msgs/lib:/home/gkasha/ros2_humble/install/libstatistics_collector/lib:/home/gkasha/ros2_humble/install/rcl/lib:/home/gkasha/ros2_humble/install/rmw_implementation/lib:/home/gkasha/ros2_humble/install/ament_index_cpp/lib:/home/gkasha/ros2_humble/install/rcl_logging_spdlog/lib:/home/gkasha/ros2_humble/install/rcl_logging_interface/lib:/home/gkasha/ros2_humble/install/rcl_interfaces/lib:/home/gkasha/ros2_humble/install/rcl_yaml_param_parser/lib:/home/gkasha/ros2_humble/install/libyaml_vendor/lib:/home/gkasha/ros2_humble/install/rosgraph_msgs/lib:/home/gkasha/ros2_humble/install/statistics_msgs/lib:/home/gkasha/ros2_humble/install/tracetools/lib:/home/gkasha/ros2_humble/install/builtin_interfaces/lib:/home/gkasha/ros2_humble/install/rosidl_typesupport_fastrtps_c/lib:/home/gkasha/ros2_humble/install/rosidl_typesupport_fastrtps_cpp/lib:/home/gkasha/ros2_humble/install/fastcdr/lib:/home/gkasha/ros2_humble/install/rmw/lib:/home/gkasha/ros2_humble/install/rosidl_typesupport_introspection_cpp/lib:/home/gkasha/ros2_humble/install/rosidl_typesupport_introspection_c/lib:/home/gkasha/ros2_humble/install/rosidl_typesupport_cpp/lib:/home/gkasha/ros2_humble/install/rosidl_typesupport_c/lib:/home/gkasha/ros2_humble/install/rcpputils/lib:/home/gkasha/ros2_humble/install/rosidl_runtime_c/lib:/home/gkasha/ros2_humble/install/rcutils/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/auction/agent")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/auction/goal_manager" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/auction/goal_manager")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/auction/goal_manager"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/auction" TYPE EXECUTABLE FILES "/home/gkasha/Documents/maae/build/auction/goal_manager")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/auction/goal_manager" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/auction/goal_manager")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/auction/goal_manager"
         OLD_RPATH "/home/gkasha/ros2_humble/install/rclcpp/lib:/home/gkasha/Documents/maae/install/ma_interfaces/lib:/home/gkasha/ros2_humble/install/std_msgs/lib:/home/gkasha/ros2_humble/install/libstatistics_collector/lib:/home/gkasha/ros2_humble/install/rcl/lib:/home/gkasha/ros2_humble/install/rmw_implementation/lib:/home/gkasha/ros2_humble/install/ament_index_cpp/lib:/home/gkasha/ros2_humble/install/rcl_logging_spdlog/lib:/home/gkasha/ros2_humble/install/rcl_logging_interface/lib:/home/gkasha/ros2_humble/install/rcl_interfaces/lib:/home/gkasha/ros2_humble/install/rcl_yaml_param_parser/lib:/home/gkasha/ros2_humble/install/libyaml_vendor/lib:/home/gkasha/ros2_humble/install/rosgraph_msgs/lib:/home/gkasha/ros2_humble/install/statistics_msgs/lib:/home/gkasha/ros2_humble/install/tracetools/lib:/home/gkasha/ros2_humble/install/builtin_interfaces/lib:/home/gkasha/ros2_humble/install/rosidl_typesupport_fastrtps_c/lib:/home/gkasha/ros2_humble/install/rosidl_typesupport_fastrtps_cpp/lib:/home/gkasha/ros2_humble/install/fastcdr/lib:/home/gkasha/ros2_humble/install/rmw/lib:/home/gkasha/ros2_humble/install/rosidl_typesupport_introspection_cpp/lib:/home/gkasha/ros2_humble/install/rosidl_typesupport_introspection_c/lib:/home/gkasha/ros2_humble/install/rosidl_typesupport_cpp/lib:/home/gkasha/ros2_humble/install/rosidl_typesupport_c/lib:/home/gkasha/ros2_humble/install/rcpputils/lib:/home/gkasha/ros2_humble/install/rosidl_runtime_c/lib:/home/gkasha/ros2_humble/install/rcutils/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/auction/goal_manager")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/auction/clock" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/auction/clock")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/auction/clock"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/auction" TYPE EXECUTABLE FILES "/home/gkasha/Documents/maae/build/auction/clock")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/auction/clock" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/auction/clock")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/auction/clock"
         OLD_RPATH "/home/gkasha/ros2_humble/install/rclcpp/lib:/home/gkasha/Documents/maae/install/ma_interfaces/lib:/home/gkasha/ros2_humble/install/std_msgs/lib:/home/gkasha/ros2_humble/install/libstatistics_collector/lib:/home/gkasha/ros2_humble/install/rcl/lib:/home/gkasha/ros2_humble/install/rmw_implementation/lib:/home/gkasha/ros2_humble/install/ament_index_cpp/lib:/home/gkasha/ros2_humble/install/rcl_logging_spdlog/lib:/home/gkasha/ros2_humble/install/rcl_logging_interface/lib:/home/gkasha/ros2_humble/install/rcl_interfaces/lib:/home/gkasha/ros2_humble/install/rcl_yaml_param_parser/lib:/home/gkasha/ros2_humble/install/libyaml_vendor/lib:/home/gkasha/ros2_humble/install/rosgraph_msgs/lib:/home/gkasha/ros2_humble/install/statistics_msgs/lib:/home/gkasha/ros2_humble/install/tracetools/lib:/home/gkasha/ros2_humble/install/builtin_interfaces/lib:/home/gkasha/ros2_humble/install/rosidl_typesupport_fastrtps_c/lib:/home/gkasha/ros2_humble/install/rosidl_typesupport_fastrtps_cpp/lib:/home/gkasha/ros2_humble/install/fastcdr/lib:/home/gkasha/ros2_humble/install/rmw/lib:/home/gkasha/ros2_humble/install/rosidl_typesupport_introspection_cpp/lib:/home/gkasha/ros2_humble/install/rosidl_typesupport_introspection_c/lib:/home/gkasha/ros2_humble/install/rosidl_typesupport_cpp/lib:/home/gkasha/ros2_humble/install/rosidl_typesupport_c/lib:/home/gkasha/ros2_humble/install/rcpputils/lib:/home/gkasha/ros2_humble/install/rosidl_runtime_c/lib:/home/gkasha/ros2_humble/install/rcutils/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/auction/clock")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/package_run_dependencies" TYPE FILE FILES "/home/gkasha/Documents/maae/build/auction/ament_cmake_index/share/ament_index/resource_index/package_run_dependencies/auction")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/parent_prefix_path" TYPE FILE FILES "/home/gkasha/Documents/maae/build/auction/ament_cmake_index/share/ament_index/resource_index/parent_prefix_path/auction")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/auction/environment" TYPE FILE FILES "/home/gkasha/ros2_humble/install/ament_cmake_core/share/ament_cmake_core/cmake/environment_hooks/environment/ament_prefix_path.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/auction/environment" TYPE FILE FILES "/home/gkasha/Documents/maae/build/auction/ament_cmake_environment_hooks/ament_prefix_path.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/auction/environment" TYPE FILE FILES "/home/gkasha/ros2_humble/install/ament_cmake_core/share/ament_cmake_core/cmake/environment_hooks/environment/path.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/auction/environment" TYPE FILE FILES "/home/gkasha/Documents/maae/build/auction/ament_cmake_environment_hooks/path.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/auction" TYPE FILE FILES "/home/gkasha/Documents/maae/build/auction/ament_cmake_environment_hooks/local_setup.bash")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/auction" TYPE FILE FILES "/home/gkasha/Documents/maae/build/auction/ament_cmake_environment_hooks/local_setup.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/auction" TYPE FILE FILES "/home/gkasha/Documents/maae/build/auction/ament_cmake_environment_hooks/local_setup.zsh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/auction" TYPE FILE FILES "/home/gkasha/Documents/maae/build/auction/ament_cmake_environment_hooks/local_setup.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/auction" TYPE FILE FILES "/home/gkasha/Documents/maae/build/auction/ament_cmake_environment_hooks/package.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/packages" TYPE FILE FILES "/home/gkasha/Documents/maae/build/auction/ament_cmake_index/share/ament_index/resource_index/packages/auction")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/auction/cmake" TYPE FILE FILES "/home/gkasha/Documents/maae/build/auction/ament_cmake_export_include_directories/ament_cmake_export_include_directories-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/auction/cmake" TYPE FILE FILES
    "/home/gkasha/Documents/maae/build/auction/ament_cmake_core/auctionConfig.cmake"
    "/home/gkasha/Documents/maae/build/auction/ament_cmake_core/auctionConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/auction" TYPE FILE FILES "/home/gkasha/Documents/maae/src/auction/package.xml")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/gkasha/Documents/maae/build/auction/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
