/*
** EPITECH PROJECT, 2018
** command_actions
** File description:
** none
*/

#include <stddef.h>
#include <stdio.h>
#include "server/commands.h"

static command_t const command[] = {
	{"Forward", &forward}, {"Right", &right}, {"Left", &left},
	{"Look", &look}, {"Inventory", &inventory},
	{"Broadcast text", &broadcast}, {"Connect_nbr", &connect_nbr},
	{"Fork", &born}, {"Eject", &eject}, {"Take object", &take},
	{"Set object", &set}, {"Incantation", &incantation},
	{"Death", &death}
};

bool connect_nbr(server_t *server, client_t *client, cell_t *UNUSED(cells),
		char **UNUSED(args))
{
	int cmpt = 0;
	client_t *tmp = server->clients;

	while (tmp) {
		if (strcmp(tmp->team->name, client->team->name) == 0)
			cmpt += 1;
		tmp = tmp->next;
	}
	dprintf(client->sock, "%d", client->team->max_members - cmpt);
	return (true);
}

bool birth(server_t *server, client_t *client, cell_t *UNUSED(cells),
		char **UNUSED(args))
{
	client->team->max_members += 1; // a revoir
	client->player->direction = rand() % 4;
	client->player->level = 1;
	return (true);
}

bool eject(server_t *server, client_t *client, cell_t *cells,
		char **args)
{
	vec2i_t pos;
	client_t *tmp = cells->players;

	while (tmp) {
		switch (tmp->player->direction)
		{
			case (NORTH):
			pos = {tmp->player->pos.x, tmp->player->pos.y + 1};
			// client->player->pos[y][x] = client->player->pos[y + 1][x];
			dprintf(tmp->sock, "eject: S\n");
			break;
			case (EAST):
			pos = {tmp->player->pos.x + 1, tmp->player->pos.y};
			// client->player->pos[y][x] = client->player->pos[y][x + 1];
			dprintf(tmp->sock, "eject: W\n");
			break;
			case (SOUTH):
			pos = {tmp->player->pos.x, tmp->player->pos.y - 1};
			// client->player->pos[y][x] = client->player->pos[y - 1][x];
			dprintf(tmp->sock, "eject: N\n");
			break;
			case (WEST):
			pos = {tmp->player->pos.x - 1, tmp->player->pos.y};
			// client->player->pos[y][x] = client->player->pos[y][x - 1];
			dprintf(tmp->sock, "eject: E\n");
			break;
		}
		add_elem_at_front(&server->map_info->map[pos.y][pos.x].players, tmp);
		//call remove_elem
		tmp = tmp->next;
	}
	return (true);
}

bool take(cell_t *cells, resources nb)
{
	if (cells && cells->resources[nb]) {
		cells->player->inventory[nb] += cells->resources[nb];
		remove_resource_to_cell(cells, nb);
		return (true);
	}
	return (false);
}

bool set(cell_t *cells, resources nb)
{
	if (cells && cells->player->inventory[nb]) {
		cells->player->inventory[nb] -= cells->resources[nb];
		add_resource_to_cell(cells, nb);
		return (true);
	}
	return (false);
}
