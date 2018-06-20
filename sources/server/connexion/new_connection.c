/*
** EPITECH PROJECT, 2017
** Project
** File description:
** Created by armandmgt,
*/

#include <stdlib.h>
#include <stdio.h>
#include "server.h"

static int accept_client(server_t *server, client_t *client);
static client_t *new_client(server_t *server);
static void spawn_client_on_map(map_t *m, client_t *client);
static client_t *create_client(server_t *server);

int handle_new_connections(server_t *server, fd_set *readfds)
{
	client_t *client;

	if (FD_ISSET(server->sock, readfds)) {
		fprintf(stdout, "client connected !\n");
		if (!(client = new_client(server)) ||
			accept_client(server, client) == -1)
			return (-1);
	}
	return (0);
}

static client_t *new_client(server_t *server)
{
	client_t *client;

	if (!(client = create_client(server)) ||
		!add_elem_at_front(&server->clients, client))
		return (NULL);
	dprintf(client->sock, "WELCOME\n");
	spawn_client_on_map(&server->map_infos, client);
	return (client);
}

static client_t *create_client(server_t *server)
{
	client_t *client;

	if (!(client = calloc(1, sizeof(*client))) ||
		!(client->infos = calloc(1, sizeof(*client->infos))))
		return (NULL);
	init_cbuf(&client->buffer);
	client->infos->level = 1;
	client->infos->lifetime = 1260 / server->freq;
	client->infos->inventory[FOOD] = 10;
	return (client);
}

static void spawn_client_on_map(map_t *m, client_t *client)
{
	list_t *players;

	client->infos->pos.x = (uint32_t)rand() % m->x;
	client->infos->pos.y = (uint32_t)rand() % m->y;
	//TODO: add random direction when PR #35 is merged in
	players = m->map[client->infos->pos.y][client->infos->pos.x].players;
	add_elem_at_front(&players, client);
}

static int accept_client(server_t *server, client_t *client)
{
	socklen_t len = sizeof(server->addr);

	if ((client->sock = accept(server->sock,
		(struct sockaddr *)&server->addr, &len)) == -1)
		return (-1);
	return (0);
}
