#!/usr/bin/env python3

'''
    需求:向服务器发送请求生成一只小乌龟
    准备工作:
        1.服务话题 /spawn
        2.服务消息类型 turtlesim/Spawn
        3.运行前先启动 turtlesim_node 节点

    实现流程:
        1.导包
          需要包含 turtlesim 包下资源，注意在 package.xml 配置
        2.初始化 ROS节点
        3.创建服务的客户端对象
        4.组织数据并发送请求
        6.处理响应
'''
import rospy
from turtlesim.srv import Spawn,SpawnRequest,SpawnResponse

if __name__ == "__main":

    # 2.初始化ROS节点;
    rospy.init_node("service_call_p")
    # 3.创建服务的客户端对象
    client = rospy.ServiceProxy("/spawn",Spawn)
    # 4.组织数据并发送请求
    # 4.1 请求等待
    client.wait_for_service()
    # 4.2发送请求
    request = SpawnRequest()
    request.x = 1.0
    request.y = 2.0
    request.theta = -1.57
    request.name = "turtle_p"
    # 6.处理响应
    try:
        response = client.call(request)
        rospy.loginfo("乌龟创建成功!，叫:%s",response.name)
    except Exception as e:
        rospy.loginfo("服务调用失败")
