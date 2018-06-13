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

char *forward(void);
char *right(void);
char *left(void);
char *look(void);
char *inventory(void);
char *broadcast(void);
char *connect_server(void);
char *born(void);
char *eject(void);
char *take(void);
char *set(void);
char *incantation(void);
char *death(void);
