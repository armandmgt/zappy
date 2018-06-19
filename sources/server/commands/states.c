/*
** EPITECH PROJECT, 2018
** command_states
** File description:
** none
*/

#include <stdio.h>
#include "server/commands.h"
#include "common/tools.h"

bool broadcast(server_t *server, client_t *client, char *args)
{
	return (true);
}

bool inventory(server_t *UNUSED(server), client_t *client, char *UNUSED(args))
{
	player_t *tmp = client->infos;

	if (client && client->infos) {
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

	for (client_t *tmp = cells->players; tmp != NULL; tmp = tmp->next) {
		if (strcmp(tmp->team, cells->players->team) == 0)
			cmpt = cmpt + 1;
	}
	return (cmpt);
}

bool incantation(server_t *server, client_t *client, char *UNUSED(args))
{
	int idx = client->infos->level - 1;
	static size_t const *tab[7] = {{1, 1, 0, 0, 0, 0, 0},
	{2, 1, 1, 1, 0, 0, 0}, {2, 2, 0, 1, 0, 2, 0},
	{4, 1, 1, 2, 0, 1, 0}, {4, 1, 2, 1, 3, 0, 0},
	{6, 1, 2, 3, 0, 1, 0}, {6, 2, 2, 2, 2, 2, 1}};
	cell_t cell = server->map_infos->cells[client->infos.y][client->infos.x];

	if (count_player(cell, client) != tab[idx][0])
		return (false);
	for (int i = 0; i < NB_RESOURCES; i++) {
		if (client->infos->inventory[i] < tab[idx][i + 1])
			return (false);
	}
	client->infos->level += 1;
	for (int i = 0; i < NB_RESOURCES; i++) {
		client->infos->inventory[i] -= tab[idx][i + 1];
		remove_resource_to_cell(cell, i);
	}
	dprintf(client->sock, "Elevation underway\nCurrent level "
		"%d\n", client->infos->level);
	return (true);
}

bool death(server_t *UNUSED(server), client_t *client, char *UNUSED(args))
{
	if (client->infos->life_time == 0) {
		dprintf(client->sock, "dead\n");
		return (true);
	}
	return (false);
}
