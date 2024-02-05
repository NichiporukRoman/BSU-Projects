
cmake_minimum_required(VERSION 3.23)
project(Test)

set(CMAKE_CXX_STANDARD 14)

add_executable(Test main.cpp)
add_library(NumLib STATIC ../NumLib/cmake-build-debug/libNumLib.a ../NumLib/num.cpp)
add_library(Dll SHARED ../Dll/cmake-build-debug/libDll.so ../Dll/vector.cpp)

target_link_libraries(Test PUBLIC NumLib)
target_link_libraries(Test PUBLIC Dll)