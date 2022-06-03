//
// Created by kt on 2022/6/3.
//
#include <ros/ros.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>
#include <vector>
#include <string>
//#include <opencv2/tracking.hpp>
#include <opencv2/tracking/tracker.hpp>
#include <opencv2/tracking/tldDataset.hpp>
#include <opencv2/core/ocl.hpp>
#include "mypkg/point.h"
#include "mypkg/node2.h"

void Node4OneFrameDeal(cv::Mat &frame);
void Node4ImgDealColor(cv::Mat img, mynamespace::Color col);

// Convert to string
#define SSTR(x) static_cast< std::ostringstream & >( \
( std::ostringstream() << std::dec << x ) ).str()

//#include "mypkg/point.h"
//#include "mypkg/node2.h"


void imageCallback(const sensor_msgs::ImageConstPtr &msg) {
  try {
    cv::Mat img = cv_bridge::toCvShare(msg, "bgr8")->image;
    Node4OneFrameDeal(img);
    //cv::imshow("final result", img);
  }
  catch (cv_bridge::Exception &e) {
    ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
  }
}

// Read first frame
cv::Mat frame=cv::Mat::zeros(640,480,CV_8UC3);
// Define initial boundibg box
cv::Rect2d bbox(50, 50, 10, 10);
// Uncomment the line below to select a different bounding box
cv::Ptr<cv::Tracker> tracker;

std::string trackerType;

int main(int argc, char **argv) {
  ros::init(argc, argv, "image_listener");
  ros::NodeHandle node3;
  //cv::namedWindow("view");
  cv::startWindowThread();
  image_transport::ImageTransport it(node3);
  image_transport::Subscriber sub = it.subscribe("camera/image", 1, imageCallback);


// List of tracker types in OpenCV 3.4.1
  std::string trackerTypes[7] = {"BOOSTING", "MIL", "KCF", "TLD", "MEDIANFLOW", "GOTURN", "MOSSE"};
  trackerType = trackerTypes[2];


#if (CV_MINOR_VERSION < 3)
  {
    ROS_INFO("version=%d", CV_MINOR_VERSION);
    //tracker = cv::Tracker::create(trackerType);

  }
#else
  {
        if (trackerType == "BOOSTING")
            tracker = cv::TrackerBoosting::create();
        if (trackerType == "MIL")
            tracker = cv::TrackerMIL::create();
        if (trackerType == "KCF")
            tracker = cv::TrackerKCF::create();
        if (trackerType == "TLD")
            tracker = cv::TrackerTLD::create();
        if (trackerType == "MEDIANFLOW")
            tracker = cv::TrackerMedianFlow::create();
        if (trackerType == "GOTURN")
            tracker = cv::TrackerGOTURN::create();
        if (trackerType == "MOSSE")
            tracker = cv::TrackerMOSSE::create();
    }
#endif


  ros::spin();
  return 0;
}

bool if_find_col=0;
void Node4OneFrameDeal(cv::Mat& img) {
  // Start timer

  if(if_find_col==0){
    Node4ImgDealColor(img,mynamespace::red);
    imshow("Tracking", img);

  } else{
    double timer = (double) cv::getTickCount();
    // Update the tracking result
    bool ok = tracker->update(img, bbox);
    // Calculate Frames per second (FPS)
    float fps = cv::getTickFrequency() / ((double) cv::getTickCount() - timer);
    if (ok) {
      // Tracking success : Draw the tracked object
      rectangle(img, bbox, cv::Scalar(255, 0, 0), 2, 1);
    } else {
      // Tracking failure detected.
      putText(img, "Tracking failure detected", cv::Point(100, 80), cv::FONT_HERSHEY_SIMPLEX, 0.75, cv::Scalar(0, 0, 255), 2);
    }
    // Display tracker type on frame
    putText(img, trackerType + " Tracker", cv::Point(100, 20), cv::FONT_HERSHEY_SIMPLEX, 0.75, cv::Scalar(50, 170, 50), 2);
    // Display FPS on frame
    putText(img, "FPS : " + SSTR(int(fps)), cv::Point(100, 50), cv::FONT_HERSHEY_SIMPLEX, 0.75, cv::Scalar(50, 170, 50), 2);
    // Display frame.
    imshow("Tracking", img);
  }


}



void Node4ImgDealColor(cv::Mat img, mynamespace::Color col) {
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

  cv::imshow("dilate", img_dilate);

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
    //pub_.publish(send_point);

    tracker = cv::TrackerKCF::create();
    //bbox = cv::selectROI(img, false);
    cv::rectangle(img, ballsBox[max_find_n], cv::Scalar( 255, 0, 0 ), 2, 1 );
    //cv::imshow("Tracking", img);
    tracker->init(img, ballsBox[max_find_n]);
    if_find_col=1;
  }
 // cv::imshow("find_max", img);
}