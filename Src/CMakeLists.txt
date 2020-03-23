cmake_minimum_required(VERSION 3.15)
project(Proj_1)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(Tests)
add_executable(Proj_1 main.cpp Argument_Manager/Argument_Manager.cpp Argument_Manager/Argument_Manager.h Argument_Data/Argument_Data.cpp Argument_Data/Argument_Data.h System_Data/System_Data.cpp System_Data/System_Data.h Initializer/Initializer.cpp Initializer/Initializer.h Date/Date.cpp Date/Date.h Patient_Record/Patient_Record.cpp Patient_Record/Patient_Record.h Hash_Table/Hash_Table.cpp Hash_Table/Hash_Table.h Hash_Table/Hash_Bucket_Node.cpp Hash_Table/Hash_Bucket_Node.h AVL_Tree/AVL_Tree.cpp AVL_Tree/AVL_Tree.h AVL_Tree/AVL_Tree_Node.cpp AVL_Tree/AVL_Tree_Node.h Patient_List/Patients_List.cpp Patient_List/Patients_List.h Generic_List/Generic_List.h)