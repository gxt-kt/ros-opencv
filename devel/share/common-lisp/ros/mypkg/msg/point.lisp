; Auto-generated. Do not edit!


(cl:in-package mypkg-msg)


;//! \htmlinclude point.msg.html

(cl:defclass <point> (roslisp-msg-protocol:ros-message)
  ((red
    :reader red
    :initarg :red
    :type cl:fixnum
    :initform 0)
   (green
    :reader green
    :initarg :green
    :type cl:fixnum
    :initform 0)
   (blue
    :reader blue
    :initarg :blue
    :type cl:fixnum
    :initform 0)
   (point_x
    :reader point_x
    :initarg :point_x
    :type cl:integer
    :initform 0)
   (point_y
    :reader point_y
    :initarg :point_y
    :type cl:integer
    :initform 0)
   (rec_w
    :reader rec_w
    :initarg :rec_w
    :type cl:integer
    :initform 0)
   (rec_h
    :reader rec_h
    :initarg :rec_h
    :type cl:integer
    :initform 0)
   (col_name
    :reader col_name
    :initarg :col_name
    :type cl:string
    :initform ""))
)

(cl:defclass point (<point>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <point>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'point)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name mypkg-msg:<point> is deprecated: use mypkg-msg:point instead.")))

(cl:ensure-generic-function 'red-val :lambda-list '(m))
(cl:defmethod red-val ((m <point>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader mypkg-msg:red-val is deprecated.  Use mypkg-msg:red instead.")
  (red m))

(cl:ensure-generic-function 'green-val :lambda-list '(m))
(cl:defmethod green-val ((m <point>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader mypkg-msg:green-val is deprecated.  Use mypkg-msg:green instead.")
  (green m))

(cl:ensure-generic-function 'blue-val :lambda-list '(m))
(cl:defmethod blue-val ((m <point>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader mypkg-msg:blue-val is deprecated.  Use mypkg-msg:blue instead.")
  (blue m))

(cl:ensure-generic-function 'point_x-val :lambda-list '(m))
(cl:defmethod point_x-val ((m <point>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader mypkg-msg:point_x-val is deprecated.  Use mypkg-msg:point_x instead.")
  (point_x m))

(cl:ensure-generic-function 'point_y-val :lambda-list '(m))
(cl:defmethod point_y-val ((m <point>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader mypkg-msg:point_y-val is deprecated.  Use mypkg-msg:point_y instead.")
  (point_y m))

(cl:ensure-generic-function 'rec_w-val :lambda-list '(m))
(cl:defmethod rec_w-val ((m <point>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader mypkg-msg:rec_w-val is deprecated.  Use mypkg-msg:rec_w instead.")
  (rec_w m))

(cl:ensure-generic-function 'rec_h-val :lambda-list '(m))
(cl:defmethod rec_h-val ((m <point>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader mypkg-msg:rec_h-val is deprecated.  Use mypkg-msg:rec_h instead.")
  (rec_h m))

(cl:ensure-generic-function 'col_name-val :lambda-list '(m))
(cl:defmethod col_name-val ((m <point>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader mypkg-msg:col_name-val is deprecated.  Use mypkg-msg:col_name instead.")
  (col_name m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <point>) ostream)
  "Serializes a message object of type '<point>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'red)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'green)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'blue)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'point_x)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'point_y)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'rec_w)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'rec_h)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'col_name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'col_name))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <point>) istream)
  "Deserializes a message object of type '<point>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'red)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'green)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'blue)) (cl:read-byte istream))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'point_x) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'point_y) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'rec_w) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'rec_h) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'col_name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'col_name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<point>)))
  "Returns string type for a message object of type '<point>"
  "mypkg/point")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'point)))
  "Returns string type for a message object of type 'point"
  "mypkg/point")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<point>)))
  "Returns md5sum for a message object of type '<point>"
  "3b20bcbd4ecfee1b0e2965ef3012f41b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'point)))
  "Returns md5sum for a message object of type 'point"
  "3b20bcbd4ecfee1b0e2965ef3012f41b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<point>)))
  "Returns full string definition for message of type '<point>"
  (cl:format cl:nil "uint8 red~%uint8 green~%uint8 blue~%int32 point_x~%int32 point_y~%int32 rec_w~%int32 rec_h~%string col_name~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'point)))
  "Returns full string definition for message of type 'point"
  (cl:format cl:nil "uint8 red~%uint8 green~%uint8 blue~%int32 point_x~%int32 point_y~%int32 rec_w~%int32 rec_h~%string col_name~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <point>))
  (cl:+ 0
     1
     1
     1
     4
     4
     4
     4
     4 (cl:length (cl:slot-value msg 'col_name))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <point>))
  "Converts a ROS message object to a list"
  (cl:list 'point
    (cl:cons ':red (red msg))
    (cl:cons ':green (green msg))
    (cl:cons ':blue (blue msg))
    (cl:cons ':point_x (point_x msg))
    (cl:cons ':point_y (point_y msg))
    (cl:cons ':rec_w (rec_w msg))
    (cl:cons ':rec_h (rec_h msg))
    (cl:cons ':col_name (col_name msg))
))
