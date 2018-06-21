/*
** EPITECH PROJECT, 2018
** Project
** File description:
** command_value
*/

#pragma once

#include "server.h"
#include "commands.h"

typedef struct command_values_s {
	char *command;
	bool (*before_action)(server_t *, client_t *, char *);
	bool (*do_action)(server_t *, client_t *, char *);
	double timeout;
	bool is_gui;
} command_values_t;
