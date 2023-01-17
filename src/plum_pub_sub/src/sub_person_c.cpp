#include "ros/ros.h"
#include "plum_pub_sub/Person.h"
/*
    订阅方:发布人的消息
        1.包含头文件;
            #include "plumbing_pub_sub/Person.h"
        2.初始化ROS节点;
        3.创建节点句柄;
        4.创建订阅者对象;
        5.处理订阅的数据;
        6.设置循环调用回调函数,spin()函数.

*/

void doPerson(const plum_pub_sub::Person::ConstPtr& person){
    ROS_INFO("订阅人的信息为:%s,%d,%.2f",person->name.c_str(),person->age,person->height);

}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ROS_INFO("这里是订阅方:");
    //2.初始化ROS节点;
    ros::init(argc,argv,"students");
    //3.创建节点句柄;
    ros::NodeHandle nh;
    //4.创建订阅者对象;
    ros::Subscriber sub = nh.subscribe<plum_pub_sub::Person>("chat",1000,doPerson);
    //5.处理订阅的数据;

    //6.设置循环调用回调函数,spin()函数.
    ros::spin();
    return 0;
}


