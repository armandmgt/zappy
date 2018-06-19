/*
** EPITECH PROJECT, 2018
** command_directions
** File description:
** none
*/

#include <stdio.h>
#include "commands.h"
#include "server.h"
#include "tools.h"

bool forward(server_t *server, client_t *client, char *UNUSED(args))
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
	dprintf(client->sock, "ok\n");
	return (true);
}

bool right(server_t *UNUSED(server), client_t *client, char *UNUSED(args))
{
	client->infos->direction = (client->infos->direction + 1) + 4 % 4;
	dprintf(client->sock, "ok\n");
	return (true);
}

bool left(server_t *UNUSED(server), client_t *client, char *UNUSED(args))
{
	client->infos->direction = (client->infos->direction - 1) + 4 % 4;
	dprintf(client->sock, "ok\n");
	return (true);
}
