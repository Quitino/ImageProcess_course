cmake_minimum_required(VERSION 2.8.12)

PROJECT(OpenCV400Research)
set (OpenCV_DIR  "/usr/local/opencv3.4.4/share/OpenCV")

find_package( OpenCV 3.4.4 REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS})



set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})


# Build tests
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

add_executable(demo Image_Denoising.cpp)
target_link_libraries(demo ${OpenCV_LIBS} )
