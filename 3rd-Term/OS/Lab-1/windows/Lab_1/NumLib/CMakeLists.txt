cmake_minimum_required(VERSION 3.23)
project(NumLib)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-fPIC)

set(NUMBER_HEADER num.h)
set(NUMBER_SOURCE num.cpp)
add_library(Number STATIC ${NUMBER_SOURCE} ${NUMBER_HEADER})
