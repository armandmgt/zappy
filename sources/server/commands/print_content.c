/*
** EPITECH PROJECT, 2018
** Project
** File description
** print_content.c
*/

#include <stdio.h>
#include "server.h"
#include "tools.h"

static void print_cell_content(cell_t *cell, client_t *client);

void print_line_content(map_t *map_infos, client_t *client,
	int32_t tmp_y, uint32_t tiles)
{
	cell_t *tmp_cell;
	int32_t tmp_x = client->infos->direction == NORTH ? client->infos->pos
		.x  - (tiles /	2) : client->infos->pos.x  + (tiles /	2);
	uint32_t x = wrapped_coord(tmp_x, map_infos->x);
	uint32_t y = wrapped_coord(tmp_y, map_infos->y);

	for (uint32_t j = 0; j < tiles; j++) {
		if (j > 0)
			dprintf(client->sock, ",");
		x = wrapped_coord(x, map_infos->x);
		tmp_cell = get_cell_at(map_infos, x, y);
		print_cell_content(tmp_cell, client);
		x = client->infos->direction == NORTH ? x + 1 : x - 1;
	}
	if (tiles == 1)
		dprintf(client->sock, ",");
}

void print_row_content(map_t *map_infos, client_t *client,
	int32_t tmp_x, uint32_t tiles)
{
	cell_t *tmp_cell;
	int32_t tmp_y = client->infos->direction == EAST ? client->infos->pos
		.y  - (tiles /	2) : client->infos->pos.y  + (tiles /	2);
	uint32_t y = wrapped_coord(tmp_y, map_infos->y);
	uint32_t x = wrapped_coord(tmp_x, map_infos->x);

	for (uint32_t j = 0; j < tiles; j++) {
		if (j > 0)
			dprintf(client->sock, ",");
		y = wrapped_coord(y, map_infos->y);
		tmp_cell = get_cell_at(map_infos, x, y);
		print_cell_content(tmp_cell, client);
		y = client->infos->direction == EAST ? y + 1 : y - 1;
	}
	if (tiles == 1)
		dprintf(client->sock, ",");
}

static void print_cell_content(cell_t *cell, client_t *client)
{
	size_t len = list_len(cell->players);

	for (size_t i = 0; i < len; i++)
		dprintf(client->sock, " player");
	for (size_t i = 0; i < NB_RESOURCE; i++) {
		for (int j = 0; j < get_resource_on_cell(cell,
			(resource_t)i); j++)
			dprintf(client->sock, " %s", res_name[i].name);
	}
}
