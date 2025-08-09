cmake_minimum_required(VERSION 3.30)
project(test)

set(CMAKE_CXX_STANDARD 23)
file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/leetcode/src/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_executable(test ${SRC_FILES})
