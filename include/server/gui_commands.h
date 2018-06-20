/*
** EPITECH PROJECT, 2018
** Project
** File description:
** gui_commands
*/

#pragma once

#include <stdarg.h>
#include "server/server.h"

<<<<<<< HEAD
static char const *const GUI_NAME = "#*#gui#*#";

=======
>>>>>>> d79505179160a30a7d9a4f9c55ff8bb17d63ba1a
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
