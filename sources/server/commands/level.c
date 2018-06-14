/*
** EPITECH PROJECT, 2018
** command_states
** File description:
** none
*/

#include "commands.h"

void level2(infos_t *infos)
{
	if (infos->nb_player == 1 && infos->ressources[linemate] >= 1)
		infos->ressources[linemate] -= 1;
}

void level3(infos_t *infos)
{
	if (infos->nb_player == 2 && (infos->ressources[linemate] >= 1 &&
	infos->ressources[deraumere] >= 1 && infos->ressources[sibur] >= 1)) {
		infos->ressources[linemate] -= 1;
		infos->ressources[deraumere] -= 1;
		infos->ressources[sibur] -= 1;
	}
}

void level4(infos_t *infos)
{
	if (infos->nb_player == 2 && (infos->ressources[linemate] >= 2 &&
	infos->ressources[sibur] >= 1 && infos->ressources[phiras] >= 2)) {
		infos->ressources[linemate] = infos->ressources[linemate] - 2;
		infos->ressources[sibur] -= 1;
		infos->ressources[phiras] = infos->ressources[phiras] - 2;
	}
}

void level5(infos_t *infos)
{
	if (infos->nb_player == 4 && (infos->ressources[linemate] >= 1 &&
	infos->ressources[deraumere] >= 1 && infos->ressources[sibur] >= 2 &&
	infos->ressources[phiras] >= 1)) {
		infos->ressources[linemate] -= 1;
		infos->ressources[deraumere] -= 1;
		infos->ressources[sibur] = infos->ressources[sibur] - 2;
		infos->ressources[phiras] -= 1;
	}
}

void level6(infos_t *infos)
{
	if (infos->nb_player == 4 && (infos->ressources[linemate] >= 1 &&
	infos->ressources[deraumere] >= 2 && infos->ressources[sibur] >= 1 &&
	infos->ressources[mendiane] >= 3)) {
		infos->ressources[linemate] -= 1;
		infos->ressources[deraumere] = infos->ressources[deraumere] - 2;
		infos->ressources[sibur] -= 1;
		infos->ressources[mendiane] = infos->ressources[mendiane] - 3;
	}
}
