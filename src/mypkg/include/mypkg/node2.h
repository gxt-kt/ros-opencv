#ifndef NODE2_H
#define NODE2_H

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <vector>
#include "mypkg/point.h"
#include "mypkg/color_config.h"

class GetAndSend {
 public:
  GetAndSend() {
    image_transport::ImageTransport it(node_);
    sub_ = it.subscribe("camera/image", 1, &GetAndSend::imageCallback, this);
    pub_ = node_.advertise<mypkg::point>("find_point", 20);
  }
  void ImageDeal(cv::Mat img);
  void imageCallback(const sensor_msgs::ImageConstPtr &msg);
  void ImgDealColor(cv::Mat img, mynamespace::Color col);
 public:
  // 设定颜色阈值，HSV空间
  cv::Scalar red_low = {0, 43, 46};
  cv::Scalar red_up = {10, 255, 255};
  cv::Scalar blue_low = {100, 43, 46};
  cv::Scalar blue_up = {124, 255, 255};
  cv::Scalar yellow_low = {26, 43, 46};
  cv::Scalar yellow_up = {34, 255, 255};
  cv::Scalar green_low = {35, 43, 46};
  cv::Scalar green_up = {77, 255, 255};
 private:
  ros::NodeHandle node_;
  image_transport::Subscriber sub_;
  ros::Publisher pub_;
  // 定义找到的历史点
  std::vector<cv::Point> position_point;
  int show = 0;
};

#endif // NODE2_H
