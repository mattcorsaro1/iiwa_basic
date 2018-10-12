#include <iiwa_ros.h>

int main(int argc, char* argv[])
{
  ros::init(argc, argv, "example_iiwa_publisher");

  iiwa_msgs::JointPosition target_joints;
  target_joints.position.a1 = 0.0;
  target_joints.position.a2 = 0.0;
  target_joints.position.a3 = 0.0;
  target_joints.position.a4 = 0.0;
  target_joints.position.a5 = 0.0;
  target_joints.position.a6 = 0.0;
  target_joints.position.a7 = 0.0;
  iiwa_ros::iiwaRos my_iiwa_ros_object;
  
  my_iiwa_ros_object.init(); // this initializes all the subscribers, publishers and services, it has to be called after you are sure a ros::init() was called.
  
  my_iiwa_ros_object.setJointPosition(target_joints); // The robot will go to "home" position. i.e. all joints at 0.

  ros::spin();
  return 0;
}
