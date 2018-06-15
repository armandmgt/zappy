/*
** EPITECH PROJECT, 2018
** Project
** File description
** linked_list.h
*/

#pragma once

#include <stdbool.h>
#include <unistd.h>

typedef struct list_s {
	void *data;
	struct list_s *next;
} list_t;

bool add_elem_at_front(list_t **, void *data);
void free_list(list_t *, void (*free_func)(void *));
size_t list_len(list_t *);
