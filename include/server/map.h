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
#include "player.h"

typedef struct cmp_s {
	size_t pct;
	resource_t rss;
} cmp_t;

typedef struct cell_s {
	list_t *players;
	uint16_t resource[NB_RESOURCE];
} cell_t;

typedef struct map_s {
	uint32_t x;
	uint32_t y;
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

bool allocate_map(map_t *map_infos);
bool generate_map(uint8_t pct, uint8_t nb_resource, map_t *map_infos);

void free_map(map_t *map_infos);

bool add_random_resource_to_cell(cell_t *cell, uint16_t nb);
bool add_random_resource_at(map_t *map, uint32_t x, uint32_t y);
bool add_resource_to_cell(cell_t *cell, resource_t resource, uint16_t nb);
bool remove_resource_on_cell(cell_t *cell, resource_t resource, uint16_t nb);
uint16_t get_resource_on_cell(cell_t const *cell, resource_t resource);

cell_t *get_client_cell(map_t const *map_infos, client_t const *client);
cell_t *get_cell_at(map_t const *map_infos, uint32_t x, uint32_t y);
list_t **get_player_list_at(map_t *map_infos, uint32_t x, uint32_t y);

void spawn_resources(map_t *map);
