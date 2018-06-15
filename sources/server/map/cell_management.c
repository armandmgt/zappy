/*
** EPITECH PROJECT, 2018
** Project
** File description
** cell_management.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "server/map.h"

bool add_resource_to_cell(cell_t *cell, resource res)
{
	if (!cell) {
		perror("invalid cell pointer");
		return (false);
	}
	cell->resource[res] += 1;
	return (true);
}

bool add_random_resource_to_cell(cell_t *cell)
{
	int rd = rand() % (100);
	int i = 0;

	if (!cell) {
		perror("invalid cell pointer");
		return (false);
	}
	for (; i < NB_RESOURCE; i++) {
		if (gamble[i].pct < rd)
			continue;
		else
			break;
	}
	cell->resource[i] += 1;
	return (true);
}

bool remove_resource_on_cell(cell_t *cell, resource res)
{
	if (!cell) {
		perror("invalid cell pointer");
		return (false);
	}
	cell->resource[res] -= 1;
	return (true);
}

size_t get_resource_on_cell(cell_t const *cell, resource res)
{
	if (!cell) {
		perror("invalid pointer cell");
		return (0);
	}
	return (cell->resource[res]);
}
