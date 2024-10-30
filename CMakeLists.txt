cmake_minimum_required(VERSION 3.13)
project(uutf_example)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_subdirectory(example)
add_subdirectory(test)
