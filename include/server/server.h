/*
** EPITECH PROJECT, 2017
** zappy
** File description:
** Created by armandmgt,
*/

#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "linked_list.h"
#include "map.h"

typedef struct options_s {
	uint16_t port;
	uint32_t width;
	uint32_t height;
	list_t *teams;
	uint32_t max_clients;
	uint32_t freq;
} options_t;

typedef struct server_s server_t;

typedef struct command_s {
	bool (*do_action)(server_t *, client_t *, char *);
	clock_t s_time;
	double timeout;
	char *args;
} command_t;

struct server_s {
	int sock;
	struct sockaddr_in addr;
	map_t map_infos;
	list_t *teams;
	list_t *clients;
	list_t *commands;
	uint32_t freq;
};

int parse_options(int argc, char *const *argv, options_t *opts);

int init_server(options_t *opts, server_t *server);
int run_server(server_t *server);
client_t *get_new_client(int server_socket);

int check_fds(server_t *server, fd_set *readfds);
int handle_new_connections(server_t *server, fd_set *readfds);

int poll_client_commands(server_t *server, fd_set *readfds);
int do_pending_actions(server_t *server);
int eat_food(server_t *server);
