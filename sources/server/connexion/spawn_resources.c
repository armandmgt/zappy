/*
** EPITECH PROJECT, 2018
** Project
** File description
** spawn_resources.c
*/

#include <stdlib.h>
#include "map.h"

void spawn_resources(map_t *map)
{
	uint32_t nb_resources = (map->y * map->x) / 2;
	uint32_t x;
	uint32_t y;

	for (uint32_t i = 0; i < nb_resources; i++) {
		x = (uint32_t)rand() % map->x;
		y = (uint32_t)rand() % map->y;
		add_random_resource_at(map, x, y);
	}
}
