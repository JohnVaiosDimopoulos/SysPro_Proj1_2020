cmake_minimum_required(VERSION 3.15)
project(Proj_1)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(Tests)
add_executable(Proj_1 main.cpp Argument_Manager/Argument_Manager.cpp Argument_Manager/Argument_Manager.h Argument_Data/Argument_Data.cpp Argument_Data/Argument_Data.h System_Data/System_Data.cpp System_Data/System_Data.h Initializer/Initializer.cpp Initializer/Initializer.h Patients_List/Patients_List.cpp Patients_List/Patients_List.h Patients_List/Patients_List_Node.cpp Patients_List/Patients_List_Node.h Date/Date.cpp Date/Date.h Patient_Record/Patient_Record.cpp Patient_Record/Patient_Record.h)