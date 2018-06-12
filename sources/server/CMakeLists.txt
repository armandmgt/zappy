set(SOURCES
        main.c
        ../../include/common/tools.h
        ../../include/server/server.h
        options_parsing/parse_options.c options_parsing/parse_functions.c)

add_executable(zappy_server ${SOURCES})
