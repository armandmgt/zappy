/*
** EPITECH PROJECT, 2018
** Project
** File description
** map_generation.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <event.h>
#include <stdint-gcc.h>
#include "server/map.h"

static bool fill_map(map_t *map, uint8_t pct, uint8_t nb_resource);

bool generate_map(uint8_t pct, uint8_t nb_resource, map_t *map_infos)
{
	if (!allocate_map(map_infos))
		return (false);
	if (!fill_map(map_infos, pct, nb_resource))
		return (false);
	return (true);
}

static void randomly_add_resource(cell_t *cell, uint32_t random, uint8_t pct,
	uint8_t nb_resource)
{
	int res = rand() % nb_resource + 1;

	if (pct < random)
		return;
	for (int i = 0; i < res; i++)
		add_random_resource_to_cell(cell);
}

static bool fill_map(map_t *map, uint8_t pct, uint8_t nb_resource)
{
	uint32_t random = 0;

	srand((unsigned int)time(NULL));
	for (int y = 0; y < map->y; y++) {
		for (int x = 0; x < map->x; x++) {
			random = (uint32_t)(rand() % (100));
			randomly_add_resource(&map->map[y][x],
				random, pct, nb_resource);
		}
	}
	return (true);
}
