/*
** EPITECH PROJECT, 2017
** Project
** File description:
** Created by armandmgt, food
*/

#include <time.h>
#include "commands.h"
#include "server.h"

static bool take_action(server_t *server, client_t *client);

int eat_food(server_t *server)
{
	client_t *client;
	clock_t now = clock();
	double total;

	for (list_t *cur = server->clients; cur; cur = cur->next) {
		client = cur->data;
		total = (double)(now - client->last_tick) / CLOCKS_PER_SEC * 10;
		if (total > 1.f / server->freq && take_action(server, client))
			client->last_tick = now;
	}
	while (remove_elem(&server->clients, NULL));
	return (0);
}

static bool take_action(server_t *server, client_t *client)
{
	if (!client->infos->lifetime && client->infos->inventory[FOOD]) {
		client->infos->inventory[FOOD] -= 1;
		client->infos->lifetime += 1260 / server->freq;
	} else if (client->infos->lifetime) {
		client->infos->lifetime -= 1;
	} else {
		death(server, client, NULL);
		return (false);
	}
	return (true);
}
