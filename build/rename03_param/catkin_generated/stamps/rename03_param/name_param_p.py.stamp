#! /usr/bin/env python

import rospy

if __name__ == "__main__":
    
    rospy.init_node("hello_param_p")
    '''
        设置不同类型的参数
    '''
    # 1.全局
    rospy.set_param("/rd_py_A",100)
    # 2.相对
    rospy.set_param("rd_py_B",100)
    # 3.私有
    rospy.set_param("~rd_py_C",100)
    