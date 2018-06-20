/*
** EPITECH PROJECT, 2017
** zappy
** File description:
** Created by armandmgt,
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "server.h"
#include "common/tools.h"

static char const USAGE[] = "USAGE: %s -p port -x width -y height"
	" -n name1 name2 ... -c clientsNb -f freq\n"
	"port\t\tis the port number\n"
	"width\t\tis the width of the world\n"
	"height\t\tis the height of the world\n"
	"nameX\t\tis the name of the team X\n"
	"clientsNb\tis the number of authorized clients per team\n"
	"freq\t\tis the reciprocal of time unit for execution of actions\n";

int main(int argc, char * const *argv)
{
	options_t opts = {0};
	server_t server = {0};

	if (parse_options(argc, argv, &opts)) {
		fprintf(stderr, USAGE, argv[0]);
		return (FAILURE);
	}
	if (init_server(&opts, &server) == -1 || run_server(&server) == -1)
		return (FAILURE);
	free_list(server.teams, free);
	free_list(server.clients, free);
	free_map(&server.map_infos);
	close(server.sock);
	return (SUCCESS);
}
