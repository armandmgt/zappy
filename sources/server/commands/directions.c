/*
** EPITECH PROJECT, 2018
** command_directions
** File description:
** none
*/

#include <stdio.h>
#include "server/commands.h"

bool forward(server_t *server, client_t *client, char *args)
{
	vec2i_t pos;
	go_forward_t look_at[] = {
		{NORTH, {client->infos->pos.x, client->infos->pos.y + 1}},
		{EAST, {client->infos->pos.x + 1, client->infos->pos.y}},
		{SOUTH, {client->infos->pos.x, client->infos->pos.y - 1}},
		{WEST, {client->infos->pos.x - 1, client->infos->pos.y}}
	};

	pos = look_at[client->infos->direction];
	add_elem_at_front(&server->map_info->map[pos.y][pos.x].players, client);
	//call remove_elem
	return (true);
}

bool right(server_t *server, client_t *client, char *args)
{
	rotation_t look_at[] = {
		{NORTH, EAST}, {EAST, SOUTH}, {SOUTH, WEST}, {WEST, NORTH}
	};

	direction = look_at[client->infos->direction];
	return (true);
}

bool left(server_t *server, client_t *client, char *args)
{
	rotation_t look_at[] = {
		{NORTH, WEST}, {WEST, SOUTH}, {SOUTH, EAST}, {EAST, NORTH}
	};

	direction = look_at[client->infos->direction];
	return (true);
}

bool look(server_t *server, client_t *client, char *args)
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
