/*
** EPITECH PROJECT, 2017
** Project
** File description:
** Created by armandmgt,
*/

#include <stdio.h>
#include <stdlib.h>
#include "server.h"

int poll_client_commands(server_t *server, fd_set *readfds)
{
	client_t *client;
	char *line;

	for (list_t *cur = server->clients; cur; cur = cur->next) {
		client = cur->data;
		if (FD_ISSET(client->sock, readfds)) {
			write_cbuf(&client->buffer, client->sock);
			if (read_cbuf(&client->buffer, (uint8_t **)&line)) {
				fprintf(stderr, "received line [%s]\n", line);
				free(line);
			}
		}
	}
	return (0);
}

int do_pending_actions(server_t *server)
{
	return (0);
}
