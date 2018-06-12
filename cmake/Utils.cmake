########################################################################################################################
#                                                                                                                      #
#                                                 UTILS CMAKE CONFIG                                                   #
#                                                                                                                      #
########################################################################################################################

if (UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif ()

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(FATAL_ERROR "${BoldYellow}Prevented in-tree built. Please create a build directory outside of the source code and call cmake from there. Thank you.${Reset}")
endif()

macro(PRINT_PLATFORM)
    if (LINUX)
        message(STATUS "${BoldRed}Platform: Linux ${ColourReset}")
    elseif (WIN32)
        message(STATUS "Platform: Windows")
    else (APPLE)
        message(STATUS "Platform: ${BoldBlue}MacOS ${Reset}")
    endif ()
endmacro()