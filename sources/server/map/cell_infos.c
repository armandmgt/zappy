/*
** EPITECH PROJECT, 2018
** zappy_server
** File description
** cell_infos.c
*/

#include "map.h"
#include "server/server.h"

cell_t *get_player_cell(map_t const *map_infos, list_t const *client)
{
	client_t *tmp = client->data;

	return (&map_infos->map[tmp->infos->pos.y][tmp->infos->pos.x]);
}

cell_t *get_cell_at(map_t const *map_infos, uint32_t x, uint32_t y)
{
	return (&map_infos->map[y][x]);
}
