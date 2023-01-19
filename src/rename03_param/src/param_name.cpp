#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"hello_param");
    ros::NodeHandle nh;

    /*
        使用ros::paraj 来设置参数
    */
    // 1.全局
    ros::param::set("/radius_A",100);
    // 2.相对
    ros::param::set("radius_B",100);
    // 2.私有
    ros::param::set("~radius_C",100);

    /*
        使用NodeHandle 设置参数
    */
    //全店
    nh.setParam("/radius_nh_A",100);
    //相对
    nh.setParam("radius_nh_B",50);
    //私有
    nh.setParam("~radius_nh_C",25);
    //nh_private.setParam("~radius_nh_C",25);

    return 0;
}
