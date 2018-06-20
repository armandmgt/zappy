/*
** EPITECH PROJECT, 2018
** zappy_server
** File description
** cell_infos.c
*/

#include "server.h"

cell_t *get_client_cell(map_t const *map_infos, client_t const *client)
{
	return (&map_infos->map[client->infos->pos.y][client->infos->pos.x]);
}

cell_t *get_cell_at(map_t const *map_infos, uint32_t x, uint32_t y)
{
	return (&map_infos->map[y][x]);
}

list_t *get_player_list_at(map_t const *map_infos, uint32_t x, uint32_t y)
{
	return (map_infos->map[y][x].players);
}