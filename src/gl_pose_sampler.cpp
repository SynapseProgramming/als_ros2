#include <als_ros2/GLPoseSampler.h>


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<als_ros2::GLPoseSampler>());
  rclcpp::shutdown();
  return 0;
}