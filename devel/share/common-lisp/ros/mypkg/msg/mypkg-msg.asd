
(cl:in-package :asdf)

(defsystem "mypkg-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "point" :depends-on ("_package_point"))
    (:file "_package_point" :depends-on ("_package"))
  ))