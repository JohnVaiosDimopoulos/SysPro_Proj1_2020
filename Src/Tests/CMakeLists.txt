cmake_minimum_required(VERSION 3.15)
project(Tests)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Test Test_main.cpp Argument_Manager_Test.cpp Date_Test.cpp List_Test.cpp Initializer_Test.cpp Tokenizer_Test.cpp AVL_Test.cpp Hash_Table_Test.cpp Test_System_Commands.cpp Max_Heap_Test.cpp)

target_link_libraries(Test gtest gtest_main)