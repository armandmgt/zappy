/*
** EPITECH PROJECT, 2017
** zappy
** File description:
** Created by armandmgt,
*/

#include <stdio.h>
#include "server.h"
#include "common/tools.h"

static int parse_options(int argc, char *const *argv, options_t *opts);

static char const USAGE[] = "USAGE: ./zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb\n"
	"-f freq\n"
	"port\tis the port number\n"
	"width\tis the width of the world\n"
	"height\tis the height of the world\n"
	"nameX\tis the name of the team X\n"
	"clientsNb\tis the number of authorized clients per team\n"
	"freq\tis the reciprocal of time unit for execution of actions\n";

int main(int argc, char * const argv[])
{
	options_t opts;

	if (parse_options(argc, argv, &opts)) {
		fprintf(stderr, USAGE);
		return (FAILURE);
	}
	return (SUCCESS);
}
