cmake_minimum_required(VERSION 3.0)
project(OpenCV_4th)
find_package(OpenCV REQUIRED PATHS $ENV{HOME}/mylib/lib)
include_directories(${OpenCV_INCLUDE_DIRS})
set(SOURCES OpenCV_4th.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})