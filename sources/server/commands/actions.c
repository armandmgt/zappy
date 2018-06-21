/*
** EPITECH PROJECT, 2018
** command_actions
** File description:
** none
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "server/commands.h"
#include "common/tools.h"
#include "gui_commands.h"

bool connect_nbr(server_t *server, client_t *client, char *UNUSED(args))
{
	int cmpt = 0;
	client_t *tmp;
	list_t *tmp_list = server->clients;

	while (tmp_list) {
		tmp = tmp_list->data;
		if (strcmp(tmp->team->name, client->team->name) == 0)
			cmpt += 1;
		tmp_list = tmp_list->next;
	}
	dprintf(client->sock, "%d\n", client->team->max_members - cmpt);
	return (true);
}

bool birth(server_t *server, client_t *client, char *UNUSED(args))
{
	client->team->max_members += 1;
	dprintf(client->sock, "ok\n");
	print_in_gui(server->clients, "pfk %d\n", client->infos->id);
	return (true);
}

bool take(server_t *server, client_t *client, char *args)
{
	char *endptr;
	uint32_t nb = (uint32_t)strtol(args, &endptr, 10);
	cell_t *cell = get_client_cell(&server->map_infos, client);

	if (*endptr)
		return (false);
	if (cell && cell->resource[nb]) {
		client->infos->inventory[nb] += 1;
		remove_resource_on_cell(cell, (resource_t)nb, 1);
		dprintf(client->sock, "ok\n");
		print_in_gui(server->clients, "pgt %d %s\n", client->infos->id,
			args);
		return (true);
	}
	dprintf(client->sock, "ko\n");
	return (false);
}

bool set(server_t *server, client_t *client, char *args)
{
	char *endptr;
	uint32_t nb = (uint32_t)strtol(args, &endptr, 10);
	cell_t *cell = get_client_cell(&server->map_infos, client);

	if (*endptr)
		return (false);
	if (cell && client->infos->inventory[nb]) {
		client->infos->inventory[nb] -= 1;
		add_resource_to_cell(cell, (resource_t)nb, 1);
		dprintf(client->sock, "ok\n");
		print_in_gui(server->clients, "pdr %d %s\n", client->infos->id,
			args);
		return (true);
	}
	dprintf(client->sock, "ko\n");
	return (false);
}

bool broadcast(server_t *server, client_t *client, char *args)
{
	list_t *list = server->clients;
	client_t *tmp;
	double delta_x;
	double delta_y;
	double tan;
	double result;

	while (list) {
		tmp = list->data;
		delta_x = client->infos->pos.x - tmp->infos->pos.x;
		delta_y = client->infos->pos.y - tmp->infos->pos.y;
		tan = delta_y / delta_x;
		result = atan(tan);
		dprintf(tmp->sock, "message %lf, %s\n", result, args);
		list = list->next;
	}
	dprintf(client->sock, "ok\n");
	print_in_gui(server->clients, "pbc %d %s\n", client->infos->id, args);
	return (true);
}
