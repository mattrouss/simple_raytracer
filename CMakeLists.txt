cmake_minimum_required(VERSION 3.16)
project(TP1_raytracer)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(raytracer
        src/main.cc
        src/math_types.cc
        src/math_types.hh src/image.cc src/image.hh)
