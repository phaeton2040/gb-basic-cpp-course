cmake_minimum_required(VERSION 3.21)
project(CPPBasic)

set(CMAKE_CXX_STANDARD 14)

INCLUDE_DIRECTORIES("${CMAKE_CURRENT_BINARY_DIR}")
ADD_LIBRARY(ArrayLib SHARED array-lib.cpp array-lib.h)

ADD_EXECUTABLE(lesson7 lesson7.cpp)
TARGET_LINK_LIBRARIES(lesson7 ArrayLib)