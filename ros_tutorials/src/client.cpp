#include "ros/ros.h"
#include "ros_tutorials/DemoSrv.h"
#include <cstdlib>
#include <sstream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "demo_client");

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<ros_tutorials::DemoSrv>("demo_service");
  ros_tutorials::DemoSrv srv;
  std::stringstream ss;
  ss << "Sending from Here";
  srv.request.in = ss.str();

  if (client.call(srv))
  {
    ROS_INFO("%s", srv.response.out.c_str());
  }
  else
  {
    ROS_ERROR("Failed to call service");
    return 1;
  }

  return 0;
}