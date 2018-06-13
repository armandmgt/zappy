/*
** EPITECH PROJECT, 2017
** zappy
** File description:
** Created by armandmgt,
*/

#pragma once

	int init_server(char **av);
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define TEAM_NAME_LEN 64

typedef struct team_s {
	char name[TEAM_NAME_LEN];
	struct team_s *next;
} team_t;

typedef struct options_s {
	uint16_t port;
	unsigned int width;
	unsigned int height;
	team_t *teams;
	unsigned int maxClients;
	unsigned int freq;
} options_t;

typedef struct option_parser_s {
	int opt;
	int (*func)(options_t *, int *, char * const *);
} option_parser_t;

int parse_options(int argc, char * const *argv, options_t *opts);
