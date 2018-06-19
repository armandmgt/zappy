/*
** EPITECH PROJECT, 2018
** Project
** File description:
** command_value
*/

#pragma once

#include "server.h"

typedef struct	command_values_s {
	char *command;
	bool (*do_action)(server_t *, client_t *, const char *);
	double timeout;
}			command_values_t;

#endif //PROJECT_COMMAND_VALUE_H
