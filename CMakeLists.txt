cmake_minimum_required(VERSION 3.20)
project(projekt)

set(CMAKE_CXX_STANDARD 14)

add_executable(projekt classes/main.cpp classes/List.cpp headers/List.h classes/Heap.cpp headers/Heap.h classes/DynamicArray.cpp headers/DynamicArray.h classes/RedBlackTree.cpp headers/RedBlackTree.h)
