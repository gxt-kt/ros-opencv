//
// Created by kt on 2022/6/1.
//

#include "ros/ros.h"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
#include "image_transport/image_transport.h"
#include "std_msgs/String.h"
#include <cv_bridge/cv_bridge.h>
#include "opencv2/imgcodecs/legacy/constants_c.h" // to solve the bug CV_LOAD_IMAGE_COLOR
#include "sstream"
#include <iostream>

using namespace cv;

void drawText(Mat & image);

int main(int argc, char *argv[])
{
    //执行 ros 节点初始化
    ros::init(argc,argv,"node1_send_img");
    //创建 ros 节点句柄(非必须)
    ros::NodeHandle node1;
    //控制台输出 hello world
    ROS_INFO("This is node1! and name is node1_send_img");
    ROS_INFO("Built with OpenCV %s",CV_VERSION);
    // Set the ImageTransport
    image_transport::ImageTransport it(node1);
    image_transport::Publisher pub = it.advertise("camera/image", 1);

    //    Mat image;
//    VideoCapture capture;
//    capture.open(0);
//    if(capture.isOpened()){
//        cout << "Capture is opened" << endl;
//        while(1){
//            capture >> image;
//            if(image.empty())
//                break;
//            drawText(image);
//            imshow("Sample", image);
//            if(waitKey(10) >= 0)
//                break;
//        }
//    }
//    else{
//        cout << "No capture" << endl;
//        image = Mat::zeros(480, 640, CV_8UC1);
//        drawText(image);
//        imshow("Sample", image);
//        waitKey(0);
//    }
//    return 0;
    cv::Mat image;
    cv::VideoCapture capture;
    capture.open(0);
    if(capture.isOpened()){
        ROS_INFO("capture opened");
        while(1){
            capture >> image;
            if(image.empty())
                break;
            drawText(image);
            imshow("image", image);
            if(waitKey(10) >= 0)
                break;
            //===========
            sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();
            ros::Rate loop_rate(30);
            if (node1.ok()) {
                pub.publish(msg);
                static int n=0;
                ROS_INFO("running n=%d",n++);
                ros::spinOnce();
                loop_rate.sleep();
            }
        }
    }
    else{
        ROS_INFO("capture open failed");
    }
    //cv::Mat image = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);
    //sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();



//    ros::Rate loop_rate(5);
//    while (node1.ok()) {
//        // pub.publish(msg);
//        static int n=0;
//        ROS_INFO("running n=%d",n++);
//        ros::spinOnce();
//        loop_rate.sleep();
//    }


//    //4.实例化 发布者 对象
//    //泛型: 发布的消息类型
//    //参数1: 要发布到的话题
//    //参数2: 队列中最大保存的消息数，超出此阀值时，先进的先销毁(时间早的先销毁)
//    ros::Publisher pub = node1.advertise<std_msgs::String>("connect1",10);
//    //5.组织被发布的数据，并编写逻辑发布数据
//    //数据(动态组织)
//    std_msgs::String msg;
//    //set time 10times/1s
//    ros::Rate tim(10);
//    int cout;
//    //delay to ensure set the connect
//    ros::Duration(1.0).sleep();
//    //ensure the ros is available
//    while(ros::ok())
//    {
//        //set the send msg
//        std::stringstream sendStr;
//        cout++;
//        sendStr<<"sendStr num->"<<cout;
//        msg.data=sendStr.str();
//        //send msg
//        pub.publish(msg);
//        //send the debug info
//        ROS_INFO("send text and num=%d\n",cout);
//        //ros-sleep
//        tim.sleep();
//        //change mission
//        ros::spinOnce();
//    }

//   image_transport::ImageTransport it(n);//用之前声明的节点句柄初始化it
//   image_transport::Publisher pub = it.advertise("camera/image", 1);

//    cout << "Built with OpenCV " << CV_VERSION << endl;
//    Mat image;
//    VideoCapture capture;
//    capture.open(0);
//    if(capture.isOpened()){
//        cout << "Capture is opened" << endl;
//        while(1){
//            capture >> image;
//            if(image.empty())
//                break;
//            drawText(image);
//            imshow("Sample", image);
//            if(waitKey(10) >= 0)
//                break;
//        }
//    }
//    else{
//        cout << "No capture" << endl;
//        image = Mat::zeros(480, 640, CV_8UC1);
//        drawText(image);
//        imshow("Sample", image);
//        waitKey(0);
//    }
//    return 0;

}

void drawText(Mat & image)
{
    putText(image, "Hello OpenCV",
            Point(20, 50),
            FONT_HERSHEY_COMPLEX, 1, // font face and scale
            Scalar(255, 255, 255), // white
            1, LINE_AA); // line thickness and type
}

