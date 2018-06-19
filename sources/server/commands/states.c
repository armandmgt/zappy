/*
** EPITECH PROJECT, 2018
** command_states
** File description:
** none
*/

#include <stdio.h>
#include <string.h>
#include "server/commands.h"
#include "common/tools.h"
#include "common/linked_list.h"
#include "server/server.h"

bool broadcast(server_t *server, client_t *client, char const *args)
{
	return (true);
}

bool inventory(server_t *UNUSED(server), client_t *client, char const *UNUSED(args))
{
	player_t *tmp = client->infos;

	if (client->infos) {
		dprintf(client->sock, "food %d, linemate %d, deraumere %d, "
			"sibur %d, mendiane %d, phiras %d, thystame %d\n",
			tmp->inventory[0], tmp->inventory[1],
			tmp->inventory[2], tmp->inventory[3],
			tmp->inventory[4], tmp->inventory[5],
			tmp->inventory[6]);
	}
	return (true);
}

int count_player(cell_t *cell, client_t *client)
{
	int cmpt = 0;
	client_t *tmp_client;

	for (list_t *tmp = cell->players; tmp != NULL; tmp = tmp->next) {
		tmp_client = tmp->data;
		if (strcmp(tmp_client->team->name, client->team->name) == 0)
			cmpt = cmpt + 1;
	}
	return (cmpt);
}

bool incantation(server_t *server, client_t *client, char const *UNUSED(args))
{
	int idx = client->infos->level - 1;
	static uint16_t const tab[7][7] = {{1, 1, 0, 0, 0, 0, 0},
	{2, 1, 1, 1, 0, 0, 0}, {2, 2, 0, 1, 0, 2, 0},
	{4, 1, 1, 2, 0, 1, 0}, {4, 1, 2, 1, 3, 0, 0},
	{6, 1, 2, 3, 0, 1, 0}, {6, 2, 2, 2, 2, 2, 1}};
	cell_t *cell = get_cell_at(&server->map_infos, client->infos->pos.x,
		client->infos->pos.y);

	if (count_player(cell, client) != tab[idx][0])
		return (false);
	for (int i = 0; i < NB_RESOURCE; i++) {
		if (client->infos->inventory[i] < tab[idx][i + 1])
			return (false);
	}
	client->infos->level += 1;
	for (int i = 0; i < NB_RESOURCE; i++) {
		client->infos->inventory[i] -= tab[idx][i + 1];
		remove_resource_on_cell(cell, i, tab[idx][i + 1]);
	}
	dprintf(client->sock, "Elevation underway\nCurrent level "
		"%d\n", client->infos->level);
	return (true);
}

bool death(server_t *UNUSED(server), client_t *client, char const *UNUSED(args))
{
	if (client->infos->lifetime == 0) {
		dprintf(client->sock, "dead\n");
		return (true);
	}
	return (false);
}
