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

	if (!(client = calloc(sizeof(*client), 1)) ||
		!add_elem_at_front(&server->clients, client))
		return (NULL);
	return (client);
}

static int accept_client(server_t *server, client_t *client)
{
	socklen_t len = sizeof(server->addr);

	if ((client->sock = accept(server->sock,
		(struct sockaddr *)&server->addr, &len)) == -1)
		return (-1);
	return (0);
}
