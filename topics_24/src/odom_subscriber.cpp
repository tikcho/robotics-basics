#include <ros/ros.h>
#include <topics_24/Age.h>

int main(int argc, char **argv) {

  ros::init(argc, argv, "odom_sub_node");
  ros::NodeHandle nh;

  ros::Publisher pub = nh.advertise<topics_24::Age>("age_info", 1000);
  ros::Rate loop_rate(2);

  topics_24::Age age;
  age.years = 5;
  age.months = 10;
  age.days = 21;

  while (ros::ok()) {
    pub.publish(age);
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}