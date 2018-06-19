/*
** EPITECH PROJECT, 2018
** Project
** File description:
** gui_commands
*/

#pragma once

#include <stdarg.h>
#include "server/server.h"

static char const *GUI_NAME = "#*#gui#*#";

int print_in_gui(list_t *clients, char const *format, ...);
bool msz(server_t *serv, client_t *client, char *av);
bool bct(server_t *server, client_t *client, char *av);
bool mct(server_t *server, client_t *client, char *av);
