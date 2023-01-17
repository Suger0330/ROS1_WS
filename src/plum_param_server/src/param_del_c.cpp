#include "ros/ros.h"

/*
    演示参数删除:
    实现:
        ros::NodeHandle
            deleteParam()
        ros::param
            del()

*/

int main(int argc, char *argv[])
{
    //设置编码
    setlocale(LC_ALL,"");
    //初始化ROS节点
    ros::init(argc,argv,"del_param_c");
    //创建节点句柄
    ros::NodeHandle nh;

    //删除:NodeHandle-------------------
    bool flag1 = nh.deleteParam("radius");
    if (flag1)
    {
        ROS_INFO("radius 删除成功！！");
    }
    else
    {
        ROS_INFO("radius 删除失败！！");
    }
    //删除:ros::param-------------------
    bool flag2 = ros::param::del("radius_param");
    if (flag2)
    {
        ROS_INFO("radius_param 删除成功！！");
    }
    else
    {
        ROS_INFO("radius_param 删除失败！！");
    }

    return 0;
}
