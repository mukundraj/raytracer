cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project (raytracer VERSION 1.0)

add_executable(raytracer src/main.cpp )
target_include_directories(raytracer PUBLIC src)
