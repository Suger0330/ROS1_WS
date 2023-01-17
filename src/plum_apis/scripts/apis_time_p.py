#! /usr/bin/env python
import rospy
'''
    需求1:演示时间相关操作(获取当前时刻+设置指定时刻)
    需求2:程序执行中停顿5秒
    需求3:获取程序开始执行的时刻,且已知持续运行的时间,计算程序结束的时间
    需求4:创建定时器,实现类似于ros::Rate的功能(隔某个时间间隔执行某种操作)

'''

def doMsg(event):
    rospy.loginfo("----------")
    rospy.loginfo("调用回调函数的时刻:%.2f",event.current_real.to_sec())


if __name__ == "__main__":

    # 需求1:演示时间相关操作(获取当前时刻+设置指定时刻)
    rospy.init_node("hello_time")
    # 获取时刻
    # now 函数会将当前时刻封装并返回
    # 当前时刻:now被调用执行的那一刻
    # 参考系:1970年01月01日00:00:00
    right_now = rospy.Time.now()
    rospy.loginfo("当前时刻:%.2f",right_now.to_sec())

    # 设置指定
    time1 = rospy.Time(100.5) #将时间(1970年01月01日00:00:00 逝去100.5秒)封装成 Time 对象
    time2 = rospy.Time(100.123456) #将时间(1970年01月01日00:00:00 逝去100.123456秒)封装成 Time 对象

    rospy.loginfo("指定时刻1 time1 = %.2f",time1.to_sec())
    rospy.loginfo("指定时刻2 time2 = %.6f",time2.to_sec())

    # 从某个时间值获取时间对象
    time3 = rospy.Time.from_sec(200.12)
    rospy.loginfo("指定时刻3 time3 = %.2f",time3.to_sec())

    # 需求2:程序执行中停顿5秒
    rospy.loginfo("休眠前--------------------")
    # 1.封装一个持续时间对象(5秒)
    du = rospy.Duration(5)
    # 2.再将持续时间休眠
    # du.sleep() # 此语句异常
    # rospy.sleep(du)
    rospy.loginfo("休眠后--------------------")

    # 需求3:获取程序开始执行的时刻,且已知持续运行的时间,计算程序结束的时间
    # 1.获取一个时刻 t1
    t1 = rospy.Time.now()
    rospy.loginfo("开始时刻:%.2f",t1.to_sec())
    # 2.设置一个持续时间 du1
    du1 = rospy.Duration(5)
    #3.结束时刻t2 = t1 + du1
    t2 = t1 + du1
    rospy.loginfo("结束时刻:%.2f",t2.to_sec())

    du2 = du + du1
    rospy.loginfo("持续时间相加:%.2f",du2.to_sec())

    # t2 = right_now + t1 # 会抛出异常

    # 需求4:创建定时器,实现类似于ros::Rate的功能(隔某个时间间隔执行某种操作)
    '''  
    def __init__(self, period, callback, oneshot=False, reset=False):
        Constructor.
        @param period: 回调函数的时间间隔
        @type  period: rospy.Duration
        @param callback: 回调函数
        @type  callback: function taking rospy.TimerEvent
        @param oneshot: 设置为True,就只执行一次,否则循环执行
        @type  oneshot: bool
        @param reset: if True, timer is reset when rostime moved backward. [default: False]
        @type  reset: bool
    ''' 
    timer = rospy.Timer(rospy.Duration(2),doMsg) # 创建一个定时器对象
    #timer = rospy.Timer(rospy.Duration(2),doMsg,True)
    rospy.spin()

