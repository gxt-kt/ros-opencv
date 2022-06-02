#ifndef NODE2_H
#define NODE2_H

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <vector>
#include "mypkg/point.h"

#define FIND_COLOR_LOW blue_low
#define FIND_COLOR_UP blue_up
#define MIN_AREA 1000

class GetAndSend {
 public:
  GetAndSend() {
    image_transport::ImageTransport it(node_);
    sub_ = it.subscribe("camera/image", 1, &GetAndSend::imageCallback, this);
    pub_ = node_.advertise<mypkg::point>("find_point", 20);
  }
  void ImageDeal(cv::Mat img);
  void imageCallback(const sensor_msgs::ImageConstPtr &msg);
 public:
  // 设定颜色阈值，HSV空间
  cv::Scalar red_low = {0, 43, 46};
  cv::Scalar red_up = {10, 255, 255};
  cv::Scalar blue_low = {100, 43, 46};
  cv::Scalar blue_up = {124, 255, 255};
 private:
  ros::NodeHandle node_;
  //image_transport::ImageTransport it;
  image_transport::Subscriber sub_;
  ros::Publisher pub_;
  // 定义找到的历史点
  std::vector<cv::Point> position_point;
  int show=0;
};


#endif // NODE2_H
