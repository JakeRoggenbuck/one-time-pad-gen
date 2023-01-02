cmake_minimum_required(VERSION 3.3)
project(otpg)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/build/debug")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

file(GLOB_RECURSE SOURCES src/*.c)

add_executable(otpg ${SOURCES} termcolor-c/src/termcolor.c)
include_directories(${PROJECT_SOURCE_DIR}/termcolor-c/src)
target_include_directories(otpg PRIVATE src)
