#include <geometry_msgs/Twist.h>
#include <ros/ros.h>

int main(int argc, char **argv) {

  ros::init(argc, argv, "move_robot_node");
  ros::NodeHandle nh;

  ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
  ros::Rate loop_rate(2);

  geometry_msgs::Twist vel;
  vel.linear.x = 0.5;
  vel.angular.z = 0.5;

  while (ros::ok()) {
    pub.publish(vel);
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}