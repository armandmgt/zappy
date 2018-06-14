/*
** EPITECH PROJECT, 2017
** Project
** File description:
** Created by armandmgt,
*/

#pragma once

#include <stddef.h>

typedef struct command_s
{
	char *cmd;
	char *(*ptr_func)(void);
} command_t;

typedef struct infos_s
{
	size_t level;
	size_t *ressources;
	int nb_player;
} infos_t;

char *forward(cell_t *cells);
char *right(cell_t *cells);
char *left(cell_t *cells);
char *look(void);
char *inventory(player_t *player);
char *broadcast(void);
char *connect(void);
char *born(void);
char *eject(void);
char *take(cell_t *cells);
char *set(cell_t *cells);
char *incantation(player_t *player);
char *death(void);

void level2(infos_t *infos);
void level3(infos_t *infos);
void level4(infos_t *infos);
void level5(infos_t *infos);
void level6(infos_t *infos);
void level7(infos_t *infos);
void level8(infos_t *infos);
