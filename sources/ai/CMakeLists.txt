include(CMakeSources.cmake)

project(zappy_ai)

add_executable(${PROJECT_NAME} ${SRCS})

#GUI
include(${CMAKE_SOURCE_DIR}/cmake/FindSFML.cmake)
find_package(SFML 2 COMPONENTS network audio graphics window system)
if (SFML_FOUND)
        include_directories(${SFML_INCLUDE_DIR})
        target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()

#Headers
target_include_directories(${PROJECT_NAME} PRIVATE ../../include)
target_include_directories(${PROJECT_NAME} PRIVATE ../../include/ai)
target_include_directories(${PROJECT_NAME} PRIVATE ../../include/common)
target_include_directories(${PROJECT_NAME} PRIVATE ../../include/Sfml)
target_include_directories(${PROJECT_NAME} PRIVATE ../../include/Imgui)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
