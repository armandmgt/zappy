/*
** EPITECH PROJECT, 2018
** command_directions
** File description:
** none
*/

#include <stdio.h>
#include "server/gui_commands.h"
#include "commands.h"
#include "tools.h"

bool forward(server_t *server, client_t *client, char *UNUSED(args))
{
	vec2i_t cur_pos = client->infos->pos;
	go_forward_t look_at[] = {
		{NORTH, {client->infos->pos.x, client->infos->pos.y - 1}},
		{EAST, {client->infos->pos.x + 1, client->infos->pos.y}},
		{SOUTH, {client->infos->pos.x, client->infos->pos.y + 1}},
		{WEST, {client->infos->pos.x - 1, client->infos->pos.y}}
	};
	vec2i_t new_pos = look_at[client->infos->direction].pos;

	new_pos.x = wrapped_coord(new_pos.x, server->map_infos.x);
	new_pos.y = wrapped_coord(new_pos.y, server->map_infos.y);
	add_elem_at_front(&server->map_infos.map[new_pos.y][new_pos.x].players,
		client);
	remove_elem(&server->map_infos.map[cur_pos.y][cur_pos.x].players,
		client);
	client->infos->pos = new_pos;
	print_in_gui(server->clients, "ppo %d %d %d %d", client->infos->id,
		     new_pos.x, new_pos.y, client->infos->direction + 1);
	dprintf(client->sock, "ok\n");
	return (true);
}

bool right(server_t *server, client_t *client, char *UNUSED(args))
{
	client->infos->direction = ((client->infos->direction + 1) + 4) % 4;
	dprintf(client->sock, "ok\n");
	print_in_gui(server->clients, "ppo %d %d %d %d", client->infos->id,
		     client->infos->pos.x, client->infos->pos.y,
		     client->infos->direction + 1);
	return (true);
}

bool left(server_t *server, client_t *client, char *UNUSED(args))
{
	client->infos->direction = ((client->infos->direction - 1) + 4) % 4;
	dprintf(client->sock, "ok\n");
	print_in_gui(server->clients, "ppo %d %d %d %d", client->infos->id,
		     client->infos->pos.x, client->infos->pos.y,
		     client->infos->direction + 1);
	return (true);
}
