#! /usr/bin/env python

'''
    客户端:请求,产生响应
        1.导包;
        2.初始化ROS节点;
        3.创建客户端对象;
        4.组织请求数据,并发送请求;
        5.处理响应.

    优化实现:
        可以在执行节点时,动态传入参数
    问题:
       如果先启动客户端,那么请求会异常.
    需求:
        如果先启动客户端,不要直接抛出异常,而是挂起,等服务器启动后,再正常请求.
    解决:
        在ROS中内置了相关函数,这些函数可以让客户端启动后挂起,等待服务器启动.
        方案1:client.wait_for_service();
        方案2:rospy.wait_for_service("话题名称");

'''

import rospy
from plum_server_client.srv import AddInts,AddIntsRequest,AddIntsResponse
# from plum_server_client.srv import * //简单引用
import sys

if __name__ == "__main__":
    # 判断参数长度
    if len(sys.argv) != 3:
        rospy.loginfo("传入的参数个数不对!!")

        sys.exit(1)

    # 2.初始化ROS节点;
    rospy.init_node("clienter_p")
    # 3.创建客户端对象;
    client = rospy.ServiceProxy("clean",AddInts)
    # 请求前，等待服务已经就绪
    # 函数1:
    # rospy.wait_for_service("clean")
    # 函数2
    client.wait_for_service()
    # 4.组织请求数据,并发送请求;
    # 解析传入的参数
    num1 = int(sys.argv[1])
    num2 = int(sys.argv[2])
    response = client.call(num1,num2)

    # 5.处理响应.
    rospy.loginfo("响应的数据是:%d",response.sum)
