/*
** EPITECH PROJECT, 2018
** command_actions
** File description:
** none
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "server/commands.h"
#include "common/tools.h"
#include "gui_commands.h"

static int convertion_to_degree(client_t *client, double angle);
static int get_direction(server_t *server, client_t *client, client_t *tmp);
static int determine_angle(int angle);

bool broadcast(server_t *server, client_t *client, char *args)
{
	int direction;
	client_t *tmp_client;

	for (list_t *tmp = server->clients; tmp; tmp = tmp->next) {
		tmp_client = tmp->data;
		if (tmp_client != client && (client->infos->pos.x ==
			tmp_client->infos->pos.x && client->infos->pos.y ==
			tmp_client->infos->pos.y)) {
			dprintf(tmp_client->sock, "message 0, %s", args);
		}
		else if (tmp_client != client) {
			direction = get_direction(server, client, tmp_client);
			dprintf(tmp_client->sock, "message %d, %s\n", direction,
				args);
		}
	}
	dprintf(client->sock, "ok\n");
	print_in_gui(server->clients, "pbc %d %s\n", client->infos->id, args);
	return (true);
}

static int get_direction(server_t *server, client_t *client, client_t *tmp)
{
	double delta_x;
	double delta_y;
	double tan;
	double result;
	int direction;

	delta_x = abs(client->infos->pos.x - tmp->infos->pos.x);
	delta_y = abs(client->infos->pos.y - tmp->infos->pos.y);
	if (delta_x > server->map_infos.x / 2)
		delta_x = server->map_infos.x - delta_x;
	if (delta_y > server->map_infos.y / 2)
		delta_y = server->map_infos.y - delta_y;
	tan = delta_y / delta_x;
	result = atan(tan);
	direction = convertion_to_degree(client, result);
	return (direction);
}

static int convertion_to_degree(client_t *client, double angle)
{
	double degrees = (angle * 180.0 / M_PI);
	int orientation = determine_angle(degrees);
	int direction = (8 - client->infos->direction + orientation) % 8;
	return (direction);
}

static int determine_angle(int angle)
{
	if (angle <= 22.5 && angle >= 337.7)
		return (7);
	else if (angle < 67.5 && angle > 22.5)
		return (8);
	else if (angle >= 67.5 && angle <= 112.5)
		return (1);
	else if (angle > 112.5 && angle < 157.5)
		return (2);
	else if (angle >= 157.5 && angle < 202.5)
		return (3);
	else if (angle > 202.5 && angle < 247.5)
		return (4);
	else if (angle >= 247.5 && angle <= 292.5)
		return (5);
	else if (angle > 292.5 && angle < 337.5)
		return (6);
	return (-1);
}
