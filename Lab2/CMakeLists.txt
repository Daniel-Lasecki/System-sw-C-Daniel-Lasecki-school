cmake_minimum_required(VERSION 3.10.0)
project(lab2 VERSION 0.1.0 LANGUAGES C)


set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_executable(lab2 lab2.c)

include(CTest)
enable_testing()