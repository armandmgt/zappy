########################################################################################################################
#                                                                                                                      #
#                                               HEADER FUNCTION/MACROS                                                 #
#                                                                                                                      #
########################################################################################################################

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/BCMColor.cmake)

set(PROJECT_NAME "Zappy des bg")
set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 0)
set(PROJECT_VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH})
set(SETTINGS_ORGANIZATION "${BoldCyan}Epitech${Reset}")
set(SETTINGS_APPLICATION ${PROJECT_NAME}${Reset})
set(PROJECT_AUTHOR "${BoldYellow}Renaud Melet${Reset}, ${BoldRed}Armand Mégrot${Reset}, ${BoldGreen}Thomas Burgaud${Reset}, ${BoldBlue}Thomas Derote-Parcellier${Reset}, ${BoldMagenta}Tom Rochat${Reset}, ${BoldCyan}Marianne Levée${Reset}")
set(ORGANIZATION_BUILD_MESSAGE "Organization : ${SETTINGS_ORGANIZATION}")
set(PROJECT_YEAR_COPYRIGHT "2018")
set(PROJECT_BUILD_MESSAGE  " v" ${PROJECT_VERSION} " (" ${CMAKE_BUILD_TYPE} ")")
set(COPYRIGHT_BUILD_MESSAGE "Copyright (c) ${PROJECT_YEAR_COPYRIGHT}  ${PROJECT_AUTHOR}")
set(INDIE_MSG "
   _____                          _______
  |__  /__ _ _ __  _ __  _   _   / /___ /
    / // _` | '_ \\| '_ \\| | | | / /  |_ \\ 
   / /| (_| | |_) | |_) | |_| | \\ \\ ___) |
  /____\\__,_| .__/| .__/ \\__, |  \\_\\____/ 
            |_|   |_|    |___/
"
)

macro(PRINT_HEADER)
    message(" " ${BoldMagenta}${INDIE_MSG}${Reset})
    message(" ----------------------------------------------------------------------------------------------------------")
    message(" " ${BoldMagenta}${PROJECT_NAME}${Reset} ${PROJECT_BUILD_MESSAGE})
    message(" ")
    message(" " ${COPYRIGHT_BUILD_MESSAGE})
    message(" " ${EMAIL_BUILD_MESSAGE})
    message("         " ${PROJECT_AUTHOR_EMAIL2})
    message(" " ${ORGANIZATION_BUILD_MESSAGE})
    message(" ")
    message(" ----------------------------------------------------------------------------------------------------------")
endmacro()
