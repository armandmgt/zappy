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

static void loop_on_clients(server_t *server, client_t *client, char *args);
static double inverse_positions(client_t *client, client_t *tmp);
static double the_smallest(client_t *UNUSED(client), client_t *UNUSED(tmp),
	double tan);
static void convertion_to_position(server_t *server, client_t *client,
	double angle);

bool broadcast(server_t *server, client_t *client, char *args)
{
	loop_on_clients(server, client, args);
	dprintf(client->sock, "ok\n");
	print_in_gui(server->clients, "pbc %d %s\n", client->infos->id, args);
	return (true);
}

static void loop_on_clients(server_t *server, client_t *client, char *args)
{
	list_t *list = server->clients;
	client_t *tmp;
	double delta_x;
	double delta_y;
	double tan;
	double result;

	while (list) {
		tmp = list->data;
		delta_x = client->infos->pos.x - tmp->infos->pos.x;
		delta_y = client->infos->pos.y - tmp->infos->pos.y;
		tan = delta_y / delta_x;
		result = the_smallest(client, tmp, tan);
		convertion_to_position(server, client, result);
		dprintf(tmp->sock, "message %lf, %s\n", result, args);
		list = list->next;
	}
}

static double the_smallest(client_t *client, client_t *tmp, double tan)
{
	double i_tan = inverse_positions(client, tmp);

	if (i_tan - tan > 0)
		return (atan(tan));
	return (atan(i_tan));
}

static double inverse_positions(client_t *client, client_t *tmp)
{
	double i_delta_x = tmp->infos->pos.x - client->infos->pos.x;
	double i_delta_y = tmp->infos->pos.y - client->infos->pos.y;
	double i_tan = i_delta_y / i_delta_x;
	return (i_tan);
}

static void convertion_to_position(server_t *UNUSED(server), client_t *UNUSED(client),
	double angle)
{
	double degrees = (angle * 180.0 / M_PI);
}
