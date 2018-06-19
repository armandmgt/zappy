/*
** EPITECH PROJECT, 2018
** Project
** File description
** map_allocation.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "server/map.h"

bool allocate_map(map_t *map)
{
	map->map = calloc(map->y + 1, sizeof(cell_t *));
	if (!map->map) {
		perror("calloc:");
		return (false);
	}
	for (size_t i = 0; i < map->y; i++) {
		map->map[i] = calloc(map->x, sizeof(cell_t));
		if (!map->map[i]) {
			perror("calloc:");
			return (false);
		}
	}
	return (true);
}

void free_map(map_t *map)
{
	if (!map || !map->map) {
		fprintf(stderr, "Invalid map pointer\n");
		return;
	}
	for (size_t i = 0; i < map->y; i++) {
		free(map->map[i]);
	}
	free(map->map);
}
