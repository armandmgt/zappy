/*
** EPITECH PROJECT, 2017
** zappy
** File description:
** Created by armandmgt,
*/

#pragma once

	typedef struct command_s
	{
		char *cmd;
		char *(*ptr_func)(void);
	} command_t;

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


	char *forward(void);
	char *right(void);
	char *left(void);
	char *look(void);
	char *inventory(void);
	char *broadcast(void);
	char *connect(void);
	char *born(void);
	char *eject(void);
	char *take(void);
	char *set(void);
	char *incantation(void);
	char *death(void);