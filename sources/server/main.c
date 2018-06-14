/*
** EPITECH PROJECT, 2017
** zappy
** File description:
** Created by armandmgt,
*/

#include <stdio.h>
#include "../../include/server/map.h"

int main()
{
	map_t map;
	fprintf(stdout, "hello world from server\n");
	generate_map(10, 10, 10, &map);
	print_map(&map);
	free_map(&map);
	return (0);
}