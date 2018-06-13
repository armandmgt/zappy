set(CORE
	main.c

    options_parsing/parse_options.c
    options_parsing/parse_functions.c

    connexion/connexion.c
    connexion/communication.c

    commands/actions.c
    commands/directions.c
    commands/states.c
)

set(SRCS
	${CORE})