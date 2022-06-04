//
// Created by kt on 2022/6/3.
//

#ifndef COLOR_CONFIG_H_
#define COLOR_CONFIG_H_

#include <string>
#include <opencv2/highgui/highgui.hpp>

#define FIND_RED 1
#define FIND_GREEN 1
#define FIND_BLUE 1
#define FIND_YELLOW 1
#define FIND_CAMERA 2
#define MIN_AREA 1000

namespace mynamespace {
class Color {
 public:
  Color(std::string col_name, cv::Scalar col_cv_color, \
        cv::Scalar col_cv_hsv_low, cv::Scalar col_cv_hsv_up) {
    name = col_name;
    cv_color = col_cv_color;
    cv_hsv_low = col_cv_hsv_low;
    cv_hsv_up = col_cv_hsv_up;
    red = col_cv_color[2];
    green = col_cv_color[1];
    blue = col_cv_color[0];
  }
 public:
  std::string name;
  uint8_t red;
  uint8_t green;
  uint8_t blue;
  cv::Scalar cv_color;
  cv::Scalar cv_hsv_low;
  cv::Scalar cv_hsv_up;
};

Color red("red", cv::Scalar(0, 0, 255), cv::Scalar(0, 43, 46), cv::Scalar(10, 255, 255));
Color green("green", cv::Scalar(0, 255, 0), cv::Scalar(35, 43, 46), cv::Scalar(77, 255, 255));
Color blue("blue", cv::Scalar(255, 0, 0), cv::Scalar(100, 43, 46), cv::Scalar(124, 255, 255));
Color yellow("yellow", cv::Scalar(0, 255, 255), cv::Scalar(26, 43, 46), cv::Scalar(34, 255, 255));

}


#endif // COLOR_CONFIG_H_
