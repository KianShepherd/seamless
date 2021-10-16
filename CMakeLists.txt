cmake_minimum_required(VERSION 3.20)
project(seamless_cpu)

set(CMAKE_CXX_STANDARD 14)

include_directories(cpu/include)

add_executable(seamless_cpu
        cpu/include/cpu.h
        cpu/src/cpu.cpp
        cpu/main.cpp)
