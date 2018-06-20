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
#include "gui_commands.h"

static void add_command(server_t *server, client_t *client, char **av);

static  command_values_t const command_assg[] = {
	{"Forward", &forward, 7, false}, {"Right", &right, 7, false},
	{"Left", &left, 7, false}, {"Look", &look, 7, false},
	{"Inventory", &inventory, 1, false},
	{"Broadcast text", &broadcast, 7, false},
	{"Connect_nbr", &connect_nbr, 0, false},
	{"Fork", &birth, 42, false}, {"Eject", &eject, 7, false},
	{"Take object", &take, 7, false}, {"Set object", &set, 7, false},
	{"Incantation", &incantation, 300, false},
	{"msz", &msz, 0, true}, {"bct", &bct, 0, true},
	{"mct", &mct, 0, true}, {"ppo", &ppo, 0, true},
	{"plv", &plv, 0, true}, {"pin", &pin, 0, true},
	{"tna", &tna, 0, true}, {"sgt", &sgt, 0, true},
	{"sst", &sst, 0, true}
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
	client_t *client;
	command_t *cmd;
	list_t *prev;
	clock_t end = clock();
	double total;

	for (list_t *cur = server->clients; cur; cur = cur->next) {
		client = cur->data;
		if (!client->cmds)
			continue;
		cmd = client->cmds->data;
		total = (double)(end - cmd->s_time) / CLOCKS_PER_SEC * 10;
		if (cmd->timeout < total) {
			cmd->do_action(server, client, cmd->args);
			prev = remove_elem(&((client_t *)cur->data)
				->cmds, cmd);
			if (!prev || !prev->next)
				break;
			else
				((command_t *)prev->next->data)->s_time = end;
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
		if (strcmp(av[0], command_assg[i].command) == 0/* &&
				  strcmp(client->team->name, GUI_NAME) !=
				  command_assg[i].is_gui*/) {
			command->args = av[1];
			command->timeout = command_assg[i].timeout /
				server->freq;
			command->do_action = command_assg[i].do_action;
			command->s_time = clock();
			add_elem_at_back(&client->cmds, command);
			return;
		}
	}
	free(command);
}