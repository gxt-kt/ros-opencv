#include "ros/ros.h"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void drawText(Mat & image);

int main(int argc, char *argv[])
{
    //执行 ros 节点初始化
    ros::init(argc,argv,"hello");
    //创建 ros 节点句柄(非必须)
    ros::NodeHandle n;
    //控制台输出 hello world
    ROS_INFO("hello world!");

   // image_transport::ImageTransport it(nh);//用之前声明的节点句柄初始化it
   // image_transport::Publisher pub = it.advertise("camera/image", 1);

   // return 0;
    cout << "Built with OpenCV " << CV_VERSION << endl;
    Mat image;
    VideoCapture capture;
    capture.open(0);
    if(capture.isOpened()){
        cout << "Capture is opened" << endl;
        while(1){
            capture >> image;
            if(image.empty())
                break;
            drawText(image);
            imshow("Sample", image);
            if(waitKey(10) >= 0)
                break;
        }
    }
    else{
        cout << "No capture" << endl;
        image = Mat::zeros(480, 640, CV_8UC1);
        drawText(image);
        imshow("Sample", image);
        waitKey(0);
    }
    return 0;
}

void drawText(Mat & image)
{
    putText(image, "Hello OpenCV",
            Point(20, 50),
            FONT_HERSHEY_COMPLEX, 1, // font face and scale
            Scalar(255, 255, 255), // white
            1, LINE_AA); // line thickness and type
}
