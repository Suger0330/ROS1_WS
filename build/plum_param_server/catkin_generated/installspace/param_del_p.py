#!/usr/bin/env python3

'''
    演示参数删除:
        delete_param()
'''
import rospy

if __name__ == "__main__":
    #初始化ROS节点
    rospy.init_node("param_del_p")

    try:
        #删除参数
        rospy.delete_param("radius_p")
    except Exception as e:
        rospy.loginfo("被删除的参数不存在！！")    
