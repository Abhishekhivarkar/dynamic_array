cmake_minimum_required(VERSION 3.16)

project(dynamic_array C)

set(CMAKE_C_STANDARD 99)

include_directories(include)

file(GLOB_RECURSE SOURCES
    src/*.c
)

add_executable(dynamic_array ${SOURCES})