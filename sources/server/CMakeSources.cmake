set(CORE
	main.c

    options_parsing/parse_options.c
    options_parsing/parse_functions.c

    connexion/connexion.c
    connexion/communication.c
    connexion/new_connection.c

    ../common/linked_list.c

    commands/actions.c
    commands/directions.c
    commands/states.c
)

set(SRCS
	${CORE})