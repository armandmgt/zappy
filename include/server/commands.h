/*
** EPITECH PROJECT, 2017
** Project
** File description:
** Created by armandmgt,
*/

#pragma once

#include "server.h"

typedef struct go_forward_s
{
	direction_t dir;
	vec2i_t pos;
} go_forward_t;

typedef struct rotation_s
{
	direction_t dir;
	direction_t new_dir;
} rotation_t;

bool forward(server_t *server, client_t *client, char const *args);
bool right(server_t *server, client_t *client, char const *args);
bool left(server_t *server, client_t *client, char const *args);
bool look(server_t *server, client_t *client, char const *args);
bool inventory(server_t *server, client_t *client, char const *args);
bool broadcast(server_t *server, client_t *client, char const *args);
bool connect_nbr(server_t *server, client_t *client, char const *args);
bool birth(server_t *server, client_t *client, char const *args);
bool eject(server_t *server, client_t *client, char const *args);
bool take(server_t *server, client_t *client, char const *args);
bool set(server_t *server, client_t *client, char const *args);
bool incantation(server_t *server, client_t *client, char const *args);
bool death(server_t *server, client_t *client, char const *args);
