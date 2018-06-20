/*
** EPITECH PROJECT, 2017
** Project
** File description:
** Created by armandmgt, misc
*/

#include <stdio.h>
#include <stdlib.h>
#include "gui_commands.h"
#include "tools.h"

bool tna(server_t *server, client_t *client, char *UNUSED(av))
{
	team_t *team;

	for (list_t *cur = server->teams; cur; cur = cur->next) {
		team = cur->data;
		dprintf(client->sock, "tna %s\n", team->name);
	}
	return (true);
}

bool sgt(server_t *server, client_t *client, char *UNUSED(av))
{
	dprintf(client->sock, "sgt %u\n", server->freq);
	return (true);
}

bool sst(server_t *server, client_t *client, char *av)
{
	char *endptr;

	uint32_t num = (uint32_t)strtol(av, &endptr, 10);
	if (*endptr)
		return (false);
	server->freq = num;
	dprintf(client->sock, "sst %u\n", server->freq);
	return (true);
}
