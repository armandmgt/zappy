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
	void (*free_func)(void *);
	struct list_s *next;
} list_t;

bool add_elem_at_front(list_t **, void *data, void (*free_func)(void *));
void free_list(list_t *);