/*
** EPITECH PROJECT, 2018
** Project
** File description
** cell_management.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "server/map.h"

bool add_resource_to_cell(cell_t *cell, resource_t res)
{
	if (!cell) {
		fprintf(stderr, "invalid pointer\n");
		return (false);
	}
	cell->resource[res] += 1;
	return (true);
}

bool add_random_resource_to_cell(cell_t *cell)
{
	size_t rd = (size_t)(rand() % (100));

	if (!cell) {
		fprintf(stderr, "invalid pointer\n");
		return (false);
	}
	for (size_t i = 0; i < NB_RESOURCE; i++) {
		if (gamble[i].pct > rd) {
			cell->resource[i] += 1;
			break;
		}
	}
	return (true);
}

bool remove_resource_on_cell(cell_t *cell, resource_t res)
{
	if (!cell) {
		fprintf(stderr, "invalid pointer\n");
		return (false);
	}
	cell->resource[res] -= 1;
	return (true);
}

size_t get_resource_on_cell(cell_t const *const cell, resource_t res)
{
	if (!cell) {
		fprintf(stderr, "invalid pointer\n");
		return (0);
	}
	return (cell->resource[res]);
}
