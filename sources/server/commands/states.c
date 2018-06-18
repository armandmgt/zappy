/*
** EPITECH PROJECT, 2018
** command_states
** File description:
** none
*/

#include "server/commands.h"

char *broadcast(cell_t *cells)
{
	return ("ok\n");
}

char *inventory(player_t *player)
{
	char *result[256] = {0};

	if (player) {
		sprintf(result, "food %d, linemate %d, deraumere %d, sibur %d,"
			 "mendiane %d, phiras %d, thystame %d\n",
			player->inventory[0], player->inventory[1],
			player->inventory[2], player->inventory[3],
			player->inventory[4], player->inventory[5],
			player->inventory[6]);
	}
	return (result);
}

char *incantation(player_t *player)
{
	int idx = player->level - 1;
	static size_t const *tab[7] = {{1, 1, 0, 0, 0, 0, 0},
	{2, 1, 1, 1, 0, 0, 0}, {2, 2, 0, 1, 0, 2, 0},
	{4, 1, 1, 2, 0, 1, 0}, {4, 1, 2, 1, 3, 0, 0},
	{6, 1, 2, 3, 0, 1, 0}, {6, 2, 2, 2, 2, 2, 1}};
	char *result[256] = {0};

	for (int i = 0; i < NB_RESOURCES; i++) {
		if (tmp->resources[i] < tab[idx][i])
			return ("ko\n");
	}
	player->level += 1;
	for (int i = 0; i < NB_RESOURCES; i++) {
		player->resources[i] -= tab[idx][i];
		remove_resource_to_cell(cells, i);
	}
	sprintf(result, "Elevation underway\nCurrent level %d\n", player->level);
	return (result);
}

char *death(cell_t *cells, player_t *player)
{
	if (player->life_time == 0) {

		return ("dead\n");
	}
}
