#!/usr/bin/env python3

'''
    演示参数的新增与修改:
    需求:在参数服务器中设置机器人的属性、型号、半径.
    实现:
        rospy.set_param()

'''
import rospy

if  __name__ == "__main__":
    #初始化ROS节点
    rospy.init_node("param_set_p")
    #新增参数
    rospy.set_param("type_p","YellowCar")
    rospy.set_param("radius_p",0.15)
    #修改参数
    rospy.set_param("radius_p",0.20)
