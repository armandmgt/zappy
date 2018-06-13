/*
** EPITECH PROJECT, 2018
** command_actions
** File description:
** none
*/

#include <stddef.h>
#include "server/server.h"

command_t command[] = {
	{"FORWARD", &forward}, {"RIGHT", &right}, {"LEFT", &left},
	{"LOOK", &look}, {"INVENTORY", &inventory}, {"BROADCAST", &broadcast},
	{"CONNECT", &connect}, {"FORK", &born}, {"EJECT", &eject},
	{"TAKE", &take}, {"SET", &set}, {"INCANTATION", &incantation},
	{"DEATH", &death}, {NULL, NULL}
};

char *connect(void)
{
	return ("ko");
}

char *born(void)
{
	return ("ko");
}

char *eject(void)
{
	return ("ko");
}

char *take(void)
{
	return ("ko");
}

char *set(void)
{
	return ("ko");
}