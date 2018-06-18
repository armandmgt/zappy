/*
** EPITECH PROJECT, 2018
** Project
** File description
** map.h
*/

#pragma once

#include <stdbool.h>
#include <unistd.h>
#include "resources.h"
#include "common/linked_list.h"

typedef struct cmp_s {
	size_t pct;
	resource_t rss;
} cmp_t;

typedef struct cell_s {
	list_t *players;
	size_t resource[NB_RESOURCE];
} cell_t;

typedef struct map_s {
	size_t x;
	size_t y;
	cell_t **map;
} map_t;

static cmp_t const gamble[] = {
	{20, FOOD},
	{35, LINEMATE},
	{50, DERAUMERE},
	{65, SIBUR},
	{80, MENDIANE},
	{90, PHIRAS},
	{100, THYSTAME},
};

bool allocate_map(map_t *);
bool generate_map(size_t, size_t, map_t *);
void print_map(map_t const *);
void free_map(map_t *);

bool add_random_resource_to_cell(cell_t *);
bool add_resource_to_cell(cell_t *, resource_t);
bool remove_resource_on_cell(cell_t *, resource_t);
size_t get_resource_on_cell(cell_t const *, resource_t);
