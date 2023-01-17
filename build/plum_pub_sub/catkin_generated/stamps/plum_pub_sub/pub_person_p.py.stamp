#! /usr/bin/env python
import rospy
from plum_pub_sub.msg import Person
'''
    发布方:发布人的消息
    1.导包
    2.初始化ROS节点
    3.创建发布者对象
    4.组织发布逻辑并发布数据
'''
if __name__ == "__main__":

    #2.初始化ROS节点
    rospy.init_node("classteacher")
    #3.创建发布者对象
    pub = rospy.Publisher("talk",Person,queue_size=1000)
    #4.组织发布逻辑并发布数据
    #4.1创建Person数据
    p = Person()
    p.name = "王思淇"
    p.age = 1
    p.height = 1.65
    #4.2创建发布频率
    rate = rospy.Rate(1)
    #4.3循环发布数据
    while not rospy.is_shutdown():
        pub.publish(p)
        rate.sleep()
        rospy.loginfo("姓名:%s,年龄:%d,身高:%.2f",p.name,p.age,p.height)
        p.age += 1
