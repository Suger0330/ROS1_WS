#include "ros/ros.h"
#include "std_msgs/String.h"

/*
    订阅方实现：
        1.包含头文件;
            ROS中文本类型 ---> std_msgs/String.h
        2.初始化ROS节点;
        3.创建节点句柄;
        4.创建订阅者对象;
        5.处理订阅到的数据;
        6.设置循环调用回调函数,spin()函数
*/
void doMsg(const std_msgs::String::ConstPtr &msg){
    //通过msg获取并操作订阅到的数据
    ROS_INFO("subscriber订阅到的数据:%s",msg->data.c_str());

}


int main(int argc, char *argv[])
{
    //设置编码
    setlocale(LC_ALL,"");
    //2.初始化ROS节点;
    ros::init(argc,argv,"subscriber");
    //3.创建节点句柄;
    ros::NodeHandle nh;
    //4.创建订阅者对象;
    ros::Subscriber sub = nh.subscribe("house",10,doMsg);
    //5.处理订阅到的数据.

    //6.设置循环调用回调函数
    ros::spin();//循环读取接收的数据，并调用回调函数处理
    return 0;
}
