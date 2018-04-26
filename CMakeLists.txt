cmake_minimum_required(VERSION 3.10)
project(TravelRight)

set(CMAKE_CXX_STANDARD 11)

add_executable(TravelRight main.cpp ApiInterface.cpp ApiInterface.h)

target_link_libraries(TravelRight curl)