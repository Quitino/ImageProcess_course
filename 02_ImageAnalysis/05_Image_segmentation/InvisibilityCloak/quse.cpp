#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
 
using namespace std;
using namespace cv;



int en(const cv::Mat srcImg) {


    cv::Mat ImgTemp = srcImg;    //拷贝
    cv::Mat Img;

    cvtColor(ImgTemp, Img, cv::COLOR_BGR2HSV);

    std::vector<cv::Mat> ImgHSV;
    cv::split(Img, ImgHSV);

    uchar H_min = ImgHSV[0].at<uchar>(0, 0), H_max = ImgHSV[0].at<uchar>(0, 0), S_min = ImgHSV[1].at<uchar>(0, 0),
            S_max = ImgHSV[1].at<uchar>(0, 0), V_max = ImgHSV[2].at<uchar>(0, 0), V_min = ImgHSV[2].at<uchar>(0, 0);
    for (long i = 0; i < Img.rows; i++)
        for (long j = 0; j < Img.cols; j++) {
            H_min = (std::min)(H_min, ImgHSV[0].at<uchar>(i, j));
            S_min = (std::min)(S_min, ImgHSV[1].at<uchar>(i, j));
            V_min = (std::min)(V_min, ImgHSV[2].at<uchar>(i, j));
            H_max = (std::max)(H_max, ImgHSV[0].at<uchar>(i, j));
            S_max = (std::max)(S_max, ImgHSV[1].at<uchar>(i, j));
            V_max = (std::max)(V_max, ImgHSV[2].at<uchar>(i, j));
        }
    cout << "H_max:" << (int)H_max << endl << "H_min:" << (int)H_min << endl << "S_max:"
         << (int)S_max << endl << "S_min:" << (int)S_min << endl << "V_max:" << (int)V_max << endl << "V_min：" << (int)V_min << endl;
    return 1;
}

int main(int argc, char** argv){
  cv::Mat image = imread("test.png");
  en(image);
     
  return 0;
}
