/*
** EPITECH PROJECT, 2018
** cardinal_points
** File description:
** none
*/

#include <stdio.h>
#include "server.h"
#include "tools.h"
#include "gui_commands.h"

static void case_positions(server_t *server, client_t *cpy, vec2i_t *pos);
static void change_data(server_t *server, list_t *tmp);

bool eject(server_t *server, client_t *client, char *UNUSED(args))
{
	list_t **list = get_player_list_at(&server->map_infos,
		client->infos->pos.x,client->infos->pos.y);

	if (list_len(*list) <= 1) {
		dprintf(client->sock, "ko\n");
		return (false);
	}
	for (list_t *tmp = *list; tmp; tmp = tmp->next)
		change_data(server, tmp);
	dprintf(client->sock, "ok\n");
	print_in_gui(server->clients, "pex %d\n", client->infos->id);
	return (true);
}

static void case_positions(server_t *server, client_t *cpy, vec2i_t *pos)
{
	switch (cpy->infos->direction) {
	case (NORTH):
		*pos = (vec2i_t){cpy->infos->pos.x, cpy->infos->pos.y + 1};
		dprintf(cpy->sock, "eject: S\n");
		break;
	case (EAST):
		*pos = (vec2i_t){cpy->infos->pos.x + 1, cpy->infos->pos.y};
		dprintf(cpy->sock, "eject: W\n");
		break;
	case (SOUTH):
		*pos = (vec2i_t){cpy->infos->pos.x, cpy->infos->pos.y - 1};
		dprintf(cpy->sock, "eject: N\n");
		break;
	case (WEST):
		*pos = (vec2i_t){cpy->infos->pos.x - 1, cpy->infos->pos.y};
		dprintf(cpy->sock, "eject: E\n");
		break;
	default:
		break;
	}
	pos->y = (pos->y + server->map_infos.y) % server->map_infos.y;
	pos->x = (pos->x + server->map_infos.x) % server->map_infos.x;
}

static void change_data(server_t *server, list_t *tmp)
{
	vec2i_t new_pos;
	vec2i_t cur_pos;
	client_t *cpy;

	cpy = tmp->data;
	case_positions(server, cpy, &new_pos);
	cur_pos = cpy->infos->pos;
	add_elem_at_front(&server->
		map_infos.map[new_pos.y][new_pos.x].players, tmp);
	remove_elem(&server->
		map_infos.map[cur_pos.y][cur_pos.x].players, cpy);
}
