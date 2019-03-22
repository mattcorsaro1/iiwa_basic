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

  iiwa_msgs::JointPosition home_joints;
  home_joints.position.a1 = 0.0;
  home_joints.position.a2 = 0.0;
  home_joints.position.a3 = 0.0;
  home_joints.position.a4 = 0.0;
  home_joints.position.a5 = 0.0;
  home_joints.position.a6 = 0.0;
  home_joints.position.a7 = 0.0;

  iiwa_msgs::JointPosition grasp_joints;
  grasp_joints.position.a1 = 0.853;
  grasp_joints.position.a2 = 1.5604;
  grasp_joints.position.a3 = 0.0;
  grasp_joints.position.a4 = 0.0;
  grasp_joints.position.a5 = 0.0;
  grasp_joints.position.a6 = 0.0;
  grasp_joints.position.a7 = 0.0;

  iiwa_msgs::JointPosition pub_joints = grasp_joints;
  std::string param;
  if(n.getParam("/basic_iiwa_publisher/pos", param))
  {
    std::cout << "Gave param pos: " << param << std::endl;
    if (param == "grasp")
    {
      pub_joints = grasp_joints;
      std::cout << "Sending to grasp." << std::endl;
    }
    else
    {
      pub_joints = home_joints;
      std::cout << "Sending home." << std::endl;
    }
  }
  else
  {
    pub_joints = home_joints;
    std::cout << "Sending home." << std::endl;
  }

  while (ros::ok())
  {
    joint_pub.publish(pub_joints);
    ros::Duration(1.0).sleep();
    ros::spinOnce();
  }

  return 0;
}
