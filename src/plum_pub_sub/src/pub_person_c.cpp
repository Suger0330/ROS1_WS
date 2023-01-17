#include "ros/ros.h"
#include "plum_pub_sub/Person.h"
/*
    发布方:发布人的消息
        1.包含头文件;
            #include "plum_pub_sub/Person.h"
        2.初始化ROS节点;
        3.创建节点句柄;
        4.创建发布者对象;
        5.编写发布逻辑并发布数据.

*/

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ROS_INFO("这是消息的发布方");
    //2.初始化ROS节点;
    ros::init(argc,argv,"teacher");
    //3.创建节点句柄;
    ros::NodeHandle nh;
    //4.创建发布者对象;
    ros::Publisher pub = nh.advertise<plum_pub_sub::Person>("chat",1000);
    //5.编写发布逻辑并发布数据.
    //5.1创建被发布的数据
    plum_pub_sub::Person person;
    person.name = "lxm";
    person.age = 1;
    person.height = 1.80;
    //5.2设置发布频率
    ros::Rate rate(1);
    //5.3循环发布频率
    while (ros::ok())
    {
        //修改被发布的数据
        person.age += 1;
        //核心:数据发布
        pub.publish(person);
        //打印发布的消息
        ROS_INFO("发布的消息是:%s,%d,%.2f",person.name.c_str(),person.age,person.height);
        //休眠
        rate.sleep();
        //建议写上
        ros::spinOnce();
        
    }
    
    return 0;
}
