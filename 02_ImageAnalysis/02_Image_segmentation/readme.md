##OpenCV-day-117

图像均值漂移分割

图像均值漂移分割是一种无监督的图像分割方法，前面我们在跟踪相关的内容介绍过均值迁移算法，知道均值迁移可以找到图像中特征直方图空间的峰值分布，这里我们还是使用均值迁移，让它去不断分割找到空间颜色分布的峰值，然后根据峰值进行相似度合并，解决过度分割问题，得到最终的分割图像，对于图像多维度数据颜色值(RGB)与空间位置(x,y)，所以需要两个窗口半径，一个是空间半径、另外一个是颜色半径，经过均值漂移窗口的所有的像素点会具有相同的像素值，OpenCV中均值漂移分割的API如下：
void cv::pyrMeanShiftFiltering(
	InputArray src,
	OutputArray dst,
	double sp,
	double sr,
	int maxLevel = 1,
	TermCriteria termcrit = TermCriteria(TermCriteria::MAX_ITER+TermCriteria::EPS, 5, 1) 
)
src 输入图像
dst输出结果
sp 表示空间窗口大小
sr 表示表示颜色空间
maxLevel表示金字塔层数，总层数为maxlevel+1
termcrit表示停止条件
