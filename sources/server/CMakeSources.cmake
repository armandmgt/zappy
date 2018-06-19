set(CORE
	main.c

    options_parsing/parse_options.c
    options_parsing/parse_functions.c

    connexion/connexion.c
    connexion/communication.c
    connexion/new_connection.c

    commands/client_parsing.c
    commands/content.c
    commands/player_stat.c
    commands/print_in_gui.c

    ../common/linked_list.c
    ../common/tools.c
    ../common/cir_buffer.c
    ../common/init_cir_buffer.c

	map/map_generation.c
	map/map_allocation.c
	map/cell_management.c
	map/cell_infos.c
)

set(SRCS
	${CORE})