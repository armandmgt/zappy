/*
** EPITECH PROJECT, 2018
** Project
** File description
** cell_management.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "map.h"

bool add_resource_to_cell(cell_t *cell, resource_t res, uint16_t nb)
{
	if (!cell) {
		fprintf(stderr, "invalid pointer\n");
		return (false);
	}
	cell->resource[res] += nb;
	return (true);
}

bool add_random_resource_at(map_t *map, uint32_t x, uint32_t y)
{
	size_t rd = (size_t)(rand() % NB_RESOURCE);

	if (!map) {
		fprintf(stderr, "invalid pointer\n");
		return (false);
	}
	map->map[y][x].resource[rd] += 1;
	return (true);
}

bool add_random_resource_to_cell(cell_t *cell, uint16_t nb)
{
	size_t rd = (size_t)(rand() % 100);

	if (!cell) {
		fprintf(stderr, "invalid pointer\n");
		return (false);
	}
	for (size_t i = 0; i < NB_RESOURCE; i++) {
		if (gamble[i].pct > rd) {
			cell->resource[i] += nb;
			break;
		}
	}
	return (true);
}

bool remove_resource_on_cell(cell_t *cell, resource_t res, uint16_t nb)
{
	if (!cell) {
		fprintf(stderr, "invalid pointer\n");
		return (false);
	}
	cell->resource[res] -= nb;
	return (true);
}

uint16_t get_resource_on_cell(cell_t const *const cell, resource_t res)
{
	if (!cell) {
		fprintf(stderr, "invalid pointer\n");
		return (0);
	}
	return (cell->resource[res]);
}
