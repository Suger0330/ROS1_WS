#!/usr/bin/env python3

'''
    需求:订阅小乌龟的位姿并输出到控制台
    准备工作:
        1.获取话题名称 /turtle1/pose
        2.获取消息类型 turtlesim/Pose
        3.运行前启动 turtlesim_node 与 turtle_teleop_key 节点
    实现流程:
        1.导包
        2.初始化 ROS 节点
        3.创建订阅对象
        4.使用回调函数处理订阅到的消息
        5.spin()
'''
import rospy
from turtlesim.msg import Pose


def doPose(pose):
    rospy.loginfo("乌龟坐标:x = %.2f,y = %.2f,theta = %.2f,linear = %.2f,angular = %.2f",
                  pose.x,pose.y,pose.theta,pose.linear_velocity,pose.angular_velocity)

if __name__ == "__main__":
    # 2.初始化ROS节点;
    rospy.init_node("pose_p")
    # 3.创建订阅者对象
    sub = rospy.Subscriber("/turtle1/pose",Pose,doPose,queue_size=1000)
    # 4.回调函数处理订阅的数据

    # 5.spin()
    rospy.spin()