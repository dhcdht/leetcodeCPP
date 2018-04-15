cmake_minimum_required(VERSION 3.6)
project(leetcodeCPP)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -Wno-deprecated)

file(GLOB sources "*.hpp")
set(SOURCE_FILES main.cpp helper.hpp ${sources})
add_executable(leetcodeCPP ${SOURCE_FILES})