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
  :slots (_red _green _blue _point_x _point_y _rec_w _rec_h _col_name ))

(defmethod mypkg::point
  (:init
   (&key
    ((:red __red) 0)
    ((:green __green) 0)
    ((:blue __blue) 0)
    ((:point_x __point_x) 0)
    ((:point_y __point_y) 0)
    ((:rec_w __rec_w) 0)
    ((:rec_h __rec_h) 0)
    ((:col_name __col_name) "")
    )
   (send-super :init)
   (setq _red (round __red))
   (setq _green (round __green))
   (setq _blue (round __blue))
   (setq _point_x (round __point_x))
   (setq _point_y (round __point_y))
   (setq _rec_w (round __rec_w))
   (setq _rec_h (round __rec_h))
   (setq _col_name (string __col_name))
   self)
  (:red
   (&optional __red)
   (if __red (setq _red __red)) _red)
  (:green
   (&optional __green)
   (if __green (setq _green __green)) _green)
  (:blue
   (&optional __blue)
   (if __blue (setq _blue __blue)) _blue)
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
  (:col_name
   (&optional __col_name)
   (if __col_name (setq _col_name __col_name)) _col_name)
  (:serialization-length
   ()
   (+
    ;; uint8 _red
    1
    ;; uint8 _green
    1
    ;; uint8 _blue
    1
    ;; int32 _point_x
    4
    ;; int32 _point_y
    4
    ;; int32 _rec_w
    4
    ;; int32 _rec_h
    4
    ;; string _col_name
    4 (length _col_name)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _red
       (write-byte _red s)
     ;; uint8 _green
       (write-byte _green s)
     ;; uint8 _blue
       (write-byte _blue s)
     ;; int32 _point_x
       (write-long _point_x s)
     ;; int32 _point_y
       (write-long _point_y s)
     ;; int32 _rec_w
       (write-long _rec_w s)
     ;; int32 _rec_h
       (write-long _rec_h s)
     ;; string _col_name
       (write-long (length _col_name) s) (princ _col_name s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _red
     (setq _red (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _green
     (setq _green (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _blue
     (setq _blue (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; int32 _point_x
     (setq _point_x (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _point_y
     (setq _point_y (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _rec_w
     (setq _rec_w (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _rec_h
     (setq _rec_h (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; string _col_name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _col_name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get mypkg::point :md5sum-) "3b20bcbd4ecfee1b0e2965ef3012f41b")
(setf (get mypkg::point :datatype-) "mypkg/point")
(setf (get mypkg::point :definition-)
      "uint8 red
uint8 green
uint8 blue
int32 point_x
int32 point_y
int32 rec_w
int32 rec_h
string col_name
")



(provide :mypkg/point "3b20bcbd4ecfee1b0e2965ef3012f41b")


