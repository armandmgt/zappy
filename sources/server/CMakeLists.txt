include(CMakeSources.cmake)

project(zappy_server)

add_executable(${PROJECT_NAME} ${SRCS})

#Headers
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_include_directories(${PROJECT_NAME} PRIVATE include/server)
target_include_directories(${PROJECT_NAME} PRIVATE include/common)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
