cmake_minimum_required(VERSION 3.23)
project(Dll)

set(CMAKE_CXX_STANDARD 14)

add_library(NumLib ../NumLib/cmake-build-debug/libNumLib.a ../NumLib/num.cpp)

add_library(Dll SHARED vector.cpp)

target_link_directories(Dll PUBLIC vector.cpp vector.h)