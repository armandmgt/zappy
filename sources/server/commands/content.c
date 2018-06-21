/*
** EPITECH PROJECT, 2018
** Project
** File description:
** content_command
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gui_commands.h"
#include "tools.h"

static void print_cell_resources(server_t *server, int sock, vec2i_t *pos);

bool msz(server_t *server, client_t *client, char *UNUSED(av))
{
	dprintf(client->sock, "msz %u %u\n",
		server->map_infos.x, server->map_infos.y);
	return (true);
}

bool bct(server_t *server, client_t *client, char *av)
{
	vec2i_t pos;
	char *tokens[2];
	char *endptr;

	tokens[0] = strtok(av, " ");
	tokens[1] = strtok(NULL, " ");
	pos.x = (uint32_t)strtol(tokens[0], &endptr, 10);
	if (*endptr)
		return (false);
	pos.y = (uint32_t)strtol(tokens[1], &endptr, 10);
	if (*endptr)
		return (false);
	print_cell_resources(server, client->sock, &pos);
	return (true);
}

bool mct(server_t *server, client_t *client, char *UNUSED(av))
{
	for (size_t x = 0; x < server->map_infos.x; x++) {
		for (size_t y = 0; y < server->map_infos.y; y++) {
			print_cell_resources(server, client->sock,
				&(vec2i_t){(uint32_t)y, (uint32_t)x});
		}
	}
	return (true);
}

static void print_cell_resources(server_t *server, int sock, vec2i_t *pos)
{
	cell_t *cell;

	cell = get_cell_at(&server->map_infos, pos->x, pos->y);
	dprintf(sock, "bct %u %u", pos->x, pos->y);
	for (size_t i = 0; i < NB_RESOURCE; i++)
		dprintf(sock, " %u", cell->resource[i]);
	dprintf(sock, "\n");
}
