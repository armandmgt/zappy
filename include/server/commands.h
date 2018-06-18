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
	char *(*ptr_func)(cell_t *cells);
} command_t;

char *forward(cell_t *cells, player_t *player);
char *right(cell_t *cells, player_t *player);
char *left(cell_t *cells, player_t *player);
char *look(cell_t *cells);
char *inventory(client_t *client);
char *broadcast(client_t *client);
char *connect(client_t *client);
char *birth(client_t *client);
char *eject(client_t *client);
char *take(cell_t *cells, resources nb);
char *set(cell_t *cells, resources nb);
char *incantation(player_t *player);
char *death(client_t *client);
