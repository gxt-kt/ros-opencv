//
// Created by kt on 2022/6/2.
//

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <vector>
#include "mypkg/point.h"

std::vector<cv::Point> position_point;
cv::Rect position_rect;
bool find_flag = 0;

void imageCallback(const sensor_msgs::ImageConstPtr &msg) {
  try {
    cv::Mat img = cv_bridge::toCvShare(msg, "bgr8")->image;

    // 根据存储点画线
    if (position_point.size() > 1) {
      for (int i = 0; i < position_point.size() - 1; i++) {
        cv::line(img, position_point[i], position_point[i + 1], cv::Scalar(255, 0, 0), 2);
      }
    }
    if (find_flag) {
      cv::rectangle(img, position_rect, CV_RGB(0, 255, 0), 2);
      find_flag = 0;
    }
    cv::imshow("final result", img);
  }
  catch (cv_bridge::Exception &e) {
    ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
  }
}

void DealNode2Data(mypkg::point find_point) {
  ROS_INFO("point_x:%d point_y:%d", find_point.point_x, find_point.point_y);
  cv::Point point;
  point.x = find_point.point_x;
  point.y = find_point.point_y;
  position_rect.width = find_point.rec_w;
  position_rect.height = find_point.rec_h;
  position_rect.x = find_point.point_x-find_point.rec_w/2;
  position_rect.y = find_point.point_y-find_point.rec_h/2;
  position_point.push_back(point);
  find_flag = 1;
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "node3_get_node1_2");
  ros::NodeHandle node3;
  //cv::namedWindow("view");
  cv::startWindowThread();
  image_transport::ImageTransport it(node3);
  image_transport::Subscriber sub = it.subscribe("camera/image", 1, imageCallback);

  ros::Subscriber sub2 = node3.subscribe<mypkg::point>("find_point", 10, DealNode2Data);

  ros::spin();
  return 0;
  //cv::destroyWindow("view");
}

