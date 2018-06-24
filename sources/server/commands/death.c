/*
** EPITECH PROJECT, 2018
** Project
** File description:
** death
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "server/gui_magic.h"
#include "common/tools.h"
#include "server/server.h"
#include "gui_commands.h"

static void print_ko(client_t *client, list_t *cmds)
{
	for (list_t *cur = cmds; cur; cur = cur->next) {
		dprintf(client->sock, "ko\n");
	}
}

bool death(server_t *server, client_t *client, char *UNUSED(args))
{
	for (list_t *tmp = server->clients; tmp; tmp = tmp->next) {
		if (tmp->data == client && client->infos->lifetime == 0 &&
			client->team && strcmp(client->team->name, GUI_NAME)) {
			dprintf(client->sock, "dead\n");
			print_in_gui(server->clients, "pdi %d\n",
				     client->infos->id);
			close(client->sock);
			free(client->infos);
			print_ko(client, client->cmds);
			free(tmp->data);
			tmp->data = NULL;
			return (true);
		}
	}
	return (false);
}