#include "ros/ros.h"
#include "ros_tutorials/DemoSrv.h"
#include <sstream>

bool demo_service_callback(ros_tutorials::DemoSrv::Request &req,
                            ros_tutorials::DemoSrv::Response &res)
{
  std::stringstream ss;
  ss << "Received Here";
  res.out = ss.str();
  ROS_INFO("From Client [%s], Server says [%s]", req.in.c_str(), res.out.c_str());
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "demo_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("demo_service", demo_service_callback);
  //   ROS_INFO("Ready to add two ints.");
  ros::spin();

  return 0;
}