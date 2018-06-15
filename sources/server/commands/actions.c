/*
** EPITECH PROJECT, 2018
** command_actions
** File description:
** none
*/

#include <stddef.h>
#include "server/commands.h"

static command_t const command[] = {
	{"Forward", &forward}, {"Right", &right}, {"Left", &left},
	{"Look", &look}, {"Inventory", &inventory},
	{"Broadcast text", &broadcast}, {"Connect_nbr", &connect},
	{"Fork", &born}, {"Eject", &eject}, {"Take object", &take},
	{"Set object", &set}, {"Incantation", &incantation},
	{"Death", &death}
};

char *connect(cell_t *cells)
{
	return ("value\n");
}

char *birth(cell_t *cells)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
		return (-1);
	else if (pid == 0) {
		/* créer un oeuf et attendre qu'un client puisse se co*/
	}
	return ("ok\n");
}

char *eject(cell_t *cells)
{
	switch (cells->player->direction)
	{
		case (cells->player->direction == 1):
		cells->player->pos[y][x] = cells->player->pos[y + 1][x];
		return ("ok\n");
		//return ("eject: S\n"); /* si y a des gens sur la case */
		case (cells->player->direction == 2):
		cells->player->pos[y][x] = cells->player->pos[y][x + 1];
		return ("ok");
		//return ("eject: W\n"); /* si y a des gens sur la case */
		case (cells->player->direction == 3):
		cells->player->pos[y][x] = cells->player->pos[y - 1][x];
		return ("ok");
		//return ("eject: N\n"); /* si y a des gens sur la case */
		case (cells->player->direction == 4):
		cells->player->pos[y][x] = cells->player->pos[y][x - 1];
		return ("ok");
		//return ("eject: E\n"); /* si y a des gens sur la case */
	}
	return ("ko\n");
}

char *take(cell_t *cells)
{
	if (cells[y][x] && cells[y][x]->ressources) {
		while (cells[y][x]->ressources != NULL) {
			cells[y][x]->player->inventory += cells[y][x]->ressources;
			cells[y][x]->ressources -= 1;
		}
		return ("ok\n");
	}
	return ("ko\n");
}

char *set(cell_t *cells)
{
	if (cells[y][x] && cells->player->inventory) {
		while (cells->player->inventory != NULL) {
			cells[y][x]->player->inventory -= cells[y][x]->ressources;
			cells[y][x]->ressources += 1;
		}
		return ("ok\n");
	}
	return ("ko\n");
}
