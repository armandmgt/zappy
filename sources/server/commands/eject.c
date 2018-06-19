/*
** EPITECH PROJECT, 2018
** cardinal_points
** File description:
** none
*/

#include <stdio.h>
#include "map.h"
#include "server.h"
#include "tools.h"

static void case_positions(client_t *cpy, vec2i_t *pos);

bool eject(server_t *server, client_t *client, char *UNUSED(args))
{
	vec2i_t pos;
	list_t *tmp = server->map_infos.map[client->infos->
		pos.y][client->infos->pos.x].players;
	client_t *cpy;

	if (list_len(tmp) <= 1) {
		dprintf(client->sock, "ko\n");
		return (false);
	}
	while (tmp) {
		cpy = tmp->data;
		case_positions(cpy, &pos);
		add_elem_at_front(&server->map_infos.map[pos.y][pos.x].players,
			tmp);
		remove_elem(&server->map_infos.map[pos.y][pos.x].players, tmp);
		tmp = tmp->next;
	}
	dprintf(client->sock, "ok\n");
	return (true);
}

static void case_positions(client_t *cpy, vec2i_t *pos)
{
	switch (cpy->infos->direction)
	{
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
	}
}
