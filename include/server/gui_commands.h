/*
** EPITECH PROJECT, 2018
** Project
** File description:
** gui_commands
*/

#pragma once

#include <stdarg.h>
#include "server/server.h"

char const *GUI_NAME = "#*#gui#*#";

int print_in_gui(list_t *clients, char const *format, ...);
bool msz(server_t *serv, client_t *client, char const *av);
