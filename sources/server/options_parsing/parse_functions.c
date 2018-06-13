/*
** EPITECH PROJECT, 2017
** zappy
** File description:
** Created by armandmgt,
*/

#include <stdio.h>
#include <getopt.h>
#include "parse_functions.h"
#include "common/tools.h"

int port(options_t *opts, int *error, char * const * UNUSED(argv))
{
	opts->port = (uint16_t)parse_number(error);
	return (0);
}

int size(options_t *opts, int *error, char * const * UNUSED(argv))
{
	static int calls = 0;

	if (calls++ == 0)
		opts->width = (unsigned int)parse_number(error);
	else
		opts->height = (unsigned int)parse_number(error);
	return (0);
}

int names(options_t *opts, int *error, char * const *argv)
{
	opts->teams = parse_teams(error, argv);
	return (0);
}

int client_nb(options_t *opts, int *error, char * const *
	UNUSED(argv))
{
	opts->maxClients = (unsigned int)parse_number(error);
	return (0);
}

int freq(options_t *opts, int *error, char * const * UNUSED(argv))
{
	opts->freq = (unsigned int)parse_number(error);
	return (0);
}
