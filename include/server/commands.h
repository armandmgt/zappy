/*
** EPITECH PROJECT, 2017
** Project
** File description:
** Created by armandmgt,
*/

#pragma once

#include "server.h"

enum direction
{
	NORTH,
	EAST,
	SOUTH,
	WEST
};

typedef struct go_forward_s
{
	direction dir;
	vec2i_t pos;
} go_forward_t;

typedef struct rotation_s
{
	direction dir;
	direction new_dir;
} rotation_t;

bool forward(server_t *server, client_t *client, char *args);
bool right(server_t *server, client_t *client, char *args);
bool left(server_t *server, client_t *client, char *args);
bool look(server_t *server, client_t *client, char *args);
bool inventory(server_t *server, client_t *client, char *args);
bool broadcast(server_t *server, client_t *client, char *args);
bool connect_nbr(server_t *server, client_t *client, char *args);
bool birth(server_t *server, client_t *client, char *args);
bool eject(server_t *server, client_t *client, char *args);
bool take(server_t *server, client_t *client, char *args);
bool set(server_t *server, client_t *client, char *args);
bool incantation(server_t *server, client_t *client, char *args);
bool death(server_t *server, client_t *client, char *args);
