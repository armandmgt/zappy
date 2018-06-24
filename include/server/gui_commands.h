/*
** EPITECH PROJECT, 2018
** Project
** File description:
** gui_commands
*/

#pragma once

#include <stdarg.h>
#include "server/server.h"
#include "gui_magic.h"

int print_in_gui(list_t *clients, char const *format, ...);
bool msz(server_t *serv, client_t *client, char *av);
bool bct(server_t *server, client_t *client, char *av);
bool mct(server_t *server, client_t *client, char *av);
bool ppo(server_t *server, client_t *client, char *av);
bool plv(server_t *server, client_t *client, char *av);
bool pin(server_t *server, client_t *client, char *av);
bool tna(server_t *server, client_t *client, char *av);
bool sgt(server_t *server, client_t *client, char *av);
bool sst(server_t *server, client_t *client, char *av);
