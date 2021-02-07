#! /usr/bin/env python

import rospy
# from std_msgs.msg import Int32 
from nav_msgs.msg import Odometry

def callback(msg): 
  # print (msg.data)

    print(msg)
  # print(msg.header) 
  # print(msg.pose)

rospy.init_node('topic_subscriber')
# sub = rospy.Subscriber('/counter', Int32, callback)
sub = rospy.Subscriber('/odom', Odometry, callback)
rospy.spin()