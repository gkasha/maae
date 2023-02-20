cmake_minimum_required(VERSION 3.8)
project(auction)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(ma_interfaces REQUIRED)

include_directories(include)
install(DIRECTORY include/${PROJECT_NAME}/ DESTINATION include/${PROJECT_NAME}/)
ament_export_include_directories(include)

add_executable(execution_interface src/execution_interface.cpp)
ament_target_dependencies(execution_interface
  rclcpp ma_interfaces)

add_executable(client src/client.cpp)
ament_target_dependencies(client
  rclcpp ma_interfaces)

add_executable(agent src/agent.cpp src/stn.cpp)
ament_target_dependencies(agent
  rclcpp ma_interfaces)

add_executable(goal_manager src/goal_manager.cpp)
ament_target_dependencies(goal_manager
  rclcpp ma_interfaces)


install(TARGETS
  execution_interface
  client
  agent
  goal_manager
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
