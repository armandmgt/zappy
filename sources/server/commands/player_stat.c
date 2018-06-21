/*
** EPITECH PROJECT, 2017
** Project
** File description:
** Created by armandmgt, player_stat
*/

#include <stdlib.h>
#include <stdio.h>
#include "gui_commands.h"
#include "tools.h"

static client_t *get_player_by_number(server_t *server, uint32_t num);

bool ppo(server_t *server, client_t *client, char *av)
{
	char *endptr;
	client_t *asked;

	uint32_t num = (uint32_t)strtol(av + 1, &endptr, 10);
	if (*endptr)
		return (false);
	if (!(asked = get_player_by_number(server, num)))
		return (false);
	dprintf(client->sock, "ppo #%u %u %u %u\n", num, asked->infos->pos.x,
		asked->infos->pos.x, 1);
	return (true);
}

bool plv(server_t *server, client_t *client, char *av)
{
	char *endptr;
	client_t *asked;

	uint32_t num = (uint32_t)strtol(av + 1, &endptr, 10);
	if (*endptr)
		return (false);
	if (!(asked = get_player_by_number(server, num)))
		return (false);
	dprintf(client->sock, "plv %u %u\n", num, asked->infos->level);
	return (true);
}

bool pin(server_t *server, client_t *client, char *av)
{
	char *endptr;
	client_t *asked;

	uint32_t num = (uint32_t)strtol(av + 1, &endptr, 10);
	if (*endptr)
		return (false);
	if (!(asked = get_player_by_number(server, num)))
		return (false);
	dprintf(client->sock, "pin %u %u %u", num, asked->infos->pos.x,
		asked->infos->pos.y);
	for (size_t i = 0; i < NB_RESOURCE; i++)
		dprintf(client->sock, " %u", asked->infos->inventory[i]);
	dprintf(client->sock, "\n");
	return (true);
}

static client_t *get_player_by_number(server_t *server, uint32_t num)
{
	list_t *cur = server->clients;

	for (; cur && num; cur = cur->next)
		num--;
	if (!cur)
		return (false);
	return (cur->data);
}
