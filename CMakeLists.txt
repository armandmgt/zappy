cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)

#Easy Doc
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(${CMAKE_SOURCE_DIR}/cmake/BCMColor.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/Header.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/Utils.cmake)

PRINT_HEADER()
PRINT_PLATFORM()

add_subdirectory(sources)
