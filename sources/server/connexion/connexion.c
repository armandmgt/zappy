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

static int get_socket(void);
static int listen_socket(int sock, struct sockaddr_in *addr);
static void init_teams(list_t *list, unsigned int max_clients);

int run_server(server_t *server)
{
	int rc = 0;
	fd_set readfds;

	while (true) {
		if ((rc = check_fds(server, &readfds)) ||
			(rc = handle_new_connections(server, &readfds)) ||
			(rc = poll_client_commands(server, &readfds)) ||
			(rc = do_pending_actions(server)))
			return (rc);
	}
}

int init_server(options_t *opts, server_t *server)
{
	server->teams = opts->teams;
	init_teams(server->teams, opts->max_clients);
	server->map_infos = (map_t){opts->width, opts->height, 0};
	generate_map(80, 10, &server->map_infos);
	server->addr.sin_family = AF_INET;
	server->addr.sin_port = htons(opts->port);
	server->addr.sin_addr.s_addr = INADDR_ANY;
	server->freq = opts->freq;
	if ((server->sock = get_socket()) == -1 ||
		listen_socket(server->sock, &server->addr) == -1) {
		perror("server initialisation");
		return (-1);
	}
	return (0);
}

static void init_teams(list_t *list, unsigned int max_clients)
{
	for (list_t *cur = list; cur; cur = cur->next) {
		team_t *team = cur->data;
		team->max_members = max_clients;
	}
}

static int get_socket(void)
{
	int sd;
	int const val = 1;
	socklen_t const len = sizeof(val);
	struct protoent *p = getprotobyname("TCP");

	if (!p || (sd = socket(AF_INET, SOCK_STREAM, p->p_proto)) == -1)
		return (-1);
	setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &val, len);
	return (sd);
}

static int listen_socket(int sock, struct sockaddr_in *addr)
{
	if (bind(sock, (const struct sockaddr *)addr, sizeof(*addr)) ==	-1 ||
		listen(sock, 128) == -1)
		return (-1);
	return (0);
}
