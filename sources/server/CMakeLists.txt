include(CMakeSources.cmake)

project(zappy_server)

add_executable(${PROJECT_NAME} ${SRCS})

#Headers
target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_SOURCE_DIR}/include/server)
target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_SOURCE_DIR}/include/common)

#CFlags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
