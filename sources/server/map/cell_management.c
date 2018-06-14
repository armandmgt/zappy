/*
** EPITECH PROJECT, 2018
** Project
** File description
** cell_management.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "../../../include/server/map.h"

bool add_ressource_to_cell(cell_t *cell, ressource res)
{
	if (!cell) {
		perror("invalid cell pointer");
		return (false);
	}
	cell->ressource[res] += 1;
}

bool add_random_ressource_to_cell(cell_t *cell)
{
	int rd = rand() % (NB_RESSOURCE);

	if (!cell) {
		perror("invalid cell pointer");
		return (false);
	}
	cell->ressource[rd] += 1;
	return (true);
}

bool remove_ressource_on_cell(cell_t *cell, ressource res)
{
	if (!cell) {
		perror("invalid cell pointer");
		return (false);
	}
	cell->ressource[res] -= 1;
	return (true);
}

size_t get_ressource_on_cell(cell_t const *cell, ressource res)
{
	if (!cell) {
		perror("invalid pointer cell");
		return (0);
	}
	return (cell->ressource[res]);
}
