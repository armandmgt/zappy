/*
** EPITECH PROJECT, 2018
** command_states
** File description:
** none
*/

#include "server/server.h"

char *broadcast(void)
{
	return ("ok\n");
}

char *inventory(player_t *player)
{
	if (player && player->inventory) {
		printf("food %d, linemate %d, deraumere %d, sibur %d, "
			"mendiane %d, phiras %d, thystame %d\n",
			player->inventory[0], player->inventory[1],
			player->inventory[2], player->inventory[3],
			player->inventory[4], player->inventory[5],
			player->inventory[6]);
	}
	return ("[minerals]\n");
}

char *incantation(player_t *player)
{

	return ("Elevation underway\nCurrent level X\nko\n");
}

char *death(void)
{
	return ("dead\n");
}
