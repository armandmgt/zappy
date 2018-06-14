/*
** EPITECH PROJECT, 2018
** Project
** File description
** linked_list.c
*/

#include <string.h>
#include <stdlib.h>
#include "common/linked_list.h"

bool add_elem_at_front(list_t **players, void *data, void (*free_func)(void *))
{
	list_t *node = calloc(sizeof(**players), 1);

	if (!node)
		return (false);
	node->next = *players;
	node->data = data;
	node->free_func = free_func;
	*players = node;
	return (true);
}

void free_list(list_t *list)
{
	list_t *ptr;
	void *data;

	while (list) {
		ptr = list;
		list = list->next;
		data = ptr->data;
		if (ptr->free_func)
			ptr->free_func(data);
		free(data);
		free(ptr);
	}
}

size_t list_len(list_t *list)
{
	size_t len = 0;

	for (; list; list = list->next)
		len++;
	return (len);
}
