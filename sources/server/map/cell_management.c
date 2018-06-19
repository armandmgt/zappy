/*
** EPITECH PROJECT, 2018
** Project
** File description
** cell_management.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "server/map.h"

bool add_resource_to_cell(cell_t *cell, resource_t res, uint16_t nb)
{
	if (!cell) {
		fprintf(stderr, "invalid pointer\n");
		return (false);
	}
	cell->resource[res] += nb;
	return (true);
}

bool add_random_resource_to_cell(cell_t *cell, uint16_t nb)
{
	int rd = rand() % (100);
	int i = 0;

	if (!cell) {
		fprintf(stderr, "invalid pointer\n");
		return (false);
	}
	for (; i < NB_RESOURCE; i++) {
		if (gamble[i].pct > rd)
			break;
	}
	cell->resource[i] += nb;
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

size_t get_resource_on_cell(cell_t const *const cell, resource_t res)
{
	if (!cell) {
		fprintf(stderr, "invalid pointer\n");
		return (0);
	}
	return (cell->resource[res]);
}
