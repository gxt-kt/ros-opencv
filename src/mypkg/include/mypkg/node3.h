//
// Created by kt on 2022/6/3.
//

#ifndef NODE3_H_
#define NODE3_H_

#include <opencv2/highgui/highgui.hpp>
#include "mypkg/color_config.h"
#include <vector>
#include "mypkg/point.h"

struct GetNode2Message {
  bool flush = 0;
  std::vector<mypkg::point> point;
  cv::Rect position_rect;
};

#endif // NODE3_H_
