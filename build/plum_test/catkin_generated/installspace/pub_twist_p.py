#!/usr/bin/env python3

'''
    需求:发布速度消息
        话题: /turtle1/cmd_vel
        消息: geometry/Twist   
    1.导包;
    2.初始化ROS节点;
    3.创建发布者对象
    4.编写发布逻辑并发布数据.
'''
import rospy
from geometry_msgs.msg import Twist

if __name__ == "__main__":

    # 2.初始化ROS节点;
    rospy.init_node("control_p")
    # 3.创建发布者对象
    pub = rospy.Publisher("/turtle1/cmd_vel",Twist,queue_size=1000)
    # 4.编写发布逻辑并发布数据.
    # 设置发布频率
    rate = rospy.Rate(10)
    # 创建速度消息
    twist = Twist()
    # xyz 线速度赋值
    twist.linear.x = 2.0
    twist.linear.y = 0.0
    twist.linear.z = 0.0
    # xyz 角速度赋值
    twist.angular.x = 0.0
    twist.angular.y = 0.0
    twist.angular.z = 1.0
    # 循环发布
    while not rospy.is_shutdown():
        pub.publish(twist)
        rate.sleep() #休眠

