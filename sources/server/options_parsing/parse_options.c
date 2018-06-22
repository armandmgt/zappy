/*
** EPITECH PROJECT, 2017
** zappy
** File description:
** Created by armandmgt,
*/

#include <getopt.h>
#include <stdlib.h>
#include <string.h>
#include <server/gui_magic.h>
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

static void create_team(list_t **teams , int *error, char const * const str)
{
	team_t *elem;

	if (!(elem = calloc(1, sizeof(*elem)))) {
		*error = 1;
		return;
	}
	strncpy(elem->name, str, TEAM_NAME_LEN);
	add_elem_at_front(teams, elem);
}

list_t *parse_teams(int *error, char *const *argv)
{
	list_t *teams = NULL;
	int i = optind;

	while (argv[i]) {
		create_team(&teams, error, argv[i++]);
		if (*error == 1)
			return (NULL);
	}
	create_team(&teams, error, GUI_NAME);
	if (*error == 1)
		return (NULL);
	return (teams);
}
