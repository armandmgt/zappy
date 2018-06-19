/*
** EPITECH PROJECT, 2017
** Project
** File description:
** Created by armandmgt,
*/

#pragma once

static const int CMD_LEN = 13;

enum direction
{
	NORTH,
	EAST,
	SOUTH,
	WEST
};

typedef struct command_s
{
	char *cmd;
	bool (*do_action)(server_t *server, client_t *client, cell_t *cells,
		char **args);
} command_t;

typedef struct vec2i_s
{
	int x;
	int y;
} vec2i_t;

char *forward(server_t *server, client_t *client, cell_t *cells,
		char **args);
char *right(server_t *server, client_t *client, cell_t *cells,
		char **args);
char *left(server_t *server, client_t *client, cell_t *cells,
		char **args);
char *look(server_t *server, client_t *client, cell_t *cells,
		char **args);
char *inventory(server_t *server, client_t *client, cell_t *cells,
		char **args);
char *broadcast(server_t *server, client_t *client, cell_t *cells,
		char **args);
char *connect_nbr(server_t *server, client_t *client, cell_t *cells,
		char **args);
char *birth(server_t *server, client_t *client, cell_t *cells,
		char **args);
char *eject(server_t *server, client_t *client, cell_t *cells,
		char **args);
char *take(cell_t *cells, resources nb);
char *set(cell_t *cells, resources nb);
char *incantation(server_t *server, client_t *client, cell_t *cells,
		char **args);
char *death(server_t *server, client_t *client, cell_t *cells,
		char **args);
