#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

/*
    需求:发布速度消息
        话题: /turtle1/cmd_vel
        消息: geometry/Twist
    1.包含头文件
    2.初始化ROS节点
    3.创建节点句柄
    4.创建发布对象
    5.发布逻辑实现
    6.spinOnce();

*/

int main(int argc, char *argv[])
{
    //2.初始化ROS节点
    ros::init(argc,argv,"pub_control_c");
    //3.创建节点句柄
    ros::NodeHandle nh;
    //4.创建发布对象
    ros::Publisher pub =nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",1000);
    //5.发布逻辑实现
    ros::Rate rate(10); //设置发布频率
    //组织被发布的消息
    geometry_msgs::Twist twist;
    // xyz 线速度赋值
    twist.linear.x = 1.0;
    twist.linear.y = 0.0;
    twist.linear.z = 0.0;
    // xyz 角速度赋值
    twist.angular.x = 0.0;
    twist.angular.y = 0.0;
    twist.angular.z = 1.0;
    //循环发布
    while (ros::ok())
    {
        pub.publish(twist);
        //休眠
        rate.sleep();
        //6.spinOnce();
        ros::spinOnce();
    }

    return 0;
}
