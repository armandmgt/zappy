/*
** EPITECH PROJECT, 2018
** Project
** File description
** print_content.c
*/

#include <stdio.h>
#include "print_content.h"

static void print_cell_content(cell_t *cell, client_t *client);

void print_line_content(map_t *map_infos, client_t *client,
	uint32_t y, uint32_t tiles)
{
	cell_t *tmp;
	uint32_t x = client->infos->pos.x  - (tiles / 2);

	if (y < 0 || y >= map_infos->y)
		y = (y + map_infos->y) % map_infos->y;
	for (uint32_t j = 0; j < tiles; j++) {
		if (x < 0 || x >= map_infos->x)
			x = (x + map_infos->x) % map_infos->x;
		tmp = get_cell_at(map_infos, x, y);
		print_cell_content(tmp, client);
		x++;
	}
}

void print_row_content(map_t *map_infos, client_t *client,
	uint32_t x, uint32_t tiles)
{
	cell_t *tmp;
	uint32_t y = client->infos->pos.y  - (tiles / 2);

	if (x < 0 || x >= map_infos->x)
		x = (x + map_infos->x) % map_infos->x;
	for (uint32_t j = 0; j < tiles; j++) {
		if (y < 0 || y >= map_infos->y) {
			y = (y + map_infos->y) % map_infos->y;
		}
		tmp = get_cell_at(map_infos, x, y);
		print_cell_content(tmp, client);
		y++;
	}
}

static void print_cell_content(cell_t *cell, client_t *client)
{
	static resource_name_t const tab[7] = {
		{FOOD, "food"}, {LINEMATE, "linemate"},
		{DERAUMERE, "deraumere"}, {SIBUR, "sibur"},
		{MENDIANE, "mendiane"}, {PHIRAS, "phiras"},
		{THYSTAME, "thystame"}
	};

	for (size_t i = 0; i < list_len(cell->players); i++) {
		if (i > 0)
			dprintf(client->sock, " ");
		dprintf(client->sock, "player");
	}
	for (size_t i = 0; i < NB_RESOURCE; i++) {
		if (i > 0 || (i == 0 && list_len(cell->players)))
			dprintf(client->sock, " ");
		for (int j = 0; j < get_resource_on_cell(cell,
			(resource_t)i); j++)
			dprintf(client->sock, "%s", tab[i].name);
	}
	dprintf(client->sock, ",");
}
