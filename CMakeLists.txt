cmake_minimum_required(VERSION 3.6)

set(ProjectName Walker)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

project(${ProjectName})

add_subdirectory(Walker)
add_subdirectory(Sandbox)
