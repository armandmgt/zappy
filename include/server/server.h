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
#include "resources.h"
#include "linked_list.h"

#define TEAM_NAME_LEN 64

typedef struct team_s {
	char name[TEAM_NAME_LEN];
	size_t max_members;
	list_t *members;
} team_t;

typedef struct player_s {
	uint16_t level;
	uint32_t inventory[NB_RESOURCE];
	uint32_t lifetime;
} player_t;

typedef struct client_s {
	int sock;
	player_t *infos;
	team_t *team;
} client_t;

typedef struct options_s {
	uint16_t port;
	unsigned int width;
	unsigned int height;
	list_t *teams;
	unsigned int maxClients;
	unsigned int freq;
} options_t;

typedef struct server_t {
	int sock;
	struct sockaddr_in addr;
	list_t *teams;
	list_t *clients;
} server_t;

int parse_options(int argc, char * const *argv, options_t *opts);

int init_server(options_t *opts, server_t *server);
int run_server(options_t *opts, server_t *server);
client_t *get_new_client(int server_socket);

int check_fds(server_t *server, fd_set *readfds);
int handle_new_connections(server_t *server, fd_set *readfds);

int poll_client_commands(server_t *server, fd_set *readfds);
int do_pending_actions(server_t *server);
