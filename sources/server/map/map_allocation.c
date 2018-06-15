/*
** EPITECH PROJECT, 2018
** Project
** File description
** map_allocation.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "server/map.h"

static void fill_line(size_t size, cell_t *line)
{
	for (int j = 0; j < size; j++) {
		line[j].players = NULL;
		line[j].resource = calloc(NB_RESOURCE, sizeof(size_t));
	}
}

bool allocate_map(map_t *map)
{
	int i = 0;

	map->map = malloc(sizeof(cell_t *) * (map->y + 1));
	if (!map->map) {
		perror("Malloc:");
		return (false);
	}
	while (i < map->y) {
		map->map[i] = malloc(sizeof(cell_t) * (map->x + 1));
		if (!map->map[i]) {
			perror("Malloc:");
			return (false);
		}
		fill_line(map->x, map->map[i]);
		i++;
	}
	map->map[i] = NULL;
	return (true);
}

static void print_cell_resource(int x, int y, cell_t *cell)
{
	printf("[%d][%d] -> ", x, y);
	for (int i = 0; i < NB_RESOURCE; i++) {
		printf("%ld", cell->resource[i]);
		if (i + 1 < NB_RESOURCE)
			printf(" ");
	}
	printf("\n");
}

void print_map(map_t *map)
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
