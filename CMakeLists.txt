cmake_minimum_required(VERSION 3.10)

project(LocalBinaryPattern)

find_package(OpenCV REQUIRED)

add_executable(lbp src/main.cpp)
target_link_libraries(lbp PRIVATE ${OpenCV_LIBS})
