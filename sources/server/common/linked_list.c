/*
** EPITECH PROJECT, 2018
** Project
** File description
** linked_list.c
*/

#include <malloc.h>
#include <string.h>
#include "../../../include/common/linked_list.h"

static player_t *new_elem(char const *name, size_t life_time, int socket);

bool add_elem(list_t **players, char const *name, size_t life_time, int socket)
{
	player_t *new = new_elem(name, life_time, socket);
	player_t *tmp = (*players)->data;

	if (!new)
		return (false);
	if (!tmp)
		(*players)->data = new;
	else {
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (true);
}

void free_list(list_t *players)
{
	list_t *tmp;
	player_t *player;

	while (players) {
		tmp = players;
		players = players->next;
		player = tmp->data;
		free(player->team_name);
		free(tmp);
	}
}

static player_t *new_elem(char const *name, size_t life_time, int socket)
{
	player_t *new = malloc(sizeof(player_t));

	if (!new) {
		perror("Malloc:");
		return (NULL);
	}
	if (!(new->team_name = strdup(name))) {
		perror("Malloc:");
		return (NULL);
	}
	new->level = 1;
	new->inventory = (size_t[7]) {0, 0, 0, 0, 0, 0, 0};
	new->life_time = life_time;
	new->socket = socket;
	return (new);
}