/*
** EPITECH PROJECT, 2018
** Project
** File description:
** do_pending_action
*/

#include <time.h>
#include <stdlib.h>
#include "server.h"

static bool check_timer(command_t *cmd, clock_t *end);

int do_pending_actions(server_t *server)
{
	client_t *client;
	command_t *cmd;
	list_t *prev;
	clock_t end = clock();

	for (list_t *cur = server->clients; cur; cur = cur->next) {
		client = cur->data;
		if (!client->cmds)
			continue;
		cmd = client->cmds->data;
		if (check_timer(cmd, &end))
			continue;
		cmd->do_action(server, client, cmd->args);
		if (cmd->args)
			free(cmd->args);
		if (!(prev = remove_elem(&((client_t *)cur->data)->cmds, cmd)))
			break;
		else
			((command_t *)prev->data)->s_time = end;
	}
	return (0);
}

static bool check_timer(command_t *cmd, clock_t *end)
{
	if (cmd->t_out > (double)(*end - cmd->s_time) / CLOCKS_PER_SEC * 10)
		return (true);
	return (false);
}