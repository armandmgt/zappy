/*
** EPITECH PROJECT, 2018
** Project
** File description
** linked_list.h
*/

#pragma once

#include <stdbool.h>
#include <unistd.h>

typedef struct list_s {
	void *data;
	struct list_s *next;
} list_t;

typedef struct player_s {
	char *team_name;
	size_t life_time;
	size_t *inventory;
	size_t level;
	int socket;
	struct player_s *next;
}		player_t;

bool add_elem(list_t **, char const *, size_t, int);
void free_list(list_t *);