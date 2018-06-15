/*
** EPITECH PROJECT, 2017
** zappy
** File description:
** Created by armandmgt,
*/

#pragma once

#include "server.h"

typedef struct option_parser_s {
	int opt;
	int (*func)(options_t *, int *, char * const *);
} option_parser_t;

unsigned long parse_number(int *);
team_t *parse_teams(int *, char * const *);
int port(options_t *, int *, char * const *);
int size(options_t *, int *, char * const *);
int names(options_t *, int *, char * const *);
int client_nb(options_t *, int *, char *const *);
int freq(options_t *, int *, char * const *);
