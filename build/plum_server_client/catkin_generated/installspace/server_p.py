#!/usr/bin/env python3

'''
    服务端:解析客户端请求,产生响应
        1.导包;
        2.初始化ROS节点;
        3.创建服务端对象;
        4.编写处理逻辑(回调函数);
        5.spin()函数;

'''
import rospy
from plum_server_client.srv import AddInts,AddIntsRequest,AddIntsResponse
# from plum_server_client.srv import * //简单引用

# 参数:封装了请求数据
# 返回值:响应数据
def doNum(request):
    # 1.解析提交的两个正整数
    num1 = request.num1
    num2 = request.num2
    # 2.求和
    sum = num1 + num2
    # 3.将结果封装进响应
    response = AddIntsResponse()
    response.sum = sum
    rospy.loginfo("提交的数据:num1 = %d, num2 = %d, sum = %d",request.num1, request.num2, sum)
    return response

if __name__ == "__main__":
    # 2.初始化ROS节点;
    rospy.init_node("company_p")
    # 3.创建服务端对象;
    server = rospy.Service("clean",AddInts,doNum)
    rospy.loginfo("服务器已经启动了-----")
    # 4.回调函数处理请求并产生响应;

    # 5.spin()函数;
    rospy.spin()
