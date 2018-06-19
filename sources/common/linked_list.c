/*
** EPITECH PROJECT, 2018
** Project
** File description
** linked_list.c
*/

#include <string.h>
#include <stdlib.h>
#include "common/linked_list.h"

bool add_elem_at_front(list_t **list, void *data)
{
	list_t *node = calloc(1, sizeof(list_t));

	if (!node)
		return (false);
	node->next = *list;
	node->data = data;
	*list = node;
	return (true);
}

bool add_elem_at_back(list_t **list, void *data)
{
	list_t *node = calloc(1, sizeof(list_t));
	list_t *cur = *list;

	if (!node)
		return (false);
	if (!cur) {
		*list = node;
		return (true);
	}
	while (cur->next)
		cur = cur->next;
	cur->next = node;
	return (true);
}

list_t *remove_elem(list_t **list, void *elem)
{
	list_t *prev = NULL;

	for (list_t *cur = *list; cur; cur = cur->next) {
		if (cur->data == elem) {
			prev ? prev->next = cur->next : *list = cur->next;
			free(cur);
			return (prev);
		}
		prev = cur;
	}
	return (NULL);
}

void free_list(list_t *list, void (*free_func)(void *))
{
	list_t *ptr;
	void *data;

	while (list) {
		ptr = list;
		list = list->next;
		data = ptr->data;
		if (free_func)
			free_func(data);
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
