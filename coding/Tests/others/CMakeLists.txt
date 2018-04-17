cmake_minimum_required(VERSION 3.8)
project(Order)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES AfterOrder.cpp)
add_executable(Order ${SOURCE_FILES})
