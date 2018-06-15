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

char *inventory(cell_t *cells)
{
	if (cells->player && cells->player->inventory) {
		printf("food %d, linemate %d, deraumere %d, sibur %d, "
			"mendiane %d, phiras %d, thystame %d\n",
			cells->player->inventory[0], cells->player->inventory[1],
			cells->player->inventory[2], cells->player->inventory[3],
			cells->player->inventory[4], cells->player->inventory[5],
			cells->player->inventory[6]);
	}
	return ("[minerals]\n");
}

char *incantation(cell_t *cells)
{
	int idx = cells->player->level - 1;
	static const size_t *tab[7] = {{1, 1, 0, 0, 0, 0, 0},
	{2, 1, 1, 1, 0, 0, 0}, {2, 2, 0, 1, 0, 2, 0},
	{4, 1, 1, 2, 0, 1, 0}, {4, 1, 2, 1, 3, 0, 0},
	{6, 1, 2, 3, 0, 1, 0}, {6, 2, 2, 2, 2, 2, 1}};

	for (int i = 0; i < 7; i++) {
		if (cells->player->ressources[i] < tab[idx][i])
			return ("ko\n");
	}
	cells->player->level += 1;
	for (int i = 0; i < 7; i++) {
		cells->player->ressources[i] -= tab[idx][i];
	}
	return ("Elevation underway\nCurrent level %d\n", cells->player->level);
}

char *death(cell_t *cells)
{
	return ("dead\n");
}
