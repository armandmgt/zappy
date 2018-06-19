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

bool connect_nbr(server_t *server, client_t *client, char const *UNUSED(args))
{
	int cmpt = 0;
	client_t *tmp;
	list_t *tmp_list;

	while (tmp_list) {
		tmp = tmp_list->data;
		if (strcmp(tmp->team->name, client->team->name) == 0)
			cmpt += 1;
		tmp_list = tmp_list->next;
	}
	dprintf(client->sock, "%d\n", client->team->max_members - cmpt);
	return (true);
}

bool birth(server_t *UNUSED(server), client_t *client, char const *UNUSED(args))
{
	client->team->max_members += 1;
	client->infos->direction = rand() % 4;
	client->infos->level = 1;
	return (true);
}

bool eject(server_t *server, client_t *client, char const *UNUSED(args))
{
	vec2i_t pos;
	list_t *tmp = server->map_infos.map[client->infos->pos.y][client->infos->pos.x].players;
	client_t *cpy;

	while (tmp) {
		cpy = tmp->data;
		switch (cpy->infos->direction)
		{
			case (NORTH):
			pos = (vec2i_t){cpy->infos->pos.x, cpy->infos->pos.y + 1};
			dprintf(cpy->sock, "eject: S\n");
			break;
			case (EAST):
			pos = (vec2i_t){cpy->infos->pos.x + 1, cpy->infos->pos.y};
			dprintf(cpy->sock, "eject: W\n");
			break;
			case (SOUTH):
			pos = (vec2i_t){cpy->infos->pos.x, cpy->infos->pos.y - 1};
			dprintf(cpy->sock, "eject: N\n");
			break;
			case (WEST):
			pos = (vec2i_t){cpy->infos->pos.x - 1, cpy->infos->pos.y};
			dprintf(cpy->sock, "eject: E\n");
			break;
		}
		add_elem_at_front(&server->map_infos.map[pos.y][pos.x].players, tmp);
		remove_elem(&server->map_infos.map[pos.y][pos.x].players, tmp);
		tmp = tmp->next;
	}
	return (true);
}

bool take(server_t *server, client_t *client, char const *args)
{
	int nb = atoi(args);
	cell_t *cell = get_cell_at(&server->map_infos,
		client->infos->pos.x, client->infos->pos.y);

	if (cell && cell->resource[nb]) {
		client->infos->inventory[nb] += 1;
		remove_resource_on_cell(cell, (resource_t)nb, 1);
		return (true);
	}
	return (false);
}

bool set(server_t *server, client_t *client, char const *args)
{
	int nb = atoi(args);
	cell_t *cell = get_cell_at(&server->map_infos,
		client->infos->pos.x, client->infos->pos.y);

	if (cell && client->infos->inventory[nb]) {
		client->infos->inventory[nb] -= 1;
		add_resource_to_cell(cell, (resource_t)nb, 1);
		return (true);
	}
	return (false);
}
