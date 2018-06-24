/*
** EPITECH PROJECT, 2018
** command_states
** File description:
** none
*/

#include <stdio.h>
#include "common/tools.h"
#include "server/server.h"
#include "gui_commands.h"

static uint16_t const tab[7][7] = {
	{1, 1, 0, 0, 0, 0, 0}, {2, 1, 1, 1, 0, 0, 0}, {2, 2, 0, 1, 0, 2, 0},
	{4, 1, 1, 2, 0, 1, 0}, {4, 1, 2, 1, 3, 0, 0}, {6, 1, 2, 3, 0, 1, 0},
	{6, 2, 2, 2, 2, 2, 1}
};
static void print_incantation_infos(server_t *server, client_t *client);

bool inventory(server_t *server, client_t *client, char *UNUSED(args))
{
	player_t *tmp = client->infos;

	if (client->infos) {
		for (size_t i = 0; i < NB_RESOURCE; i++)
			dprintf(client->sock, i ? ", %s %d" : "[%s %d",
				res_name[i].name, tmp->inventory[i]);
		dprintf(client->sock, "]\n");
		print_in_gui(server->clients, "pin %d %d %d", client->infos->id,
		client->infos->pos.x, client->infos->pos.y);
		for (int i = 0; i < NB_RESOURCE; i++)
			print_in_gui(server->clients, " %d",
				client->infos->inventory[i]);
		print_in_gui(server->clients, "\n");
	}
	return (true);
}

bool incantation(server_t *server, client_t *client, char *UNUSED(args))
{
	int idx = client->infos->level - 1;
	cell_t *cell = get_client_cell(&server->map_infos, client);

	if (list_len(cell->players) >= tab[idx][0]) {
		dprintf(client->sock, "ko\n");
		return (false);
	}
	for (int i = 1; i < NB_RESOURCE; i++) {
		if (cell->resource[i] < tab[idx][i]) {
			dprintf(client->sock, "ko\n");
			return (false);
		}
	}
	print_incantation_infos(server, client);
	return (true);
}

bool elevation(server_t *server, client_t *client, char *UNUSED(args))
{
	cell_t *cell = get_client_cell(&server->map_infos, client);
	int idx = client->infos->level - 1;
	client->infos->level += 1;

	for (int i = 1; i < NB_RESOURCE; i++)
		cell->resource[i] -= tab[idx][i];
	dprintf(client->sock, "Current level %d\n", client->infos->level);
	print_in_gui(server->clients, "pie %d %d ok\n", client->infos->pos.x,
		client->infos->pos.y);
	return (true);
}

static void print_incantation_infos(server_t *server, client_t *client)
{
	list_t **list = get_player_list_at(&server->map_infos,
		client->infos->pos.x, client->infos->pos.y);
	client_t *tmp_client;

	dprintf(client->sock, "Elevation underway\n");
	print_in_gui(server->clients, "pic %d %d %d", client->infos->pos.x,
		client->infos->pos.y, client->infos->level);
	for (list_t *tmp = *list; tmp; tmp = tmp->next) {
		tmp_client = tmp->data;
		print_in_gui(server->clients, " %d", tmp_client->infos->id);
	}
	print_in_gui(server->clients, "\n");
}
