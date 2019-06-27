##OpenCV-day-112

KMeans 图像分割 – 背景替换
KMeans可以实现简单的证件照片的背景分割提取与替换，大致可以分为如下几步实现
1.	读入图像建立KMenas样本
2.	使用KMeans图像分割，指定指定分类数目
3.	取左上角的label得到背景cluster index
4.	生成mask区域，然后高斯模糊进行背景替换
