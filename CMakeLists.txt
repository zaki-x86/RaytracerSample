cmake_minimum_required(VERSION 3.15)

project(raytracer02)

set(CMAKE_CXX_STANDARD 17)

add_executable(raytracer02 
    main.cpp)

target_include_directories(raytracer02 PRIVATE
    ${CMAKE_SOURCE_DIR}/maths
    ${CMAKE_SOURCE_DIR}/utils
    ${CMAKE_SOURCE_DIR}/external)

# link cmath library
target_link_libraries(raytracer02 PRIVATE m)