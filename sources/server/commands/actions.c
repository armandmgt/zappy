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
	cell_t *cell = get_client_cell(&server->map_infos, client);
	int32_t res = -1;

	for (int32_t i = 0; i < NB_RESOURCE; i++)
		if (args && !strcmp(res_name[i].name, args)) {
			res = i;
			break;
		}
	if (res == -1 || !cell || !cell->resource[res]) {
		dprintf(client->sock, "ko\n");
		return (false);
	}
	client->infos->inventory[res] += 1;
	remove_resource_on_cell(cell, (resource_t)res, 1);
	dprintf(client->sock, "ok\n");
	print_in_gui(server->clients, "pgt %d %s\n", client->infos->id, args);
	return (true);
}

bool set(server_t *server, client_t *client, char *args)
{
	int32_t res = -1;
	cell_t *cell = get_client_cell(&server->map_infos, client);

	for (int32_t i = 0; i < NB_RESOURCE; i++)
		if (args && !strcmp(res_name[i].name, args)) {
			res = i;
			break;
		}
	if (res == -1 || !cell || !client->infos->inventory[res]) {
		dprintf(client->sock, "ko\n");
		return (false);
	}
	client->infos->inventory[res] -= 1;
	add_resource_to_cell(cell, (resource_t)res, 1);
	dprintf(client->sock, "ok\n");
	print_in_gui(server->clients, "pdr %d %s\n", client->infos->id, args);
	return (true);
}

bool broadcast(server_t *UNUSED(server), client_t *UNUSED(client),
	char *UNUSED(args))
{
	return (false);
}