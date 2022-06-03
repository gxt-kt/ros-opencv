//
// Created by kt on 2022/6/1.
//

#include "ros/ros.h"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
#include "image_transport/image_transport.h"
#include "std_msgs/String.h"
#include <cv_bridge/cv_bridge.h>
#include "opencv2/imgcodecs/legacy/constants_c.h" // to solve the bug CV_LOAD_IMAGE_COLOR
#include "sstream"
#include <iostream>

using namespace cv;

void drawText(Mat &image);

int main(int argc, char *argv[]) {
  //执行 ros 节点初始化
  ros::init(argc, argv, "node1_send_img");
  //创建 ros 节点句柄(非必须)
  ros::NodeHandle node1;
  //控制台输出 hello world
  ROS_INFO("This is node1! and name is node1_send_img");
  ROS_INFO("Built with OpenCV %s", CV_VERSION);
  // Set the ImageTransport
  image_transport::ImageTransport it(node1);
  image_transport::Publisher pub = it.advertise("camera/image", 1);

  //    Mat image;
//    VideoCapture capture;
//    capture.open(0);
//    if(capture.isOpened()){
//        cout << "Capture is opened" << endl;
//        while(1){
//            capture >> image;
//            if(image.empty())
//                break;
//            drawText(image);
//            imshow("Sample", image);
//            if(waitKey(10) >= 0)
//                break;
//        }
//    }
//    else{
//        cout << "No capture" << endl;
//        image = Mat::zeros(480, 640, CV_8UC1);
//        drawText(image);
//        imshow("Sample", image);
//        waitKey(0);
//    }
//    return 0;
  cv::Mat image;
  cv::VideoCapture capture;
  capture.open(0);
  capture.set(cv::CAP_PROP_FRAME_WIDTH, 640);
  capture.set(cv::CAP_PROP_FRAME_HEIGHT, 480);
  if (capture.isOpened()) {
    ROS_INFO("capture opened");
    while (1) {
      capture >> image;
      if (image.empty())
        break;
//            drawText(image);
//            imshow("image", image);
//      if (waitKey(1) >= 0)
//        break;
      //===========
      sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();
      //ros::Rate loop_rate(60);
      if (node1.ok()) {
        pub.publish(msg);
        static int fps = 0;
        ros::Time t1 = ros::Time::now();
        uint64 ms = t1.toNSec() / 1000000;
        static uint64 ms_last;
        if (ms - ms_last > 1000) {
          ROS_INFO("fps = %d", fps);
          fps=0;
          ms_last=ms;
        }
        fps++;
        //ROS_INFO("running n=%ld", ms);
        ros::spinOnce();
        //loop_rate.sleep();
      }
    }
  } else {
    ROS_INFO("capture open failed");
  }
  return 0;
}

void drawText(Mat &image) {
  putText(image, "Hello OpenCV",
          Point(20, 50),
          FONT_HERSHEY_COMPLEX, 1, // font face and scale
          Scalar(255, 255, 255), // white
          1, LINE_AA); // line thickness and type
}

//std::vector<uint8_t> color
//std::vector<cv::Point> point_position