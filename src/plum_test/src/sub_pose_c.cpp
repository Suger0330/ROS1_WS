#include "ros/ros.h"
#include "turtlesim/Pose.h"

/*
    需求:订阅小乌龟的位姿并输出到控制台
    准备工作:
        1.获取话题名称 /turtle1/pose
        2.获取消息类型 turtlesim/Pose
        3.运行前启动 turtlesim_node 与 turtle_teleop_key 节点
    实现流程:
        1.包含头文件
        2.初始化ROS节点
        3.创建ROS句柄
        4.创建订阅者对象
        5.回调函数处理订阅的数据
        6.spin();

*/
//处理订阅到的数据
void doPose(const turtlesim::Pose::ConstPtr &pose)
{
    ROS_INFO("乌龟位姿信息:坐标(x=%.2f,y=%.2f),朝向(theta=%.2f),线速度(lv=%.2f),角速度(av=%.2f).",
            pose->x,pose->y,pose->theta,pose->linear_velocity,pose->angular_velocity
    );
}

int main(int argc, char *argv[])
{
    //编码
    setlocale(LC_ALL,"");
    // 2.初始化ROS节点
    ros::init(argc,argv,"sub_pose_c");
    // 3.创建ROS句柄
    ros::NodeHandle nh;
    // 4.创建订阅者对象
    ros::Subscriber sub = nh.subscribe<turtlesim::Pose>("/turtle1/pose",10,doPose);
    //5.回调函数处理订阅的数据

    //6.spin
    ros::spin();
    return 0;
}
