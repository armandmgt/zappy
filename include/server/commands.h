/*
** EPITECH PROJECT, 2017
** Project
** File description:
** Created by armandmgt,
*/

#pragma once

#include <stddef.h>

static const int CMD_LEN = 13;

typedef struct command_s
{
	char *cmd;
	char *(*ptr_func)(cell_t *cells);
} command_t;

char *forward(cell_t *cells);
char *right(cell_t *cells);
char *left(cell_t *cells);
char *look(cell_t *cells);
char *inventory(cell_t *cells);
char *broadcast(cell_t *cells);
char *connect(cell_t *cells);
char *born(cell_t *cells);
char *eject(cell_t *cells);
char *take(cell_t *cells);
char *set(cell_t *cells);
char *incantation(cell_t *cells);
char *death(cell_t *cells);
