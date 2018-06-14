/*
** EPITECH PROJECT, 2018
** command_actions
** File description:
** none
*/

#include <stddef.h>
#include "server/server.h"

static const command_t command[] = {
	{"Forward", &forward}, {"Right", &right}, {"Left", &left},
	{"Look", &look}, {"Inventory", &inventory},
	{"Broadcast text", &broadcast}, {"Connect_nbr", &connect},
	{"Fork", &born}, {"Eject", &eject}, {"Take object", &take},
	{"Set object", &set}, {"Incantation", &incantation},
	{"Death", &death}
};

char *connect(void)
{
	return ("value\n");
}

char *born(void)
{
	return ("ok\n");
}

char *eject(void)
{
	return ("ko\n");
}

char *take(cell_t *cells)
{
	if (cells[y][x] && cells[y][x]->ressources) {
		while (cells[y][x]->ressources != NULL) {
			cells[y][x]->player->inventory += cells[y][x]->ressources;
			cells[y][x]->ressources -= cells[y][x]->ressources;
		}
		return ("ok");
	}
	return ("ko\n");
}

char *set(cell_t *cells)
{
	return ("ko\n");
}
