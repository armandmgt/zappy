/*
** EPITECH PROJECT, 2017
** Project
** File description:
** Created by armandmgt,
*/

#pragma once

typedef struct command_s
{
	char *cmd;
	char *(*ptr_func)(void);
} command_t;

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
