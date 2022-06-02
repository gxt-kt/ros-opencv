//
// Created by kt on 2022/6/2.
//

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <vector>


void ImageDeal(cv::Mat img);

void imageCallback(const sensor_msgs::ImageConstPtr &msg) {
  try {
    cv::Mat img = cv_bridge::toCvShare(msg, "bgr8")->image;
    ImageDeal(img);
  }
  catch (cv_bridge::Exception &e) {
    ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
  }
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "node3_get_node1_2");
  ros::NodeHandle node3;
  //cv::namedWindow("view");
  cv::startWindowThread();
  image_transport::ImageTransport it(node3);
  image_transport::Subscriber sub = it.subscribe("camera/image", 1, imageCallback);
  ros::spin();
  //cv::destroyWindow("view");
}


void ImageDeal(cv::Mat img) {
  // show the image
  cv::imshow("node3", img);

}