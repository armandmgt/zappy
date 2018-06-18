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
	{"Broadcast text", &broadcast}, {"Connect_nbr", &connect},
	{"Fork", &born}, {"Eject", &eject}, {"Take object", &take},
	{"Set object", &set}, {"Incantation", &incantation},
	{"Death", &death}
};

char *connect(client_t *client)
{
	int cmpt = 0;
	char *result[256] = {0};

	while (client) {
		if (strcmp(client->team, client->team->name) == 0)
			cmpt += 1;
	}
	sprintf(result, "%d", client->team->max_members - cmpt);
	return (result);
}

char *birth(client_t *client)
{
	client->team->max_members += 1;
	client->player->direction = rand() % 4;
	client->player->level = 1;
	return ("ok\n");
}

char *eject(client_t *client, cell_t *cells)
{
	while (cells->members) {

	}
	switch (client->player->direction)
	{
		case (NORTH):
		client->player->pos[y][x] = client->player->pos[y + 1][x];
		dprintf(client->sock, "eject: S\n");
		return ("ok\n");
		case (EAST):
		client->player->pos[y][x] = client->player->pos[y][x + 1];
		dprintf(client->sock, "eject: W\n");
		return ("ok");
		case (SOUTH):
		client->player->pos[y][x] = client->player->pos[y - 1][x];
		dprintf(client->sock, "eject: N\n");
		return ("ok");
		case (WEST):
		client->player->pos[y][x] = client->player->pos[y][x - 1];
		dprintf(client->sock, "eject: E\n");
		return ("ok");
	}
	return ("ko\n");
}

char *take(cell_t *cells, resources nb)
{
	if (cells && cells->resources[nb]) {
		cells->player->inventory[nb] += cells->resources[nb];
		remove_resource_to_cell(cells, nb);
		return ("ok\n");
	}
	return ("ko\n");
}

char *set(cell_t *cells, resources nb)
{
	if (cells && cells->player->inventory[nb]) {
		cells->player->inventory[nb] -= cells->resources[nb];
		add_resource_to_cell(cells, nb);
		return ("ok\n");
	}
	return ("ko\n");
}
