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
	int i = 0;

	map->map = malloc(sizeof(cell_t *) * (map->y + 1));
	if (!map->map) {
		perror("Malloc:");
		return (false);
	}
	while (i < map->y) {
		map->map[i] = calloc(map->x, sizeof(cell_t));
		if (!map->map[i]) {
			perror("Calloc:");
			return (false);
		}
		i++;
	}
	map->map[i] = NULL;
	return (true);
}

static void print_cell_resource(int x, int y, cell_t const *const cell)
{
	fprintf(stdout, "[%d][%d] -> ", x, y);
	for (int i = 0; i < NB_RESOURCE; i++) {
		fprintf(stdout, "%ld", cell->resource[i]);
		if (i + 1 < NB_RESOURCE)
			fprintf(stdout, " ");
	}
	fprintf(stdout, "\n");
}

void print_map(map_t const *const map)
{
	for (int y = 0; map->map[y]; y++) {
		for (int x = 0; x < map->x; x++) {
			print_cell_resource(x, y, &map->map[y][x]);
		}
	}
}

void free_map(map_t *map)
{
	if (!map || !map->map) {
		fprintf(stderr, "Invalid map pointer\n");
		return;
	}
	for (int i = 0; i < map->y; i++) {
		free(map->map[i]);
	}
	free(map->map);
}
