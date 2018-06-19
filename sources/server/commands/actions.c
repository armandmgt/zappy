/*
** EPITECH PROJECT, 2018
** command_actions
** File description:
** none
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "server/commands.h"
#include "common/tools.h"
//#include "server/map.h"

static command_t const command[] = {
	{"Forward", &forward}, {"Right", &right}, {"Left", &left},
	{"Look", &look}, {"Inventory", &inventory},
	{"Broadcast text", &broadcast}, {"Connect_nbr", &connect_nbr},
	{"Fork", &birth}, {"Eject", &eject}, {"Take object", &take},
	{"Set object", &set}, {"Incantation", &incantation},
	{"Death", &death}
};

bool connect_nbr(server_t *server, client_t *client, char *UNUSED(args))
{
	int cmpt = 0;
	client_t *tmp;
	list_t *tmp_list;

	while (tmp_list) {
		tmp = tmp_list->data;
		if (strcmp(tmp->team->name, client->team->name) == 0)
			cmpt += 1;
		tmp_list = tmp_list->next;
	}
	dprintf(client->sock, "%d\n", client->team->max_members - cmpt);
	return (true);
}

bool birth(server_t *UNUSED(server), client_t *client, char *UNUSED(args))
{
	client->team->max_members += 1;
	client->infos->direction = rand() % 4;
	client->infos->level = 1;
	return (true);
}

bool eject(server_t *server, client_t *client, char *UNUSED(args))
{
	vec2i_t pos;
	list_t *tmp = server->map_infos->cells[client->
		infos.y][client->infos.x]->players;
	client_t *cpy;

	while (tmp) {
		cpy = tmp->data;
		switch (cpy->infos->direction)
		{
			case (NORTH):
			pos = (vec2i_t){cpy->infos->pos.x, cpy->player->pos.y + 1};
			// client->player->pos[y][x] = client->player->pos[y + 1][x];
			dprintf(cpy->sock, "eject: S\n");
			break;
			case (EAST):
			pos = (vec2i_t){cpy->player->pos.x + 1, cpy->player->pos.y};
			// client->player->pos[y][x] = client->player->pos[y][x + 1];
			dprintf(cpy->sock, "eject: W\n");
			break;
			case (SOUTH):
			pos = (vec2i_t){cpy->player->pos.x, cpy->player->pos.y - 1};
			// client->player->pos[y][x] = client->player->pos[y - 1][x];
			dprintf(cpy->sock, "eject: N\n");
			break;
			case (WEST):
			pos = (vec2i_t){cpy->player->pos.x - 1, cpy->player->pos.y};
			// client->player->pos[y][x] = client->player->pos[y][x - 1];
			dprintf(cpy->sock, "eject: E\n");
			break;
		}
		add_elem_at_front(&server->map_info->map[pos.y][pos.x].players, tmp);
		//call remove_elem
		tmp = tmp->next;
	}
	return (true);
}

bool take(server_t *server, client_t *client, char *args)
{
	int nb = atoi(args);
	cell_t cell = server->map_infos->cells[client->infos.y][client->infos.x];

	if (cell && cell->resources[nb]) {
		client->infos->inventory[nb] += 1;
		remove_resource_to_cell(&cell, nb);
		return (true);
	}
	return (false);
}

bool set(server_t *server, client_t *client, char *args)
{
	int nb = atoi(args);
	cell_t cell = server->map_infos->cells[client->infos.y][client->infos.x];

	if (cell && cell->players->inventory[nb]) {
		cell->infos->inventory[nb] -= 1;
		add_resource_to_cell(&cell, nb);
		return (true);
	}
	return (false);
}
