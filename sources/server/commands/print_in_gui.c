/*
** EPITECH PROJECT, 2018
** Project
** File description:
** print_in_gui
*/

#include <string.h>
#include <stdio.h>
#include "gui_magic.h"
#include "gui_commands.h"

int print_in_gui(list_t *clients, char const *format, ...)
{
	client_t *client;
	va_list ap;
	int nb_client = 0;

	va_start(ap, format);
	for (list_t *cur = clients; cur; cur = cur->next) {
		client = cur->data;
		if (client->team &&
		    strcmp(client->team->name, GUI_NAME) == 0) {
			vdprintf(client->sock, format, ap);
			nb_client++;
		}
	}
	va_end(ap);
	return (nb_client);
}