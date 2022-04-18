cmake_minimum_required(VERSION 3.21)
project(CPPBasic)

set(CMAKE_CXX_STANDARD 14)

INCLUDE_DIRECTORIES("${CMAKE_CURRENT_BINARY_DIR}")
ADD_LIBRARY(ArrayFunctions SHARED ArrayFunctions.cpp ArrayFunctions.h ArrayFunctions.hpp)

ADD_EXECUTABLE(lesson5 lesson5.cpp)
TARGET_LINK_LIBRARIES(lesson5 ArrayFunctions)