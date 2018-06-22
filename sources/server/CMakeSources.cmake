set(CORE
	main.c

    options_parsing/parse_options.c
    options_parsing/parse_functions.c

    connexion/connexion.c
    connexion/communication.c
    connexion/new_connection.c
    connexion/food.c
	connexion/spawn_resources.c

    commands/client_commands.c
    commands/actions.c
    commands/directions.c
    commands/states.c
    commands/eject.c
	commands/look.c
	commands/print_content.c
    commands/content.c
    commands/player_stat.c
    commands/misc.c
    commands/print_in_gui.c

    ../common/linked_list.c
    ../common/tools.c
    ../common/cir_buffer.c
    ../common/init_cir_buffer.c
	../common/count_in_team.c

	map/map_generation.c
	map/map_allocation.c
	map/cell_management.c
	map/cell_infos.c
)

set(SRCS
	${CORE})