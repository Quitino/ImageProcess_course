echo 基于dlib hog的人脸检测

./face_detection_dlib_hog videos/baby.mp4
sleep 2s
./face_detection_dlib_hog videos/neck-exercise.mp4
sleep 2s
./face_detection_dlib_hog videos/rowing.mp4
sleep 2s

echo  基于Haar的人脸检测

./face_detection_opencv_haar videos/baby.mp4
sleep 2s

./face_detection_opencv_haar videos/neck-exercise.mp4
sleep 2s

./face_detection_opencv_haar videos/rowing.mp4
sleep 2s


echo  基于OpenCV DNN的人脸检测

./face_detection_opencv_dnn  videos/baby.mp4
sleep 2s
./face_detection_opencv_dnn  videos/neck-exercise.mp4
sleep 2s
./face_detection_opencv_dnn  videos/rowing.mp4
sleep 2s



echo 基于dlib mmod的人脸检测
./face_detection_dlib_mmod  videos/baby.mp4
sleep 2s
./face_detection_dlib_mmod  videos/neck-exercise.mp4
sleep 2s
./face_detection_dlib_mmod  videos/rowing.mp4
sleep 2s
