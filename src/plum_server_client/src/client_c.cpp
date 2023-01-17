#include "ros/ros.h"
#include "plum_server_client/AddInts.h"

/*
    客户端实现:提交两个整数,并处理响应的结果
        1.包含头文件
        2.初始化ROS节点
        3.创建节点句柄
        4.创建客户端对象
        5.提交请求并处理响应

    实现参数的动态提交:
        1.格式  rosrun xxxx xxxx 12 34
        2.节点执行时,需要获取命令中的参数,并组织进 response
    
    问题:
       如果先启动客户端,那么请求会异常.
    需求:
        如果先启动客户端,不要直接抛出异常,而是挂起,等服务器启动后,再正常请求.
    解决:
        在ROS中内置了相关函数,这些函数可以让客户端启动后挂起,等待服务器启动.
        client.waitForExistence();
        ros::service::waitForService("服务话题");

*/
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    // 优化实现,获取命令中的参数
    // 调用时动态传值,如果通过 launch 的 args 传参，需要传递的参数个数 +3
    if (argc != 3)
    // if (argc != 5)//launch 传参(0-文件路径 1传入的参数 2传入的参数 3节点名称 4日志路径)
    {
        ROS_ERROR("请提交两个整数!!!");
        return 1;
    }
    // 2.初始化ROS节点
    ros::init(argc,argv,"clienter");
    // 3.创建节点句柄
    ros::NodeHandle nh;
    // 4.创建客户对象
    ros::ServiceClient client = nh.serviceClient<plum_server_client::AddInts>("addInts");
    // 5.提交请求并处理响应
    // 5.1组织请求
    plum_server_client::AddInts ai;
    //ai.request.num1 = atoi(argv[1]);
    //ai.request.num2 = atoi(argv[2]);
    ai.request.num1 = atoi(argv[1]);// <atoi>把字符串转换成整型数的一个函数
    ai.request.num2 = atoi(argv[2]);
    // 5.2处理响应
    // 调用判断服务器状态的函数
    // 函数1
    //client.waitForExistence();
    // 函数2
    ros::service::waitForService("addInts");
    bool flag = client.call(ai);
    if(flag){
        ROS_INFO("请求正常处理,响应结果:%d",ai.response.sum);
    }
    else{
        ROS_ERROR("请求处理失败....");
        return 1;
    }

    return 0;
}
