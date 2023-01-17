#include "ros/ros.h"
#include "std_msgs/String.h" //普通文本类型的消息
#include <sstream>  //字符串拼接

/*
    发布方实现：
        1.包含头文件;
            ROS中文本类型 ---> std_msgs/String.h
        2.初始化ROS节点;
        3.创建节点句柄;
        4.创建发布者对象;
        5.编写逻辑发布数据并发布数据.
*/
int main(int argc, char *argv[])
{
    //设置编码
    setlocale(LC_ALL,"");
    //2.初始化ROS节点;
    ros::init(argc,argv,"publisher");
    // 参数1和参数2后期为节点传值会使用
    // 参数3是节点名称，是一个标识符，需要保证运行后，在 ROS 网络拓扑中唯一
    //3.创建节点句柄;
    ros::NodeHandle nh;//该类封装了 ROS 中的一些常用功能
    //4.创建发布者对象;
    ros::Publisher pub = nh.advertise<std_msgs::String>("house",10);
    //泛型:发布的消息类型;参数1:要发布到的话题;
    //参数2:队列中最大保存的消息数，超出此阀值时，先进的先销毁(时间早的先销毁)
    
    //5.编写逻辑发布数据并发布数据.
    //要求以 10Hz 的频率发布数据，并且文本后添加编号
    //先创建被发布的消息
    std_msgs::String msg;
    //发布频率
    ros::Rate rate(1);
    //设置编号
    int count = 0;
    //防止在先执行订阅的情况下，发布方发布数据时，publisher 还未在 roscore 注册完毕，导致数据丢失
    ros::Duration(3.0).sleep();//加入休眠，延迟第一条数据的发送
    //编写循环，循环中发布数据
    while (ros::ok())
    {
        count++;
        //实现字符串拼接数字
        std::stringstream ss;
        ss << "hello --->" << count;
        //msg.data = "hell0!";
        msg.data = ss.str();
        pub.publish(msg);//发布消息
        //加入调试，打印发送的消息
        ROS_INFO("publisher发送的消息:%s",msg.data.c_str());
        rate.sleep();//根据前面制定的发送贫频率自动休眠
        ros::spinOnce();//处理循环当中的回调函数;(官方建议处理回调函数)
    }
    
    return 0;
    
}
