/*
** EPITECH PROJECT, 2018
** Project
** File description
** look.c
*/

#include <stdio.h>
#include "print_content.h"
#include "tools.h"

static void look_north_south(server_t *server,
	client_t *client, direction_t dir);
static void look_east_west(server_t *server,
	client_t *client, direction_t dir);

bool look(server_t *server, client_t *client, char *UNUSED(args))
{
	switch (client->infos->direction) {
	case (NORTH):
		look_north_south(server, client, client->infos->direction);
		break;
	case (SOUTH):
		look_north_south(server, client, client->infos->direction);
		break;
	case (EAST):
		look_east_west(server, client, client->infos->direction);;
		break;
	case (WEST):
		look_east_west(server, client, client->infos->direction);;
		break;
	}
	dprintf(client->sock, "\n");
	return (true);
}

static void look_north_south(server_t *server,
	client_t *client, direction_t dir)
{
	if (dir == NORTH)
		for (uint32_t i = 0; i < client->infos->level; i++)
			print_line_content(&server->map_infos,
				client, client->infos->pos.y - i, i * 2 + 1);
	else
		for (uint32_t i = 0; i < client->infos->level; i++)
			print_line_content(&server->map_infos,
				client, client->infos->pos.y + i, i * 2 + 1);
}

static void look_east_west(server_t *server, client_t *client, direction_t dir)
{
	if (dir == EAST)
		for (uint32_t i = 0; i < client->infos->level; i++)
			print_row_content(&server->map_infos,
				client, client->infos->pos.x + i, i * 2 + 1);
	else
		for (uint32_t i = 0; i < client->infos->level; i++)
			print_row_content(&server->map_infos,
				client, client->infos->pos.x - i, i * 2 + 1);
}
