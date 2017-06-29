cmake_minimum_required(VERSION 3.6)
project(leetcodeCPP)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -Wno-deprecated)

set(SOURCE_FILES main.cpp 0.hpp 1.hpp 2.hpp 3.hpp 4.hpp 5.hpp 6.hpp 7.hpp 8.hpp 9.hpp 10.hpp 11.hpp 12.hpp 13.hpp 14.hpp
        15.hpp 16.hpp 17.hpp 18.hpp 19.hpp 20.hpp 21.hpp 22.hpp 23.hpp 24.hpp 25.hpp 26.hpp 27.hpp 28.hpp 29.hpp 30.hpp
        31.hpp 32.hpp 33.hpp 33.hpp 34.hpp 35.hpp 36.hpp 37.hpp 38.hpp 39.hpp 40.hpp 41.hpp 42.hpp 43.hpp 44.hpp 45.hpp
        46.hpp 47.hpp 48.hpp 49.hpp 50.hpp 51.hpp 52.hpp 53.hpp 54.hpp 55.hpp 56.hpp 57.hpp 58.hpp 59.hpp 60.hpp 61.hpp
        62.hpp 63.hpp 64.hpp 65.hpp 66.hpp)
add_executable(leetcodeCPP ${SOURCE_FILES})