/*
** EPITECH PROJECT, 2018
** command_actions
** File description:
** none
*/

#include "server.h"
#include "commands.h"

command_t command[] = {
	{"FORWARD", &forward}, {"RIGHT", &right}, {"LEFT", &left},
	{"LOOK", &look}, {"INVENTORY", &inventory}, {"BROADCAST", &broadcast},
	{"CONNECT", &connect_server}, {"FORK", &born}, {"EJECT", &eject},
	{"TAKE", &take}, {"SET", &set}, {"INCANTATION", &incantation},
	{"DEATH", &death}, {NULL, NULL}
	//TODO: remove NULL, NULL and use a const to know end of array
};

char *connect_server(void)
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
