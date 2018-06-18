/*
** EPITECH PROJECT, 2018
** command_actions
** File description:
** none
*/

#include <stddef.h>
#include "server/commands.h"

static command_t const command[] = {
	{"Forward", &forward}, {"Right", &right}, {"Left", &left},
	{"Look", &look}, {"Inventory", &inventory},
	{"Broadcast text", &broadcast}, {"Connect_nbr", &connect},
	{"Fork", &born}, {"Eject", &eject}, {"Take object", &take},
	{"Set object", &set}, {"Incantation", &incantation},
	{"Death", &death}
};

char *connect(client_t *client, char *team, unsigned int max_clients)
{
	int cmpt = 0;
	char *result[256] = {0};

	while (client) {
		if (strcmp(team, client->team->name) == 0)
			cmpt += 1;
	}
	sprintf(result, "%d", max_clients - cmpt);
	return (result);
}

char *birth(cell_t *cells,)
{
	// pid_t pid;
	// int new = 0;

	// pid = fork();
	// if (pid == -1)
	// 	return ("ko\n");
	// else if (pid == 0) {
	// 	new = accept(cells->player->socket, (struct sockaddr *)&addr,
	// 		&client_size);
	// }

	/* créer un oeuf et attendre qu'un client puisse se co*/
	/* augmenter le nombre de client qui peuvent se connecter dans la team*/
	cells->player->nb_player += 1;
	//new:
	cells->player->direction = rand() % 4 - 1;
	cells->player->level = cells->player->level; /*parent*/
	return ("ok\n");
}

char *eject(cell_t *cells)
{
	switch (cells->player->direction)
	{
		case (cells->player->direction == NORTH):
		cells->player->pos[y][x] = cells->player->pos[y + 1][x];
		return ("ok\n");
		//return ("eject: S\n"); /* si y a des gens sur la case */
		case (cells->player->direction == EAST):
		cells->player->pos[y][x] = cells->player->pos[y][x + 1];
		return ("ok");
		//return ("eject: W\n"); /* si y a des gens sur la case */
		case (cells->player->direction == SOUTH):
		cells->player->pos[y][x] = cells->player->pos[y - 1][x];
		return ("ok");
		//return ("eject: N\n"); /* si y a des gens sur la case */
		case (cells->player->direction == WEST):
		cells->player->pos[y][x] = cells->player->pos[y][x - 1];
		return ("ok");
		//return ("eject: E\n"); /* si y a des gens sur la case */
	}
	return ("ko\n");
}

char *take(cell_t *cells, resources nb)
{
	if (cells && cells->resources[nb]) {
		cells->player->inventory[nb] += cells->resources[nb];
		remove_resource_to_cell(cells, nb);
		return ("ok\n");
	}
	return ("ko\n");
}

char *set(cell_t *cells, resources nb)
{
	if (cells && cells->player->inventory[nb]) {
		cells->player->inventory[nb] -= cells->resources[nb];
		add_resource_to_cell(cells, nb);
		return ("ok\n");
	}
	return ("ko\n");
}
