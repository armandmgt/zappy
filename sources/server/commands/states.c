/*
** EPITECH PROJECT, 2018
** command_states
** File description:
** none
*/

#include <stdio.h>
#include "server/commands.h"

char *broadcast(client_t *client)
{
	return ("ok\n");
}

char *inventory(client_t *client)
{
	char *result[256] = {0};

	if (client->player) {
		sprintf(result, "food %d, linemate %d, deraumere %d, sibur %d,"
			 "mendiane %d, phiras %d, thystame %d\n",
			client->player->inventory[0], client->player->inventory[1],
			client->player->inventory[2], client->player->inventory[3],
			client->player->inventory[4], client->player->inventory[5],
			client->player->inventory[6]);
	}
	return (result);
}

int count_player(cell_t *cells, player_t *player)
{
	int cmpt = 0;

	for (player_t *tmp = cells->player; tmp != NULL; tmp = tmp->next) {
		if (strcmp(tmp->team, player->team) == 0)
			cmpt = cmpt + 1;
	}
	return (cmpt);
}

char *incantation(cell_t *cells, player_t *player)
{
	int idx = player->level - 1;
	static size_t const *tab[7] = {{1, 1, 0, 0, 0, 0, 0},
	{2, 1, 1, 1, 0, 0, 0}, {2, 2, 0, 1, 0, 2, 0},
	{4, 1, 1, 2, 0, 1, 0}, {4, 1, 2, 1, 3, 0, 0},
	{6, 1, 2, 3, 0, 1, 0}, {6, 2, 2, 2, 2, 2, 1}};
	char *result[256] = {0};

	if (count_player(cells, player) != tab[idx][0])
		return ("ko\n");
	for (int i = 0; i < NB_RESOURCES; i++) {
		if (tmp->resources[i] < tab[idx][i + 1])
			return ("ko\n");
	}
	player->level += 1;
	for (int i = 0; i < NB_RESOURCES; i++) {
		player->resources[i] -= tab[idx][i + 1];
		remove_resource_to_cell(cells, i);
	}
	sprintf(result, "Elevation underway\nCurrent level %d\n", player->level);
	return (result);
}

char *death(client_t *client)
{
	if (client->player->life_time == 0) {
		return ("dead\n");
	}
}
