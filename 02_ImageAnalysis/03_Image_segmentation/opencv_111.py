import numpy as np
import cv2 as cv

image = cv.imread('D:/projects/opencv_tutorial/data/images/toux.jpg')

# 构建图像数据
data = image.reshape((-1,3))
data = np.float32(data)

# 图像分割
criteria = (cv.TERM_CRITERIA_EPS + cv.TERM_CRITERIA_MAX_ITER, 10, 1.0)
num_clusters = 4
ret,label,center=cv.kmeans(data, num_clusters, None, criteria, num_clusters, cv.KMEANS_RANDOM_CENTERS)
center = np.uint8(center)
res = center[label.flatten()]

# 显示
result = res.reshape((image.shape))
cv.imshow('kmeans-image-demo',result)

cv.waitKey(0)
cv.destroyAllWindows()