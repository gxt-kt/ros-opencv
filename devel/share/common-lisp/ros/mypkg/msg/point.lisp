; Auto-generated. Do not edit!


(cl:in-package mypkg-msg)


;//! \htmlinclude point.msg.html

(cl:defclass <point> (roslisp-msg-protocol:ros-message)
  ((color
    :reader color
    :initarg :color
    :type cl:integer
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
    :initform 0))
)

(cl:defclass point (<point>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <point>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'point)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name mypkg-msg:<point> is deprecated: use mypkg-msg:point instead.")))

(cl:ensure-generic-function 'color-val :lambda-list '(m))
(cl:defmethod color-val ((m <point>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader mypkg-msg:color-val is deprecated.  Use mypkg-msg:color instead.")
  (color m))

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
(cl:defmethod roslisp-msg-protocol:serialize ((msg <point>) ostream)
  "Serializes a message object of type '<point>"
  (cl:let* ((signed (cl:slot-value msg 'color)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
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
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <point>) istream)
  "Deserializes a message object of type '<point>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'color) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
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
  "ced0dd05440ad59425463c1af8c9cc38")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'point)))
  "Returns md5sum for a message object of type 'point"
  "ced0dd05440ad59425463c1af8c9cc38")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<point>)))
  "Returns full string definition for message of type '<point>"
  (cl:format cl:nil "int32 color~%int32 point_x~%int32 point_y~%int32 rec_w~%int32 rec_h~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'point)))
  "Returns full string definition for message of type 'point"
  (cl:format cl:nil "int32 color~%int32 point_x~%int32 point_y~%int32 rec_w~%int32 rec_h~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <point>))
  (cl:+ 0
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <point>))
  "Converts a ROS message object to a list"
  (cl:list 'point
    (cl:cons ':color (color msg))
    (cl:cons ':point_x (point_x msg))
    (cl:cons ':point_y (point_y msg))
    (cl:cons ':rec_w (rec_w msg))
    (cl:cons ':rec_h (rec_h msg))
))
