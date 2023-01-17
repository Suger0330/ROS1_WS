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
    /*
        作用:ROS初始化函数
        参数:
            1.argc  ----> 封装实参的个数(n+1),传入的第一个是文件本身
            2.argc  ----> 封装参数的数组(字符串数组)
            3.name  ----> 节点名称，需要保证其唯一性，不允许包含命名空间
            4.options  ----> 节点启动选项，被封装进了ros::init_options

            返回值:void
        使用:
            1.argc 与 argv 的使用
                如果按照ROS中的特定格式传入实参,那么ROS可以加以使用,比如用来设置全局参数、节点重命名等
            2.options 的使用
                节点名称需要保证唯一,若不唯一,会导致一个问题:同一个节点不能重复启动.
                结果:ROS中当有重名的节点启动时,之前的节点会被关闭.
                需求:特定场景下,需要一个节点多次启动且能正常运行,怎么办?
                解决:设置启动项ros::init_options::AnonymousName
                    当创建ROS节点时,会在用户自定义的节点名称后缀随机数,从而避免重名问题.

    */
    ros::init(argc,argv,"publisher_apis",ros::init_options::AnonymousName);
    // 参数1和参数2后期为节点传值会使用
    // 参数3是节点名称，是一个标识符，需要保证运行后，在ROS网络拓扑中唯一
    //3.创建节点句柄;
    ros::NodeHandle nh;//该类封装了 ROS 中的一些常用功能
    //4.创建发布者对象;
    /*
        作用:创建发布者对象

        模板:被发布的消息的类型
        参数:
            1.话题名称/topic
            2.队列长度/queue_size
            3.latch(可选)//如果为 true,该话题发布的最后一条消息将被保存,
                并且后期当有订阅者连接时会将该消息发送给订阅者
        使用:
            latch 设置为 ture 的作用？
            以静态地图发布为例:
            方案1:可以使用固定频率发送地图数据，但是效率低;
            方案2:可以将地图发布对象的latch 设置为true ，并且发布方只发送-次数据，每当订阅者连接时，
            将地图数据发送给订阅者(只发送一次)，这样提高了数据的发送效率。
    */
    ros::Publisher pub = nh.advertise<std_msgs::String>("house",10,true);
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
        // 如果计数器 >= 50,那么关闭节点
        if (count >= 50)
        {
            ros::shutdown();
        }
        //---------------------------
        count++;
        //实现字符串拼接数字
        std::stringstream ss;
        ss << "hello --->" << count;
        //msg.data = "hell0!";
        msg.data = ss.str();
        /*
        if (count <= 10)
        {
            pub.publish(msg);//发布消息
            //加入调试，打印发送的消息
            ROS_INFO("publisher_apis发送的消息:%s",msg.data.c_str());
        }
        */
        pub.publish(msg);//发布消息
        //加入调试，打印发送的消息
        ROS_INFO("publisher_apis发送的消息:%s",msg.data.c_str());
        
        rate.sleep();//根据前面制定的发送贫频率自动休眠
        
        ros::spinOnce();//处理循环当中的回调函数;(官方建议处理回调函数)
        ROS_INFO("一轮回调执行完毕.....");
    }
    
    return 0;
    
}
