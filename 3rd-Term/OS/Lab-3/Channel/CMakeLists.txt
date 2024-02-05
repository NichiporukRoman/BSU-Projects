cmake_minimum_required(VERSION 3.23)
project(Channel)

set(CMAKE_CXX_STANDARD 20)

add_executable(Channel main.cpp buffered_channel.h)
