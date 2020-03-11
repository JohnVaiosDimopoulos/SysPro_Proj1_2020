cmake_minimum_required(VERSION 3.15)
project(Proj_1)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(Tests)
add_executable(Proj_1 main.cpp Argument_Manager/Argument_Manager.cpp Argument_Manager/Argument_Manager.h Argument_Data/Argument_Data.cpp Argument_Data/Argument_Data.h)