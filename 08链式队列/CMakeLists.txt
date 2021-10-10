cmake_minimum_required(VERSION 3.20)
project(08 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(08
        linkqueue.c
        linkqueue.h
        main.c)
