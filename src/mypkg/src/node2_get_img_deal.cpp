#include <ros/ros.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <vector>
#include "mypkg/point.h"
#include "mypkg/node2.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "image_listener");

  cv::startWindowThread();

  GetAndSend node2_get_and_send;
  //image_transport::ImageTransport it(node2);
  //image_transport::Subscriber sub = it.subscribe("camera/image", 1, imageCallback);

  //ros::Publisher node2_to_node3 = node2.advertise<mypkg::point>("find_point", 20);

  ros::spin();
  //cv::destroyWindow("view");
}

void GetAndSend::ImageDeal(cv::Mat img) {
  if (FIND_RED == 1) {
    ImgDealColor(img, mynamespace::red);
  }
  if (FIND_GREEN == 1) {
    ImgDealColor(img, mynamespace::green);
  }
  if (FIND_BLUE == 1) {
    ImgDealColor(img, mynamespace::blue);
  }
  if (FIND_YELLOW == 1) {
    ImgDealColor(img, mynamespace::yellow);
  }
  // show the image
  //cv::imshow("node2", img);
  // convert to HSV
//  cv::Mat img_hsv;
//  cv::cvtColor(img, img_hsv, cv::COLOR_BGR2HSV);
//  // get mask through the color 掩膜
//  cv::Mat img_mask;
//  cv::inRange(img_hsv, FIND_COLOR_LOW, FIND_COLOR_UP, img_mask);
//  // mask erode 腐蚀
//  cv::Mat img_erode;
//  cv::erode(img_mask, img_erode, 3);
//  // mask dilate 膨胀
//  cv::Mat img_dilate;
//  cv::dilate(img_erode, img_dilate, 4);
//  // show
//  if (show) {
//    cv::imshow("dilate", img_dilate);
//  }
//  // get the img contours
//  std::vector<std::vector<cv::Point> > img_contours;
//  cv::findContours(img_dilate, img_contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
//
//  std::vector<std::vector<cv::Point> > balls;
//  std::vector<cv::Rect> ballsBox;
//  for (auto &img_contour : img_contours) {
//    cv::Rect img_find_rect;
//    img_find_rect = cv::boundingRect(img_contour);
//
//    /*//Searching for a bBox almost square
//    //        float ratio = (float) bBox.width / (float) bBox.height;
//    //        if (ratio > 1.0f)
//    //            ratio = 1.0f / ratio;
//    //        if (ratio > 0.75 && bBox.area() >= MIN_AREA) {
//    //            balls.push_back(img_contours[i]);
//    //            ballsBox.push_back(bBox);
//    //        }
//    //      // just area condition
//    // 对区域最小值进行限制*/
//    if (cv::contourArea(img_contour) >= MIN_AREA) {
//      balls.push_back(img_contour);
//      ballsBox.push_back(img_find_rect);
//    }
//  }
//
//  ROS_INFO("Balls found:%ld", ballsBox.size());
//
//  // 找到最大的区域
//  if (!ballsBox.empty()) {
//    int max_find_n = 0;
//    for (int i = 1; i < ballsBox.size(); i++) {
//      if (cv::contourArea(balls[i]) > cv::contourArea(balls[max_find_n])) {
//        max_find_n = i;
//      }
//    }
//
//    cv::drawContours(img, balls, max_find_n, CV_RGB(20, 150, 20), 1);
//    cv::rectangle(img, ballsBox[max_find_n], CV_RGB(0, 255, 0), 2);
//
//    cv::Point center;
//    center.x = ballsBox[max_find_n].x + ballsBox[max_find_n].width / 2;
//    center.y = ballsBox[max_find_n].y + ballsBox[max_find_n].height / 2;
//    cv::circle(img, center, 2, CV_RGB(20, 150, 20), -1);
//
//    position_point.push_back(center);
//
//    // send point to node3
//    mypkg::point send_point;
//    send_point.point_x = center.x;
//    send_point.point_y = center.y;
//    send_point.rec_w = ballsBox[max_find_n].width;
//    send_point.rec_h = ballsBox[max_find_n].height;
//    pub_.publish(send_point);
//  }
//  // 根据存储点画线
//  if (position_point.size() > 1) {
//    for (int i = 0; i < position_point.size() - 1; i++) {
//      cv::line(img, position_point[i], position_point[i + 1], cv::Scalar(255, 0, 0), 2);
//    }
//  }
//  if (show) {
//    cv::imshow("find_max", img);
//  }
}

void GetAndSend::ImgDealColor(cv::Mat img, mynamespace::Color col) {
  //cv::imshow("node2", img);
  // convert to HSV
  cv::Mat img_hsv;
  cv::cvtColor(img, img_hsv, cv::COLOR_BGR2HSV);
  // get mask through the color 掩膜
  cv::Mat img_mask;
  cv::inRange(img_hsv, col.cv_hsv_low, col.cv_hsv_up, img_mask);
  // mask erode 腐蚀
  cv::Mat img_erode;
  cv::erode(img_mask, img_erode, 3);
  // mask dilate 膨胀
  cv::Mat img_dilate;
  cv::dilate(img_erode, img_dilate, 4);
  // show
  if (show) {
    cv::imshow("dilate", img_dilate);
  }
  // get the img contours
  std::vector<std::vector<cv::Point> > img_contours;
  cv::findContours(img_dilate, img_contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

  std::vector<std::vector<cv::Point> > balls;
  std::vector<cv::Rect> ballsBox;
  for (auto &img_contour : img_contours) {
    cv::Rect img_find_rect;
    img_find_rect = cv::boundingRect(img_contour);

    if (cv::contourArea(img_contour) >= MIN_AREA) {
      balls.push_back(img_contour);
      ballsBox.push_back(img_find_rect);
    }
  }

  ROS_INFO("Balls found:%ld", ballsBox.size());

  // 找到最大的区域
  if (!ballsBox.empty()) {
    int max_find_n = 0;
    for (int i = 1; i < ballsBox.size(); i++) {
      if (cv::contourArea(balls[i]) > cv::contourArea(balls[max_find_n])) {
        max_find_n = i;
      }
    }

    cv::Point center;
    center.x = ballsBox[max_find_n].x + ballsBox[max_find_n].width / 2;
    center.y = ballsBox[max_find_n].y + ballsBox[max_find_n].height / 2;

    // pack the point and send to node3
    mypkg::point send_point;
    send_point.col_name = col.name;
    send_point.red = col.red;
    send_point.green = col.green;
    send_point.blue = col.blue;
    send_point.point_x = center.x;
    send_point.point_y = center.y;
    send_point.rec_w = ballsBox[max_find_n].width;
    send_point.rec_h = ballsBox[max_find_n].height;
    pub_.publish(send_point);
  }
  // 根据存储点画线
//  if (position_point.size() > 1) {
//    for (int i = 0; i < position_point.size() - 1; i++) {
//      cv::line(img, position_point[i], position_point[i + 1], cv::Scalar(255, 0, 0), 2);
//    }
//  }
  if (show) {
    cv::imshow("find_max", img);
  }
}

void GetAndSend::imageCallback(const sensor_msgs::ImageConstPtr &msg) {
  try {
    cv::Mat img = cv_bridge::toCvShare(msg, "bgr8")->image;
    ImageDeal(img);
  }
  catch (cv_bridge::Exception &e) {
    ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
  }
}