/*
** EPITECH PROJECT, 2018
** Project
** File description:
** count_in_team
*/

#include <string.h>
#include "server/server.h"

int count_in_team(server_t *server, client_t *client)
{
	int cmpt = 0;
	client_t *tmp;
	list_t *tmp_list = server->clients;

	while (tmp_list) {
		tmp = tmp_list->data;
		if (tmp->team &&
		    strcmp(tmp->team->name, client->team->name) == 0)
			cmpt += 1;
		tmp_list = tmp_list->next;
	}
	return (client->team->max_members - cmpt);
}