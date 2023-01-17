#! /usr/bin/env python

import rospy
from plum_pub_sub.msg import Person
'''
    订阅方:订阅人的消息
    1.导包
    2.初始化ROS节点
    3.创建订阅者对象
    4.处理订阅的数据
    5.spin()

'''
def doPerson(p):
    rospy.loginfo("姓名:%s,年龄:%d,身高:%.2f",p.name,p.age,p.height)

if __name__ == "__main__":
    #2.初始化ROS节点
    rospy.init_node("clstudent")
    #3.创建订阅者对象
    sub = rospy.Subscriber("talk",Person,doPerson,queue_size=1000,)
    #4.处理订阅的数据
    #5.spin()
    rospy.spin()
