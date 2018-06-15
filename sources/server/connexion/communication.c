/*
** EPITECH PROJECT, 2017
** Project
** File description:
** Created by armandmgt,
*/

#include <stdio.h>
#include "server.h"

int check_fds(server_t *server, fd_set *readfds)
{
	client_t *client;
	int maxfd = server->sock;

	FD_ZERO(readfds);
	FD_SET(server->sock, readfds);
	for (list_t *cur = server->clients; cur;
		cur = cur->next) {
		client = cur->data;
		FD_SET(client->sock, readfds);
		maxfd = client->sock > maxfd ? client->sock : maxfd;
	}
	if (select(maxfd + 1, readfds, NULL, NULL,
		&(struct timeval){0, 1000}) == -1) {
		perror("select");
		return (-1);
	}
	return (0);
}
