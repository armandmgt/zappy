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
#include "parse_functions.c"

static int help(options_t *, int *);
static int port(options_t *, int *);
static int size(options_t *, int *);
static int names(options_t *, int *);
static int clientNb(options_t *, int *);
static int freq(options_t *, int *);

int parse_options(int argc, char *const *argv, options_t *opts)
{
	int opt;
	int error = 0;
	static option_parser_t parse_options[] = {
		{'h', &help}, {'p', &port}, {'x', &size}, {'y', &size},
		{'n', &names}, {'c', &clientNb}, {'f', &freq}
	};

	while ((opt = getopt(argc, argv, "hp:x:y:nc:f:")) && error == 0) {
		for (size_t i = 0; i < 7; i++) {
			if (opt == parse_options[i].opt == opt &&
				(parse_options[i].func(opts, &error) || error))
				return (1);
		}
	}
	return (error);
}

static int help(options_t * UNUSED(opts), int * UNUSED(error))
{
	return (1);
}

static unsigned long parse_number(int *error)
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

static team_t *parse_teams(int *error, char *const argv[])
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
