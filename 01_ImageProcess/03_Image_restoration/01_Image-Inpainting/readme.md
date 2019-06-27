##  OpenCV-day-075
 
图像去水印/修复
- [ref1](https://blog.csdn.net/dcrmg/article/details/53792061)
- [ref2](https://www.cnblogs.com/skyfsm/p/6888213.html)

在OpenCV中有时候我们需要一个批量的去水印的方法，这个在很多时候需要用到，对得到图像进行批量的去水印，其本质上是一种图像修复，OpenCV也提供一个图像修复的API，可以部分解决这里问题，
void cv::inpaint(
InputArray  src,
InputArray  ipaintMask,
OutputArray  dst
double  npaintRadius,
int  fags 
)
基于Navier-Stokes的修复方法
基于图像梯度的快速匹配方法又称(Telea法)


