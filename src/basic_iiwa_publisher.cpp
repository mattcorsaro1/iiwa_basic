#include <iiwa_ros.h>

void joint_print_callback(const iiwa_msgs::JointPosition::ConstPtr& joints)
{
  ROS_INFO_STREAM("JOINTS: (" << joints->position.a1 << ", " << joints->position.a2 <<
    ", " << joints->position.a3 << ", " << joints->position.a4 << ", " <<
    joints->position.a5 << ", " << joints->position.a6 << ", " << joints->position.a7 << ")");
}

int main(int argc, char* argv[])
{
  ros::init(argc, argv, "basic_iiwa_publisher");

  ros::NodeHandle n;
  ros::Publisher joint_pub = n.advertise<iiwa_msgs::JointPosition>("/iiwa/command/JointPosition", 1000);
  ros::Subscriber sub = n.subscribe("/iiwa/state/JointPosition", 1000, joint_print_callback);

  iiwa_msgs::JointPosition target_joints;
  target_joints.position.a1 = 0.0;
  target_joints.position.a2 = 0.0;
  target_joints.position.a3 = 0.0;
  target_joints.position.a4 = 0.0;
  target_joints.position.a5 = 0.0;
  target_joints.position.a6 = 0.0;
  target_joints.position.a7 = 0.0;

  while (ros::ok())
  {
    joint_pub.publish(target_joints);
    ros::Duration(1.0).sleep();
    ros::spinOnce();
  }

  return 0;
}
