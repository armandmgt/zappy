/*
** EPITECH PROJECT, 2018
** command_directions
** File description:
** none
*/

#include <stdio.h>
#include "server/commands.h"

bool forward(server_t *server, client_t *client, cell_t *UNUSED(cells),
		char **UNUSED(args))
{
	vec2i_t pos;

	switch (client->player->direction)
	{
		case (NORTH):
		pos = {client->player->pos.x, client->player->pos.y + 1};
		// client->player->pos[y][x] = client->player->pos[y + 1][x];
		break;
		case (EAST):
		pos = {client->player->pos.x + 1, client->player->pos.y};
		// client->player->pos[y][x] = client->player->pos[y][x + 1];
		break;
		case (SOUTH):
		pos = {client->player->pos.x, client->player->pos.y - 1};
		// client->player->pos[y][x] = client->player->pos[y - 1][x];
		break;
		case (WEST):
		pos = {client->player->pos.x - 1, client->player->pos.y};
		// client->player->pos[y][x] = client->player->pos[y][x - 1];
		break;
	}
	add_elem_at_front(&server->map_info->map[pos.y][pos.x].players, client);
	//call remove_elem
	return (true);
}

char *right(server_t *server, client_t *client, cell_t *cells,
		char **args)
{
	if (cells[y][x + 1]) {
		cells->player->pos[y][x] = cells->player->pos[y][x + 1];
		return ("ok\n");
	}
	return ("ko\n");
}

char *left(server_t *server, client_t *client, cell_t *cells,
		char **args)
{
	if (cells[y][x - 1]) {
		cells->player->pos[y][x] = cells->player->pos[y][x - 1];
		return ("ok\n");
	}
	return ("ko\n");
}

char *look(server_t *server, client_t *client, cell_t *cells,
		char **args)
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