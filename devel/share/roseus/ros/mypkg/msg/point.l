;; Auto-generated. Do not edit!


(when (boundp 'mypkg::point)
  (if (not (find-package "MYPKG"))
    (make-package "MYPKG"))
  (shadow 'point (find-package "MYPKG")))
(unless (find-package "MYPKG::POINT")
  (make-package "MYPKG::POINT"))

(in-package "ROS")
;;//! \htmlinclude point.msg.html


(defclass mypkg::point
  :super ros::object
  :slots (_color _point_x _point_y _rec_w _rec_h ))

(defmethod mypkg::point
  (:init
   (&key
    ((:color __color) 0)
    ((:point_x __point_x) 0)
    ((:point_y __point_y) 0)
    ((:rec_w __rec_w) 0)
    ((:rec_h __rec_h) 0)
    )
   (send-super :init)
   (setq _color (round __color))
   (setq _point_x (round __point_x))
   (setq _point_y (round __point_y))
   (setq _rec_w (round __rec_w))
   (setq _rec_h (round __rec_h))
   self)
  (:color
   (&optional __color)
   (if __color (setq _color __color)) _color)
  (:point_x
   (&optional __point_x)
   (if __point_x (setq _point_x __point_x)) _point_x)
  (:point_y
   (&optional __point_y)
   (if __point_y (setq _point_y __point_y)) _point_y)
  (:rec_w
   (&optional __rec_w)
   (if __rec_w (setq _rec_w __rec_w)) _rec_w)
  (:rec_h
   (&optional __rec_h)
   (if __rec_h (setq _rec_h __rec_h)) _rec_h)
  (:serialization-length
   ()
   (+
    ;; int32 _color
    4
    ;; int32 _point_x
    4
    ;; int32 _point_y
    4
    ;; int32 _rec_w
    4
    ;; int32 _rec_h
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _color
       (write-long _color s)
     ;; int32 _point_x
       (write-long _point_x s)
     ;; int32 _point_y
       (write-long _point_y s)
     ;; int32 _rec_w
       (write-long _rec_w s)
     ;; int32 _rec_h
       (write-long _rec_h s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _color
     (setq _color (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _point_x
     (setq _point_x (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _point_y
     (setq _point_y (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _rec_w
     (setq _rec_w (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _rec_h
     (setq _rec_h (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get mypkg::point :md5sum-) "ced0dd05440ad59425463c1af8c9cc38")
(setf (get mypkg::point :datatype-) "mypkg/point")
(setf (get mypkg::point :definition-)
      "int32 color
int32 point_x
int32 point_y
int32 rec_w
int32 rec_h

")



(provide :mypkg/point "ced0dd05440ad59425463c1af8c9cc38")


