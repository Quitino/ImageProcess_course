#include "opencv2/opencv.hpp"    
#include <iostream>    
 
using namespace cv;
using namespace std;
 
void main()
{
	Mat inp_img = cv::imread("test1.jpg");
	if (!inp_img.data) {
		cout << "Something Wrong";
	}
	namedWindow("Input Image", CV_WINDOW_AUTOSIZE);
	imshow("Input Image", inp_img);
 
	Mat clahe_img;
	cvtColor(inp_img, clahe_img, CV_BGR2Lab);
	vector<cv::Mat> channels(3);
	split(clahe_img, channels);
 
	Ptr<cv::CLAHE> clahe = createCLAHE();
	// 直方图的柱子高度大于计算后的ClipLimit的部分被裁剪掉，然后将其平均分配给整张直方图   
	clahe->setClipLimit(4.); // (int)(4.*(8*8)/256)  
	//clahe->setTilesGridSize(Size(8, 8)); // 将图像分为8*8块  
	Mat dst;
	clahe->apply(channels[0], dst);
	dst.copyTo(channels[0]);
	//
	clahe->apply(channels[1], dst);
	dst.copyTo(channels[1]);
	clahe->apply(channels[2], dst);
	dst.copyTo(channels[2]);
	merge(channels, clahe_img);
 
	Mat image_clahe;
	cvtColor(clahe_img, image_clahe, CV_Lab2BGR);
 
	namedWindow("CLAHE Image", CV_WINDOW_AUTOSIZE);
	imshow("CLAHE Image", image_clahe);
	imwrite("out.jpg", image_clahe);
	waitKey();
	system("pause");
}
--------------------- 
作者：古路 
来源：CSDN 
原文：https://blog.csdn.net/fb_941219/article/details/83448129 
版权声明：本文为博主原创文章，转载请附上博文链接！