/*
** EPITECH PROJECT, 2017
** zappy
** File description:
** Created by armandmgt,
*/

#include "server.h"

static unsigned long parse_number(int *error);
static team_t *parse_teams(int *error, char *const argv[]);
//	switch (opt) {
//	case 'h':
//		return (1);
//	case 'p':
//		break;
//	case 'x':
//		break;
//	case 'y':
//		break;
//	case 'n':
//		break;
//	case 'c':
//		break;
//	case 'f':
//		break;
//	default:
//		break;
//	}

static int port(options_t *opts, int *error)
{
	opts->port = (uint16_t)parse_number(error);
}

static int size(options_t *opts, int *error)
{
	static int calls = 0;

	if (calls++ == 0)
		opts->width = (unsigned int)parse_number(error);
	else
		opts->height = (unsigned int)parse_number(error);
}

static int names(options_t *opts, int *error)
{
	opts->teams = parse_teams(error, argv);
}

static int clientNb(options_t *opts, int *error)
{
	opts->maxClients = (unsigned int)parse_number(error);
}

static int freq(options_t *opts, int *error)
{
	opts->freq = (unsigned int)parse_number(error);
}
