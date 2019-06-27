##OpenCV-day-118

Grabcut图像分割

Grabcut是基于图割(graph cut)实现的图像分割算法，它需要用户输入一个bounding box作为分割目标位置，实现对目标与背景的分离/分割，这个跟KMeans与MeanShift等图像分割方法有很大的不同，但是Grabcut分割速度快，效果好，支持交互操作，因此在很多APP图像分割/背景虚化的软件中可以看到其身影。
void cv::grabCut(
	InputArray 	img,
	InputOutputArray 	mask,
	Rect 	rect,
	InputOutputArray 	bgdModel,
	InputOutputArray 	fgdModel,
	int 	iterCount,
	int 	mode = GC_EVAL 
)
img输入的三通道图像
mask输入的单通道图像，初始化方式为GC_INIT_WITH_RECT表示ROI区域可以被初始化为：
GC_BGD 定义为明显的背景像素 0
GC_FGD 定义为明显的前景像素 1
GC_PR_BGD 定义为可能的背景像素 2
GC_PR_FGD 定义为可能的前景像素 3
rect 表示roi区域
bgdModel表示临时背景模型数组
fgdModel表示临时前景模型数组
iterCount表示图割算法迭代次数
mode当使用用户提供的roi时候使用GC_INIT_WITH_RECT
