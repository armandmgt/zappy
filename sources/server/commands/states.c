/*
** EPITECH PROJECT, 2018
** command_states
** File description:
** none
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "server/commands.h"
#include "common/tools.h"
#include "common/linked_list.h"
#include "server/server.h"

static void elevation(client_t *client, uint16_t const *nb, cell_t *cell);
static int count_same_team_player(cell_t *cell, client_t *client);

bool inventory(server_t *UNUSED(server), client_t *client, char *UNUSED(args))
{
	player_t *tmp = client->infos;

	if (client->infos) {
		dprintf(client->sock, "[food %d, linemate %d, deraumere %d, "
			"sibur %d, mendiane %d, phiras %d, thystame %d]\n",
			tmp->inventory[0], tmp->inventory[1],
			tmp->inventory[2], tmp->inventory[3],
			tmp->inventory[4], tmp->inventory[5],
			tmp->inventory[6]);
	}
	return (true);
}

bool incantation(server_t *server, client_t *client, char *UNUSED(args))
{
	int idx = client->infos->level - 1;
	static uint16_t const tab[7][7] = {{1, 1, 0, 0, 0, 0, 0},
		{2, 1, 1, 1, 0, 0, 0}, {2, 2, 0, 1, 0, 2, 0},
		{4, 1, 1, 2, 0, 1, 0}, {4, 1, 2, 1, 3, 0, 0},
		{6, 1, 2, 3, 0, 1, 0}, {6, 2, 2, 2, 2, 2, 1}};
	cell_t *cell = get_client_cell(&server->map_infos, client);

	if (count_same_team_player(cell, client) != tab[idx][0]) {
		dprintf(client->sock, "ko\n");
		return (false);
	}
	for (int i = 0; i < NB_RESOURCE; i++) {
		if (client->infos->inventory[i] < tab[idx][i + 1]) {
			dprintf(client->sock, "ko\n");
			return (false);
		}
	}
	elevation(client, tab[idx], cell);
	return (true);
}

bool death(server_t *server, client_t *client, char *UNUSED(args))
{
	for (list_t *tmp = server->clients; tmp; tmp = tmp->next) {
		if (tmp->data == client && client->infos->lifetime == 0) {
			dprintf(client->sock, "dead\n");
			close(client->sock);
			free(client->infos);
			free(tmp->data);
			tmp->data = NULL;
			return (true);
		}
	}
	return (false);
}

static void elevation(client_t *client, uint16_t const *nb, cell_t *cell)
{
	client->infos->level += 1;
	for (int i = 0; i < NB_RESOURCE; i++) {
		client->infos->inventory[i] -= nb[i + 1];
		remove_resource_on_cell(cell, (resource_t)i, nb[i + 1]);
	}
	dprintf(client->sock, "Elevation underway\nCurrent level "
			      "%d\n", client->infos->level);
}

static int count_same_team_player(cell_t *cell, client_t *client)
{
	int cmpt = 0;
	client_t *tmp_client;

	for (list_t *tmp = cell->players; tmp != NULL; tmp = tmp->next) {
		tmp_client = tmp->data;
		if (strcmp(tmp_client->team->name, client->team->name) == 0)
			cmpt = cmpt + 1;
	}
	return (cmpt);
}
