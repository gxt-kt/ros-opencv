//
// Created by kt on 2022/6/2.
//

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <vector>
#include "mypkg/point.h"
#include "mypkg/node3.h"

GetNode2Message get_red;
GetNode2Message get_green;
GetNode2Message get_blue;
GetNode2Message get_yellow;

void DrawRectangle(GetNode2Message &get_col, cv::Mat &img);
void DrawLine(GetNode2Message &get_col, cv::Mat &img);
void ColorPointDeal(GetNode2Message &get_col, mypkg::point find_point);

void imageCallback(const sensor_msgs::ImageConstPtr &msg) {
  try {
    cv::Mat img = cv_bridge::toCvShare(msg, "bgr8")->image;

//    // 根据存储点画线
//    if (position_point.size() > 1) {
//      for (int i = 0; i < position_point.size() - 1; i++) {
//        cv::line(img, position_point[i], position_point[i + 1], cv::Scalar(255, 0, 0), 2);
//      }
//    }
    DrawRectangle(get_red, img);
    DrawRectangle(get_green, img);
    DrawRectangle(get_blue, img);
    DrawRectangle(get_yellow, img);

    DrawLine(get_red, img);
    DrawLine(get_green, img);
    DrawLine(get_blue, img);
    DrawLine(get_yellow, img);

    cv::imshow("final result", img);
  }
  catch (cv_bridge::Exception &e) {
    ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
  }
}

void DrawLine(GetNode2Message &get_col, cv::Mat &img) {
  if (get_col.point.size() > 1) {
    for (int i = 0; i < get_col.point.size() - 1; i++) {
      cv::line(img, cv::Point(get_col.point[i].point_x, get_col.point[i].point_y),
               cv::Point(get_col.point[i + 1].point_x, get_col.point[i + 1].point_y),
               cv::Scalar(get_col.point[0].blue, get_col.point[0].green, get_col.point[0].red), 2);
    }
  }
}

void DrawRectangle(GetNode2Message &get_col, cv::Mat &img) {
  if (get_col.flush) {
    //ROS_INFO("FLUSH1");
    cv::rectangle(img, get_col.position_rect, \
                    CV_RGB(get_col.point.back().red, get_col.point.back().green, get_col.point.back().blue), 2);
    get_col.flush = 0;
  }
  //ROS_INFO("DEBUG1");
}

void DealNode2Data(mypkg::point find_point) {
  //ROS_INFO("point_x:%d point_y:%d", find_point.point_x, find_point.point_y);
  // get red point
  if (find_point.col_name == "red") {
    ColorPointDeal(get_red, find_point);
  } else if (find_point.col_name == "green") {
    ColorPointDeal(get_green, find_point);
  } else if (find_point.col_name == "blue") {
    ColorPointDeal(get_blue, find_point);
  } else if (find_point.col_name == "yellow") {
    ColorPointDeal(get_yellow, find_point);
  }
}

void ColorPointDeal(GetNode2Message &get_col, mypkg::point find_point) {
  //ROS_INFO("point_x:%d point_y:%d", find_point.point_x, find_point.point_y);
  get_col.point.push_back(find_point);
  if(get_col.point.size()>20){
    get_col.point.erase(get_col.point.begin());
  }
  get_col.flush = 1; // flush
  get_col.position_rect.width = find_point.rec_w;
  get_col.position_rect.height = find_point.rec_h;
  get_col.position_rect.x = find_point.point_x - find_point.rec_w / 2;
  get_col.position_rect.y = find_point.point_y - find_point.rec_h / 2;
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

