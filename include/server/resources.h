/*
** EPITECH PROJECT, 2017
** Project
** File description:
** Created by armandmgt,
*/

#pragma once

#define NAME_LEN 16

typedef enum resource_e {
	FOOD,
	LINEMATE,
	DERAUMERE,
	SIBUR,
	MENDIANE,
	PHIRAS,
	THYSTAME,
	NB_RESOURCE
} resource_t;

typedef struct resource_name_s
{
	resource_t res;
	char name[NAME_LEN];
} resource_name_t;
