/*
** EPITECH PROJECT, 2018
** command_states
** File description:
** none
*/

#include "commands.h"

void level7(infos_t *infos)
{
	if (infos->nb_player == 6 && (infos->ressources[linemate] >= 1 &&
	infos->ressources[deraumere] >= 2 && infos->ressources[sibur] >= 3 &&
	infos->ressources[phiras] >= 1)) {
		infos->ressources[linemate] -= 1;
		infos->ressources[deraumere] = infos->ressources[deraumere] - 2;
		infos->ressources[sibur] = infos->ressources[sibur] - 3;
		infos->ressources[phiras] -= 1;
	}
}

void level8(infos_t *infos)
{
	if (infos->nb_player == 6 && (infos->ressources[linemate] >= 2 &&
	infos->ressources[deraumere] >= 2 && infos->ressources[sibur] >= 2 &&
	infos->ressources[mendiane] >= 2 && infos->ressources[phiras] >= 2 &&
	infos->ressources[thystame] >= 1)) {
		infos->ressources[linemate] = infos->ressources[linemate] - 2;
		infos->ressources[deraumere] = infos->ressources[deraumere] - 2;
		infos->ressources[sibur] = infos->ressources[sibur] - 2;
		infos->ressources[mendiane] = infos->ressources[mendiane] - 2;
		infos->ressources[phiras] = infos->ressources[phiras] - 2;
		infos->ressources[thystame] -= 1;
	}
}
