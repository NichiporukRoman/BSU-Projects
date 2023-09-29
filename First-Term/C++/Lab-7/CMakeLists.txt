cmake_minimum_required(VERSION 3.20)
project(untitled4)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled4 main.cpp Student.cpp StudentAfterFirstSession.cpp StudentAfterSecondSession.cpp)

add_subdirectory(tests)
