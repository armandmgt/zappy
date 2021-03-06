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
#include "server/gui_magic.h"
#include "command_value.h"
#include "gui_commands.h"

static void add_command(server_t *server, client_t *client, char **av);
static void send_pnw_to_gui(server_t *server, client_t *client);

static  command_values_t const cmd_ass[] = {
	{"Forward", NULL, &forward, 7, false},
	{"Right", NULL, &right, 7, false}, {"Left", NULL, &left, 7, false},
	{"Look", NULL, &look, 7, false},
	{"Inventory", NULL, &inventory, 1, false},
	{"Broadcast", NULL, &broadcast, 7, false},
	{"Connect_nbr", NULL, &connect_nbr, 0, false},
	{"Fork", NULL, &birth, 42, false}, {"Eject", NULL, &eject, 7, false},
	{"Take", NULL, &take, 7, false}, {"Set", NULL, &set, 7, false},
	{"Incantation", incantation, &elevation, 300, false},
	{"msz", NULL, &msz, 0, true}, {"bct", NULL, &bct, 0, true},
	{"mct", NULL, &mct, 0, true}, {"ppo", NULL, &ppo, 0, true},
	{"plv", NULL, &plv, 0, true}, {"pin", NULL, &pin, 0, true},
	{"tna", NULL, &tna, 0, true}, {"sgt", NULL, &sgt, 0, true},
	{"sst", NULL, &sst, 0, true}
};

static void handle_new_command(server_t *server, client_t *client, char *ln)
{
	char *command[2];

	command[0] = strtok(ln, " ");
	command[1] = strtok(NULL, "");
	add_command(server, client, command);
	free(ln);
}

int poll_client_commands(server_t *server, fd_set *readfds)
{
	client_t *client;
	char *ln;

	for (list_t *cur = server->clients; cur; cur = cur->next) {
		client = cur->data;
		if (FD_ISSET(client->sock, readfds) &&
			write_cbuf(&client->buff, client->sock) <= 0) {
			print_in_gui(server->clients, "pdi %d\n",
				     client->infos->id);
			cur = remove_elem(&server->clients, client);
		}
		if (!cur)
			break;
		if (!client->buff.empty && read_cbuf(&client->buff, &ln))
			handle_new_command(server, client, ln);
	}
	return (0);
}

static void stock_command(client_t *client, server_t *server, char **av,
			size_t i)
{
	command_t *command = calloc(1, sizeof(*command));

	if (!command || !av)
		return;
	if (av[1])
		command->args = strdup(av[1]);
	command->t_out = cmd_ass[i].timeout / server->freq;
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
			if (!cmd_ass[i].b_action || (cmd_ass[i].b_action &&
			    cmd_ass[i].b_action(server, client, av[i]) == 1))
				stock_command(client, server, av, i);
			return;
		}
	}
	if (client->team)
		return (void)dprintf(client->sock, "ko\n");
	for (list_t *cur = server->teams; cur; cur = cur->next)
		if (strcmp(av[0], ((team_t *)cur->data)->name) == 0)
			client->team = cur->data;
	if (client->team)
		send_pnw_to_gui(server, client);
}

static void send_pnw_to_gui(server_t *server, client_t *client)
{
	client_t *tmp;

	if (strcmp(client->team->name, GUI_NAME) != 0) {
		dprintf(client->sock, "%d\n%d %d\n", count_in_team(server,
			client), server->map_infos.x, server->map_infos.y);
		print_in_gui(server->clients, "pnw %d %d %d %d %d %s\n",
			client->infos->id, client->infos->pos.x,
			client->infos->pos.y, client->infos->direction + 1,
			client->infos->level, client->team->name);
		return;
	}
	for (list_t *cur = server->clients; cur; cur = cur->next) {
		tmp = cur->data;
		if (tmp->team && strcmp(tmp->team->name, GUI_NAME) != 0)
			print_in_gui(server->clients,
				"pnw %d %d %d %d %d %s\n",
				tmp->infos->id, tmp->infos->pos.x,
				tmp->infos->pos.y, tmp->infos->direction + 1,
				tmp->infos->level, tmp->team->name);
	}
}
