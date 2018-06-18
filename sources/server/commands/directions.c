/*
** EPITECH PROJECT, 2018
** command_directions
** File description:
** none
*/

#include "server/commands.h"

char *forward(cell_t *cells, player_t *player)
{
	if (cells[y + 1][x]) {
		cells->player->pos[y][x] = cells->player->pos[y + 1][x];
		return ("ok\n");
	}
	return ("ko\n");
}

char *right(cell_t *cells, player_t *player)
{
	if (cells[y][x + 1]) {
		cells->player->pos[y][x] = cells->player->pos[y][x + 1];
		return ("ok\n");
	}
	return ("ko\n");
}

char *left(cell_t *cells, player_t *player)
{
	if (cells[y][x - 1]) {
		cells->player->pos[y][x] = cells->player->pos[y][x - 1];
		return ("ok\n");
	}
	return ("ko\n");
}

char *look(cell_t *cells)
{
	int vision = cells->player->level;
	int vision_x = 1;
	int vision_y = 0;

	if (cells->player->level == 1)
		printf("player, %s\n", cells->player->ressources[y + 1][x - 1]);
	else if (cells->player->level == 2)
		printf("player, %s, %s\n", cells->player->ressources[y + 1][x - 1],
			cells->player->ressources[y + 1][x]);
	else if (cells->player->level == 3)
		printf("player, %s ,%s ,%s\n", cells->player->ressources[y + 1][x - 1],
			cells->player->ressources[y  + 1][x],
			cells->player->ressources[y + 1][x + 1]);
	else if (cells->player->level == 4)
		printf("player, %s ,%s ,%s ,%s\n", cells->player->ressources[y + 1][x - 1],
			cells->player->ressources[y + 1][x],
			cells->player->ressources[y + 1][x + 1],
			cells->player->ressources[y + 2][x - 2]);
	else if (cells->player->level == 5)
		printf("player, %s, %s, %s, %s, %s\n", cells->player->ressources[y + 1][x - 1],
			cells->player->ressources[y + 1][x],
			cells->player->ressources[y + 1][x + 1],
			cells->player->ressources[y + 2][x - 2],
			cells->player->ressources[y + 2][x - 1]);
	else if (cells->player->level == 6)
		printf("player %s, %s, %s, %s, %s, %s\n", cells->player->ressources[y + 1][x - 1],
			cells->player->ressources[y + 1][x],
			cells->player->ressources[y + 1][x + 1],
			cells->player->ressources[y + 2][x - 2],
			cells->player->ressources[y + 2][x - 1],
			cells->player->ressources[y + 2][x]);
	else if (cells->player->level == 7)
		printf("player %s, %s, %s, %s, %s, %s\n", cells->player->ressources[y + 1][x - 1],
			cells->player->ressources[y + 1][x],
			cells->player->ressources[y + 1][x + 1],
			cells->player->ressources[y + 2][x - 2],
			cells->player->ressources[y + 2][x - 1],
			cells->player->ressources[y + 2][x],
			cells->player->ressources[y + 2][x + 1]);
	else if (cells->player->level == 8)
		printf("player %s, %s, %s, %s, %s, %s\n", cells->player->ressources[y + 1][x - 1],
			cells->player->ressources[y + 1][x],
			cells->player->ressources[y + 1][x + 1],
			cells->player->ressources[y + 2][x - 2],
			cells->player->ressources[y + 2][x - 1],
			cells->player->ressources[y + 2][x],
			cells->player->ressources[y + 2][x + 1],
			cells->player->ressources[y + 2][x + 2]);
	return ("tile1 [...]\n");
}

void rotation(cell_t *cells)
{

}