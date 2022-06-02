#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <vector>

#define FIND_COLOR_LOW blue_low
#define FIND_COLOR_UP blue_up
#define MIN_AREA 1000

// 设定颜色阈值，HSV空间
cv::Scalar red_low = {0, 43, 46};
cv::Scalar red_up = {10, 255, 255};

cv::Scalar blue_low = {100, 43, 46};
cv::Scalar blue_up = {124, 255, 255};

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
  ros::init(argc, argv, "image_listener");
  ros::NodeHandle node2;
  //cv::namedWindow("view");
  cv::startWindowThread();
  image_transport::ImageTransport it(node2);
  image_transport::Subscriber sub = it.subscribe("camera/image", 1, imageCallback);
  ros::spin();
  //cv::destroyWindow("view");
}

// 定义找到的历史点
std::vector<cv::Point> position_point;

void ImageDeal(cv::Mat img) {
  // show the image
  //cv::imshow("node2", img);
  // convert to HSV
  cv::Mat img_hsv;
  cv::cvtColor(img, img_hsv, cv::COLOR_BGR2HSV);
  // get mask through the color 掩膜
  cv::Mat img_mask;
  cv::inRange(img_hsv, FIND_COLOR_LOW, FIND_COLOR_UP, img_mask);
  // mask erode 腐蚀
  cv::Mat img_erode;
  cv::erode(img_mask, img_erode, 3);
  // mask dilate 膨胀
  cv::Mat img_dilate;
  cv::dilate(img_erode, img_dilate, 4);
  // show
  cv::imshow("dilate", img_dilate);
  // get the img contours
  std::vector<std::vector<cv::Point> > img_contours;
  cv::findContours(img_dilate, img_contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

  std::vector<std::vector<cv::Point> > balls;
  std::vector<cv::Rect> ballsBox;
  for (auto &img_contour : img_contours) {
    cv::Rect img_find_rect;
    img_find_rect = cv::boundingRect(img_contour);

    /* Searching for a bBox almost square
//        float ratio = (float) bBox.width / (float) bBox.height;
//        if (ratio > 1.0f)
//            ratio = 1.0f / ratio;
//        if (ratio > 0.75 && bBox.area() >= MIN_AREA) {
//            balls.push_back(img_contours[i]);
//            ballsBox.push_back(bBox);
//        }
//      // just area condition*/
    // 对区域最小值进行限制
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

    cv::drawContours(img, balls, max_find_n, CV_RGB(20, 150, 20), 1);
    cv::rectangle(img, ballsBox[max_find_n], CV_RGB(0, 255, 0), 2);

    cv::Point center;
    center.x = ballsBox[max_find_n].x + ballsBox[max_find_n].width / 2;
    center.y = ballsBox[max_find_n].y + ballsBox[max_find_n].height / 2;
    cv::circle(img, center, 2, CV_RGB(20, 150, 20), -1);

    position_point.push_back(center);
  }
  // 根据存储点画线
  if (position_point.size()>1) {
    for (int i = 0; i < position_point.size() - 1; i++) {
      cv::line(img, position_point[i], position_point[i + 1], cv::Scalar(255, 0, 0), 2);
    }
  }

  cv::imshow("find_max", img);

}