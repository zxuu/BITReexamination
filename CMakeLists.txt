#cmake_minimum_required(VERSION 3.14)
#project(BITReexamination C)
#set(CMAKE_C_STANDARD 99)
#add_executable(BITReexamination test.c)

cmake_minimum_required(VERSION 3.14)
project(BITReexamination)
set(CMAKE_CXX_STANDARD 14)
add_executable(BITReexamination  DataStruct/KeyValue/ShuangXiangMap.cpp)