/*
** EPITECH PROJECT, 2017
** Project
** File description:
** Created by armandmgt,
*/

#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <server/gui_commands.h>
#include "server.h"
#include "command_value.h"

static void add_command(server_t *server, client_t *client, char **av);

bool do_action(server_t *s, client_t *c, char *av)
{
	printf("coucou\n");
}

static  command_values_t const command_assg[] = {
	{"Forward", &do_action, 7, false}, {"Right", &do_action, 7, false},
	{"Left", &do_action, 7, false},	{"Look", &do_action, 7, false},
	{"Inventory", &do_action, 1, false},
	{"Broadcast", &do_action, 7, false},
	{"Connect_nbr", &do_action, 0, false},
	{"Fork", &do_action, 42, false}, {"Eject", &do_action, 7, false},
	{"Take", &do_action, 7, false}, {"Set", &do_action, 7, false},
	{"Incantation", &do_action, 300, false}
};

int poll_client_commands(server_t *server, fd_set *readfds)
{
	client_t *client;
	char *command[2];
	char *line;

	for (list_t *cur = server->clients; cur; cur = cur->next) {
		client = cur->data;
		if (FD_ISSET(client->sock, readfds))
			write_cbuf(&client->buffer, client->sock);
		if (!client->buffer.empty &&
			read_cbuf(&client->buffer, (uint8_t **)&line)) {
			command[0] = strtok(line, " ");
			command[1] = strtok(NULL, "");
			add_command(server, client, command);
			free(line);
		}
	}
	return (0);
}

int do_pending_actions(server_t *server)
{
	command_t *command;
	clock_t end = clock();
	double total;

	for (list_t *cur = server->commands; cur; cur = cur->next) {
		command = cur->data;
		total = (double)
			(end - command->start_time) / CLOCKS_PER_SEC * 10;
		if (command->timeout < total) {
			command->do_action(server, command->client,
					   command->args);
			cur = remove_elem(&server->commands, cur->data);
			if (!cur)
				break;
		}
	}
	return (0);
}

static void add_command(server_t *server, client_t *client, char **av)
{
	command_t *command = calloc(1, sizeof(*command));

	if (!command)
		return;
	for (size_t i = 0; i < sizeof(command_assg) /
		sizeof(*command_assg); i++) {
		if (strcmp(av[0], command_assg[i].command) == 0 &&
				  strcmp(client->team->name, GUI_NAME) !=
				  command_assg[i].is_gui) {
			command->args = av[1];
			command->client = client;
			command->timeout = command_assg[i].timeout /
				server->freq;
			command->do_action = command_assg[i].do_action;
			command->start_time = clock();
			add_elem_at_back(&server->commands, command);
			return;
		}
	}
	free(command);
}