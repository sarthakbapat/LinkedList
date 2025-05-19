cmake_minimum_required(VERSION 3.19)

SET(CMAKE_C_COMPILER "/usr/bin/clang")
SET (CMAKE_CXX_COMPILER "/usr/bin/clang++")

project(LinkedList)

add_executable(LinkedList LinkedList.h LinkedList.c main.c)
