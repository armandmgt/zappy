/*
** EPITECH PROJECT, 2017
** Project
** File description:
** Created by armandmgt,
*/

#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "server/gui_magic.h"
#include "command_value.h"
#include "gui_commands.h"

static void add_command(server_t *server, client_t *client, char **av);

static  command_values_t const cmd_ass[] = {
	{"Forward", &forward, 7, false}, {"Right", &right, 7, false},
	{"Left", &left, 7, false}, {"Look", &look, 7, false},
	{"Inventory", &inventory, 1, false},
	{"Broadcast text", &broadcast, 7, false},
	{"Connect_nbr", &connect_nbr, 0, false},
	{"Fork", &birth, 42, false}, {"Eject", &eject, 7, false},
	{"Take", &take, 7, false}, {"Set", &set, 7, false},
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
		if (FD_ISSET(client->sock, readfds) &&
			write_cbuf(&client->buffer, client->sock) <= 0)
			cur = remove_elem(&server->clients, client);
		if (!cur)
			break;
		if (!client->buffer.empty &&
			read_cbuf(&client->buffer, &line)) {
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
			if (!prev)
				break;
			else
				((command_t *)prev->data)->s_time = end;
		}
	}
	return (0);
}

static void stock_command(client_t *client, server_t *server, char **av,
			size_t i)
{
	command_t *command = calloc(1, sizeof(*command));

	if (!command || !av)
		return;
	command->args = av[1];
	command->timeout = cmd_ass[i].timeout / server->freq;
	command->do_action = cmd_ass[i].do_action;
	command->s_time = clock();
	add_elem_at_back(&client->cmds, command);
}

static void add_command(server_t *server, client_t *client, char **av)
{
	for (size_t i = 0; i < sizeof(cmd_ass) / sizeof(*cmd_ass); i++) {
		if (!strcmp(av[0], cmd_ass[i].command) && client->team
		 	&& strcmp(client->team->name, GUI_NAME) !=
						 cmd_ass[i].is_gui) {
			stock_command(client, server, av, i);
			return;
		}
	}
	if (client->team)
		return;
	for (list_t *cur = server->teams; cur; cur = cur->next) {
		if (strcmp(av[0], ((team_t *)cur->data)->name) == 0)
			client->team = cur->data;
	}
}
