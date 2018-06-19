/*
** EPITECH PROJECT, 2018
** command_directions
** File description:
** none
*/

#include <stdio.h>
#include "server/commands.h"
#include "server/server.h"

bool forward(server_t *server, client_t *client, char const *args)
{
	vec2i_t pos;
	go_forward_t look_at[] = {
		{NORTH, {client->infos->pos.x, client->infos->pos.y + 1}},
		{EAST, {client->infos->pos.x + 1, client->infos->pos.y}},
		{SOUTH, {client->infos->pos.x, client->infos->pos.y - 1}},
		{WEST, {client->infos->pos.x - 1, client->infos->pos.y}}
	};

	pos = look_at[client->infos->direction].pos;
	add_elem_at_front(&server->map_infos.map[pos.y][pos.x].players, client);
	remove_elem(&server->map_infos.map[pos.y][pos.x].players, client);
	return (true);
}

bool right(server_t *server, client_t *client, char const *args)
{
	rotation_t look_at[] = {
		{NORTH, EAST}, {EAST, SOUTH}, {SOUTH, WEST}, {WEST, NORTH}
	};

	client->infos->direction = look_at[client->infos->direction].new_dir;
	return (true);
}

bool left(server_t *server, client_t *client, char const *args)
{
	rotation_t look_at[] = {
		{NORTH, WEST}, {WEST, SOUTH}, {SOUTH, EAST}, {EAST, NORTH}
	};

	client->infos->direction = look_at[client->infos->direction].new_dir;
	return (true);
}

bool look(server_t *server, client_t *client, char const *args)
{
//	cell_t cell = server->map_infos->cells[client->infos.y][client->infos.x];
//	switch (client->infos->direction)
//	{
//		case (NORTH):
//		cell_t left = cell[x - level];
//		cell_t right = cell[x + level];
//		cell_t top = cell[y + level][x];
//		look_at(client, left, right, top);
//		case (EAST):
//		cell_t left = cell[y - level];
//		cell_t right = cell[y + level];
//		cell_t top = cell[y][x + level];
//		look_at(client, left, right, top);
//		case (SOUTH):
//		cell_t left = cell[x + level];
//		cell_t right = cell[x - level];
//		cell_t top = cell[y - level][x];
//		look_at(client, left, right, top);
//		case (WEST):
//		cell_t left = cell[y + level];
//		cell_t right = cell[y - level];
//		cell_t top = cell[y][x - level];
//		look_at(client, left, right, top);
//	}
	return (true);
}

void look_at(client_t *client)
{
//	while (cell->resources != NULL) {
//		cell[y][x] = cell[y + level][x];
//		dprintf("");
//	}
}