cmake_minimum_required(VERSION 3.8)
project(als_ros2)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(tf2_ros REQUIRED)


add_executable(gl_pose_sampler src/gl_pose_sampler.cpp)
ament_target_dependencies(gl_pose_sampler rclcpp sensor_msgs nav_msgs geometry_msgs visualization_msgs tf2_ros)
target_include_directories(gl_pose_sampler
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)


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


install(
  DIRECTORY include/
  DESTINATION include
)


install(
  DIRECTORY
  classifiers
  DESTINATION share/${PROJECT_NAME}
)

install(TARGETS
  gl_pose_sampler
  DESTINATION lib/${PROJECT_NAME})




ament_package()
