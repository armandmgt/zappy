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
	if (player && player->level) {
		switch (player->level)
		{
			case (player->level == 1):
			level2(infos, player);
			case (player->level == 2):
			level3(infos, player);
			case (player->level == 3):
			level4(infos, player);
			case (player->level == 4):
			level5(infos, player);
			case (player->level == 5):
			level6(infos, player);
			case (player->level == 6):
			level7(infos, player);
			case (player->level == 7):
			level8(infos, player);
		}
		return ("Elevation underway\nCurrent level %d\n", player->level);
	}
	return ('ko');
}

char *death(void)
{
	return ("dead\n");
}
