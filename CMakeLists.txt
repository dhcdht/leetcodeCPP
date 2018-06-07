cmake_minimum_required(VERSION 3.6)
project(leetcodeCPP)

set(CMAKE_CXX_STANDARD 14)

file(GLOB sources "*.hpp")
set(SOURCE_FILES main.cpp helper.hpp ${sources})
add_executable(leetcodeCPP ${SOURCE_FILES})