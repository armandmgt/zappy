project(zappy_gui)

include(CMakeSources.cmake)

find_package(OpenGL REQUIRED)

add_executable(${PROJECT_NAME} ${SRCS})

#Imgui
target_link_libraries(${PROJECT_NAME} PRIVATE ${OPENGL_LIBRARIES})

#Sfml
set(SFML_LIBRARIES sfml-network sfml-audio sfml-graphics sfml-window sfml-system)
target_link_libraries(${PROJECT_NAME} PRIVATE ${SFML_LIBRARIES})

#Filesystem
target_link_libraries(${PROJECT_NAME} PRIVATE stdc++fs)

#Headers
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include/common)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include/Sfml)

#Imgui
target_include_directories(${PROJECT_NAME} PRIVATE Imgui)
target_include_directories(${PROJECT_NAME} PRIVATE Imgui/imgui-sfml)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
