cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project (raytracer VERSION 1.0)


# Source
set ( COMMON_ALL
  # src/rtweekend.h
  # src/camera.h
  # src/ray.h
  # src/vec3.h
  # src/mesh_obj.h
  # src/scene.h
)

set(CMAKE_BUILD_TYPE "Release")

add_executable(raytracer src/main.cpp ${COMMON_ALL})
target_include_directories(raytracer PUBLIC src)


# add_executable(tests src/tests.cpp)
## target_include_directories(tests PRIVATE include)


