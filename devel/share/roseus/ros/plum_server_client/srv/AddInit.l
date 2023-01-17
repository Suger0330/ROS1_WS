;; Auto-generated. Do not edit!


(when (boundp 'plum_server_client::AddInit)
  (if (not (find-package "PLUM_SERVER_CLIENT"))
    (make-package "PLUM_SERVER_CLIENT"))
  (shadow 'AddInit (find-package "PLUM_SERVER_CLIENT")))
(unless (find-package "PLUM_SERVER_CLIENT::ADDINIT")
  (make-package "PLUM_SERVER_CLIENT::ADDINIT"))
(unless (find-package "PLUM_SERVER_CLIENT::ADDINITREQUEST")
  (make-package "PLUM_SERVER_CLIENT::ADDINITREQUEST"))
(unless (find-package "PLUM_SERVER_CLIENT::ADDINITRESPONSE")
  (make-package "PLUM_SERVER_CLIENT::ADDINITRESPONSE"))

(in-package "ROS")





(defclass plum_server_client::AddInitRequest
  :super ros::object
  :slots (_num1 _num2 ))

(defmethod plum_server_client::AddInitRequest
  (:init
   (&key
    ((:num1 __num1) 0)
    ((:num2 __num2) 0)
    )
   (send-super :init)
   (setq _num1 (round __num1))
   (setq _num2 (round __num2))
   self)
  (:num1
   (&optional __num1)
   (if __num1 (setq _num1 __num1)) _num1)
  (:num2
   (&optional __num2)
   (if __num2 (setq _num2 __num2)) _num2)
  (:serialization-length
   ()
   (+
    ;; int32 _num1
    4
    ;; int32 _num2
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _num1
       (write-long _num1 s)
     ;; int32 _num2
       (write-long _num2 s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _num1
     (setq _num1 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _num2
     (setq _num2 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass plum_server_client::AddInitResponse
  :super ros::object
  :slots (_sum ))

(defmethod plum_server_client::AddInitResponse
  (:init
   (&key
    ((:sum __sum) 0)
    )
   (send-super :init)
   (setq _sum (round __sum))
   self)
  (:sum
   (&optional __sum)
   (if __sum (setq _sum __sum)) _sum)
  (:serialization-length
   ()
   (+
    ;; int32 _sum
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _sum
       (write-long _sum s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _sum
     (setq _sum (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass plum_server_client::AddInit
  :super ros::object
  :slots ())

(setf (get plum_server_client::AddInit :md5sum-) "4781436a0c2affec8025955a6041e481")
(setf (get plum_server_client::AddInit :datatype-) "plum_server_client/AddInit")
(setf (get plum_server_client::AddInit :request) plum_server_client::AddInitRequest)
(setf (get plum_server_client::AddInit :response) plum_server_client::AddInitResponse)

(defmethod plum_server_client::AddInitRequest
  (:response () (instance plum_server_client::AddInitResponse :init)))

(setf (get plum_server_client::AddInitRequest :md5sum-) "4781436a0c2affec8025955a6041e481")
(setf (get plum_server_client::AddInitRequest :datatype-) "plum_server_client/AddInitRequest")
(setf (get plum_server_client::AddInitRequest :definition-)
      "# 客户端请求时发送的两个数字
int32 num1
int32 num2
---
# 服务器响应发送的数据
int32 sum

")

(setf (get plum_server_client::AddInitResponse :md5sum-) "4781436a0c2affec8025955a6041e481")
(setf (get plum_server_client::AddInitResponse :datatype-) "plum_server_client/AddInitResponse")
(setf (get plum_server_client::AddInitResponse :definition-)
      "# 客户端请求时发送的两个数字
int32 num1
int32 num2
---
# 服务器响应发送的数据
int32 sum

")



(provide :plum_server_client/AddInit "4781436a0c2affec8025955a6041e481")


