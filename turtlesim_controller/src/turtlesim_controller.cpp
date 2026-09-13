#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "turtelsim_controller");
  ros::NodeHandle n;
  ros::NodeHandle pnh("~"); //Declaring Parameters

  ros::Publisher vel_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);

  ros::Rate loop_rate(10);

  //Declaring Parameters
  float linear_x;
  float angular_z;

  //Declaring Parameters
  pnh.getParam("linear_x", linear_x);
  pnh.getParam("angular_z", angular_z);

  while (ros::ok())
  {
    geometry_msgs::Twist msg;

    // msg.linear.x = 1.0;   // move forward
    // msg.angular.z = 0.5;  // turn while moving (draws a circle)

    //Declaring Parameters
    msg.linear.x = linear_x; 
    msg.linear.y = 0.0;
    msg.linear.z = 0.0;
    msg.angular.x = 0.0;
    msg.angular.y = 0.0;
    msg.angular.z = angular_z;

    ROS_INFO("linear.x: %f, angular.z: %f", msg.linear.x, msg.angular.z);
    vel_pub.publish(msg);

    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}