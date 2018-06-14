/*
** EPITECH PROJECT, 2018
** Project
** File description
** map.h
*/

#pragma once

#include <stdbool.h>
#include <unistd.h>
#include "../common/linked_list.h"

static size_t const NB_RESSOURCE = 7;

typedef enum ressource_e {
	FOOD,
	LINEMATE,
	DERAUMERE,
	SIBUR,
	MENDIANE,
	PHIRAS,
	THYSTAME
}		ressource;

typedef struct cmp_s {
	size_t pct;
	ressource rss;
}		cmp_t;

static cmp_t const gamble[] = {
	{20, FOOD},
	{35, LINEMATE},
	{50, DERAUMERE},
	{65, SIBUR},
	{80, MENDIANE},
	{90, PHIRAS},
	{100, THYSTAME},
};

typedef struct cell_s {
	void *players;
	size_t *ressource;
}	cell_t;

typedef struct map_s {
	size_t x;
	size_t y;
	cell_t **map;
}		map_t;

bool allocate_map(map_t *);
bool generate_map(size_t, size_t, map_t *);
void print_map(map_t *);
void free_map(map_t *);

bool add_random_ressource_to_cell(cell_t *);
bool add_ressource_to_cell(cell_t *, ressource);
bool remove_ressource_on_cell(cell_t *, ressource);
size_t get_ressource_on_cell(cell_t const *, ressource);
