cmake_minimum_required(VERSION 3.16)

project(ArrayAndStrings)

add_executable(hash_table hash_table.cpp)
target_include_directories(hash_table PRIVATE ../Linked_lists)