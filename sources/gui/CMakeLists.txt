project(zappy_gui)

include(CMakeSources.cmake)


set(CMAKE_CXX_FLAGS "-Wextra -Wall")
add_executable(${PROJECT_NAME} ${SRCS})

#GUI
set(SFML_LIBRARIES sfml-network sfml-audio sfml-graphics sfml-window sfml-system)
target_link_libraries(${PROJECT_NAME} PRIVATE ${SFML_LIBRARIES})

#Filesystem
target_link_libraries(${PROJECT_NAME} PRIVATE stdc++fs)

#Headers
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include/common)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include/Sfml)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include/Imgui)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
