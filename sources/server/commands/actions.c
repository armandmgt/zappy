/*
** EPITECH PROJECT, 2018
** command_actions
** File description:
** none
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "server/commands.h"
#include "common/tools.h"
#include "server/map.h"
#include "server/server.h"

bool connect_nbr(server_t *server, client_t *client, char *UNUSED(args))
{
	int cmpt = 0;
	client_t *tmp;
	list_t *tmp_list = server->clients;

	while (tmp_list) {
		tmp = tmp_list->data;
		if (strcmp(tmp->team->name, client->team->name) == 0)
			cmpt += 1;
		tmp_list = tmp_list->next;
	}
	dprintf(client->sock, "%d\n", client->team->max_members - cmpt);
	return (true);
}

bool birth(server_t *UNUSED(server), client_t *client, char *UNUSED(args))
{
	client->team->max_members += 1;
	client->infos->direction = (direction_t)rand() % 4;
	client->infos->level = 1;
	dprintf(client->sock, "ok\n");
	return (true);
}

bool take(server_t *server, client_t *client, char *args)
{
	int nb = atoi(args);
	cell_t *cell = get_client_cell(&server->map_infos, client);

	if (cell && cell->resource[nb]) {
		client->infos->inventory[nb] += 1;
		remove_resource_on_cell(cell, (resource_t)nb, 1);
		dprintf(client->sock, "ok\n");
		return (true);
	}
	dprintf(client->sock, "ko\n");
	return (false);
}

bool set(server_t *server, client_t *client, char *args)
{
	int nb = atoi(args);
	cell_t *cell = get_client_cell(&server->map_infos, client);

	if (cell && client->infos->inventory[nb]) {
		client->infos->inventory[nb] -= 1;
		add_resource_to_cell(cell, (resource_t)nb, 1);
		dprintf(client->sock, "ok\n");
		return (true);
	}
	dprintf(client->sock, "ko\n");
	return (false);
}

bool broadcast(server_t *UNUSED(server), client_t *client, char *UNUSED(args))
{
	dprintf(client->sock, "ok\n");
	return (true);
}
