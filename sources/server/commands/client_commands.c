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
#include "server.h"
#include "command_value.h"

static void add_command(server_t *server, client_t *client, cell_t *cell,
	char **av
);

bool do_action(server_t *s, client_t *c, cell_t *cell, char *av)
{
	printf("coucou\n");
}

static  command_values_t const command_assg[] = {
	/*{"Forward", &forward, 7}, {"Right", &right, 7}, {"Left", &left, 7},
	{"Look", &look, 7}, {"Inventory", &inventory, 1},
	{"Broadcast", &broadcast_text, 7}, {"Connect_nbr", &connect_nbr, 0},
	{"Fork", &fork_client, 42}, {"Eject", &eject, 7},
	{"Take", &take_object, 7}, {"Set", &set_object, 7},
	{"Incantation", &incantation, 300}*/
	{"Forward", &do_action, 7}, {"Right", &do_action, 7}, {"Left", &do_action, 7},
	{"Look", &do_action, 7}, {"Inventory", &do_action, 1},
	{"Broadcast", &do_action, 7}, {"Connect_nbr", &do_action, 0},
	{"Fork", &do_action, 42}, {"Eject", &do_action, 7},
	{"Take", &do_action, 7}, {"Set", &do_action, 7},
	{"Incantation", &do_action, 300}
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
			fprintf(stderr, "received line [%s]\n", line);
			command[0] = strtok(line, " ");
			command[1] = strtok(NULL, "");
			printf("%s \n %s \n", command[0],
			       command[1]);
			add_command(server, client, NULL, command);
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
		total = (double)(end - command->start_time) / CLOCKS_PER_SEC;
		printf("[%f] = [%f] ?", command->timeout, total);
		if (command->timeout < total) {
			command->do_action(server, command->client,
					   command->cell, command->args);
			cur = remove_elem(&server->commands, cur->data);
		}
	}
	return (0);
}

static void add_command(server_t *server, client_t *client, cell_t *cell,
	char **av)
{
	command_t *command = calloc(1, sizeof(*command));

	if (!command)
		return;
	for (size_t i = 0; i < sizeof(command_assg) /
		sizeof(*command_assg); i++) {
		if (strcmp(av[0], command_assg[i].command) == 0) {
			command->args = av[1];
			command->client = client;
			command->cell = cell;
			command->timeout = command_assg[i].timeout;
			command->do_action = command_assg[i].do_action;
			command->start_time =  clock();
			add_elem_at_back(&server->commands, command);
			return;
		}
	}
	free(command);
}