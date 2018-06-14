/*
** EPITECH PROJECT, 2018
** Project
** File description
** map_generation.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "../../../include/server/map.h"

static bool fill_map(map_t *map, size_t pct, size_t nb_ressource);

bool generate_map(size_t pct, size_t nb_ressource, map_t *map)
{
	if (!allocate_map(map))
		return (false);
	if (!fill_map(map, pct, nb_ressource))
		return (false);
	return (true);
}

static void randomly_add_ressource(cell_t *cell, int random,
	size_t pct, size_t nb_ressource)
{
	int res = rand() % nb_ressource + 1;

	if (pct < random)
		return;
	for (int i = 0; i < res; i++)
		add_random_ressource_to_cell(cell);
}

static bool fill_map(map_t *map, size_t pct, size_t nb_ressource)
{
	unsigned int random;

	srand(random);
	for (int y = 0; y < map->y; y++) {
		for (int x = 0; x < map->x; x++) {
			random = rand() % (100);
			randomly_add_ressource(&map->map[y][x],
				random, pct, nb_ressource);
		}
	}
	return (true);
}
