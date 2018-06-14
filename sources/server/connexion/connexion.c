/*
** EPITECH PROJECT, 2018
** connexion
** File description:
** none
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <netdb.h>
#include "server.h"

static int get_socket(char const *protocol);
static int listen_socket(int sock, struct sockaddr_in *addr);

int run_server(options_t *opts, server_t *server)
{
	fd_set readfds;

	while (true) {
		if (check_fds(server, &readfds) ||
			handle_new_connections(server, &readfds))
			break;
	}
	return (0);
}

int init_server(options_t *opts, server_t *server)
{
	server->addr.sin_family = AF_INET;
	server->addr.sin_port = htons(opts->port);
	server->addr.sin_addr.s_addr = INADDR_ANY;
	if ((server->sock = get_socket("TCP")) == -1 ||
		listen_socket(server->sock, &server->addr) == -1) {
		perror("server initialisation");
		return (-1);
	}
	return (0);
}

static int get_socket(char const *protocol)
{
	struct protoent *proto = getprotobyname(protocol);

	if (!proto)
		return (-1);
	return (socket(AF_INET, SOCK_STREAM, proto->p_proto));
}

static int listen_socket(int sock, struct sockaddr_in *addr)
{
	if (bind(sock, (const struct sockaddr *)addr, sizeof(*addr)) ==	-1 ||
		listen(sock, 128) == -1)
		return (-1);
	return (0);
}
