#include <geometry_msgs/Twist.h>
#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>

ros::Publisher pub;
ros::Subscriber sub;
geometry_msgs::Twist vel;

void counterCallback(const sensor_msgs::LaserScan::ConstPtr &msg) {

  ROS_INFO("LaserScan range %f", msg->ranges[360]);
  double f = msg->ranges[360];
  double l = msg->ranges[719];
  double r = msg->ranges[0];

  if (f > 1.0) {
    vel.linear.x = 0.1;
    vel.angular.z = 0;
  } else {
    vel.angular.z = 0.2;
  }
  if (r < 1.0) {
    vel.angular.z = 0.2;
  }
  if (l < 1) {
    vel.angular.z = -0.2;
  }

  pub.publish(vel);
}

int main(int argc, char **argv) {

  ros::init(argc, argv, "topics_quiz_node");
  ros::NodeHandle nh;

  pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
  sub = nh.subscribe("/kobuki/laser/scan", 1000, counterCallback);

  ros::spin();
  return 0;
}