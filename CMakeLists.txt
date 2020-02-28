cmake_minimum_required(VERSION 3.16)
project(TP1_raytracer)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_executable(raytracer
        src/main.cc
        src/math_types.cc
        src/math_types.hh src/image.cc src/image.hh src/scene.cc src/scene.hh src/textures.cc src/textures.hh src/object.cc src/object.hh src/light.cc src/light.hh src/camera.cc src/camera.hh src/color.cc src/color.hh src/blob.cc src/blob.hh src/triangle_index.hh)
