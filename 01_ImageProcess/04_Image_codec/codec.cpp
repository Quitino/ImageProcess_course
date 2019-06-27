 //https://blog.csdn.net/qq_22207951/article/details/82178803
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cv.h>
#include <highgui.h>
using namespace std;
using namespace cv;

double getPSNR(Mat& src1, Mat& src2, int bb=0);

int main(int argc, char** argv)
{
	Mat src = imread("lena.png");
	cout<<"origin image size: "<<src.dataend-src.datastart<<endl;
	cout<<"height: "<<src.rows<<endl<<"width: "<<src.cols<<endl<<"depth: "<<src.channels()<<endl;
	cout<<"height*width*depth: "<<src.rows*src.cols*src.channels()<<endl<<endl;
	//(1) jpeg compression
	vector<uchar> buff;//buffer for coding
	vector<int> param = vector<int>(2);
	param[0]=CV_IMWRITE_JPEG_QUALITY;
	param[1]=95;//default(95) 0-100

	imencode(".jpg",src,buff,param);
	cout<<"coded file size(jpg): "<<buff.size()<<endl;//fit buff size automatically.
	Mat jpegimage = imdecode(Mat(buff),CV_LOAD_IMAGE_COLOR);

	//(2) png compression
	param[0]=CV_IMWRITE_PNG_COMPRESSION;
	param[1]=3;//default(3)  0-9.
	imencode(".png",src,buff,param);
	cout<<"coded file size(png): "<<buff.size()<<endl;
	Mat pngimage = imdecode(Mat(buff),CV_LOAD_IMAGE_COLOR);

	//(3) intaractive jpeg compression
	char name[64];
	namedWindow("jpg");
	int q=95;
	createTrackbar("quality","jpg",&q,100);
	int key = 0;
	while(key!='q')
	{
		param[0]=CV_IMWRITE_JPEG_QUALITY;
		param[1]=q;
		imencode(".jpg",src,buff,param);
		Mat show = imdecode(Mat(buff),CV_LOAD_IMAGE_COLOR);

		double psnr = getPSNR(src,show);//get PSNR
		double bpp = 8.0*buff.size()/(show.size().area());//bit/pixe;
		sprintf(name,"quality:%03d, %.1fdB, %.2fbpp",q,psnr,bpp);
		putText(show,name,Point(15,50), FONT_HERSHEY_SIMPLEX,1,CV_RGB(255,255,255),2);
		imshow("jpg",show);
		key = waitKey(33);

		if(key =='s')
		{
			//(4) data writing 
			sprintf(name,"q%03d_%.2fbpp.png",q,bpp);
			imwrite(name,show);

			sprintf(name,"q%03d_%.2fbpp.jpg",q,bpp);
			param[0]=CV_IMWRITE_JPEG_QUALITY;
			param[1]=q;
			imwrite(name,src,param);;
		}
	}
}
double getPSNR(Mat& src1, Mat& src2, int bb)
{
	int i,j;
	double sse,mse,psnr;
	sse = 0.0;

	Mat s1,s2;
	cvtColor(src1,s1,CV_BGR2GRAY);
	cvtColor(src2,s2,CV_BGR2GRAY);

	int count=0;
	for(j=bb;j<s1.rows-bb;j++)
	{
		uchar* d=s1.ptr(j);
		uchar* s=s2.ptr(j);

		for(i=bb;i<s1.cols-bb;i++)
		{
			sse += ((d[i] - s[i])*(d[i] - s[i]));
			count++;
		}
	}
	if(sse == 0.0 || count==0)
	{
		return 0;
	}
	else
	{
		mse =sse /(double)(count);
		psnr = 10.0*log10((255*255)/mse);
		return psnr;
	}
}
