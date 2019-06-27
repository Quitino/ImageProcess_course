cmake_minimum_required(VERSION 2.8.12)

PROJECT(face_detection)

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS})

include(./dlib/dlib/dlib/cmake)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/run)


set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/run)

add_executable(face_detection_opencv_haar src/face_detection_opencv_haar.cpp)
target_link_libraries(face_detection_opencv_haar ${OpenCV_LIBS} dlib::dlib)

add_executable(face_detection_opencv_dnn src/face_detection_opencv_dnn.cpp)
target_link_libraries(face_detection_opencv_dnn ${OpenCV_LIBS} dlib::dlib)

add_executable(face_detection_dlib_hog src/face_detection_dlib_hog.cpp)
target_link_libraries(face_detection_dlib_hog ${OpenCV_LIBS} dlib::dlib)

add_executable(face_detection_dlib_mmod src/face_detection_dlib_mmod.cpp)
target_link_libraries(face_detection_dlib_mmod ${OpenCV_LIBS} dlib::dlib)

add_executable(run-all src/run-all.cpp)
target_link_libraries(run-all ${OpenCV_LIBS} dlib::dlib)


