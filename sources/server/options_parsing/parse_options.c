/*
** EPITECH PROJECT, 2017
** zappy
** File description:
** Created by armandmgt,
*/

#include <getopt.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"
#include "common/tools.h"
#include "parse_functions.h"

static int help(options_t *, int *, char * const *);

int parse_options(int argc, char *const *argv, options_t *opts)
{
	int opt;
	int error = 0;
	int optcount = 0;
	static const option_parser_t parse_options[] = {
		{'h', &help}, {'p', &port}, {'x', &size}, {'y', &size},
		{'n', &names}, {'c', &client_nb}, {'f', &freq}
	};

	while ((opt = getopt(argc, argv, "hp:x:y:nc:f:")) != -1 && error == 0) {
		for (size_t i = 0; i < 7; i++) {
			if (opt == parse_options[i].opt &&
				(parse_options[i].func(opts, &error, argv) ||
					error))
				return (1);
		}
		optcount++;
	}
	return (error || optcount != 6);
}

static int help(options_t * UNUSED(opts), int * UNUSED(error),
	char * const * UNUSED(argv))
{
	return (1);
}

unsigned long parse_number(int *error)
{
	char *end_ptr = NULL;
	unsigned long nb = strtoul((const char *)optarg, &end_ptr, 10);

	if (*end_ptr) {
		*error = 1;
		return (0);
	} else {
		return (nb);
	}
}

team_t *parse_teams(int *error, char * const *argv)
{
	team_t *teams = NULL;
	team_t *elem;
	int i = optind;

	while (argv[i]) {
		if (!(elem = malloc(sizeof(*teams)))) {
			*error = 1;
			return (NULL);
		}
		strncpy(elem->name, argv[i++], TEAM_NAME_LEN);
		elem->next = teams;
		teams = elem;
	}
	return (teams);
}
