/*
** EPITECH PROJECT, 2018
** command_directions
** File description:
** none
*/

#include "server/commands.h"

char *forward(cell_t *cells)
{
	if (cells[y + 1][x]) {
		cells->player->pos[y][x] = cells->player->pos[y + 1][x];
		return ("ok\n");
	}
	return ("ko\n");
}

char *right(cell_t *cells)
{
	if (cells[y][x + 1]) {
		cells->player->pos[y][x] = cells->player->pos[y][x + 1];
		return ("ok\n");
	}
	return ("ko\n");
}

char *left(cell_t *cells)
{
	if (cells[y][x - 1]) {
		cells->player->pos[y][x] = cells->player->pos[y][x - 1];
		return ("ok\n");
	}
	return ("ko\n");
}

char *look(cell_t *cells)
{
	return ("tile1 [...]\n");
}
