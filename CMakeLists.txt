cmake_minimum_required(VERSION 3.10)

project(zappy)

set(CMAKE_C_STANDARD 99)

include_directories(include include/server include/ai)
add_subdirectory(sources)
