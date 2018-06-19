set(CORE
	main.c

    options_parsing/parse_options.c
    options_parsing/parse_functions.c

    connexion/connexion.c
    connexion/communication.c
    connexion/new_connection.c

    commands/client_commands.c

    ../common/linked_list.c

	map/map_generation.c
	map/map_allocation.c
	map/cell_management.c
)

set(SRCS
	${CORE})