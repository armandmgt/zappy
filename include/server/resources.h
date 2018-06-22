/*
** EPITECH PROJECT, 2017
** Project
** File description:
** Created by armandmgt,
*/

#pragma once

#define RESOURCES_NAME_LEN 16

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
	char name[RESOURCES_NAME_LEN];
} resource_name_t;

static resource_name_t const res_name[NB_RESOURCE] = {
	{FOOD, "food"}, {LINEMATE, "linemate"},
	{DERAUMERE, "deraumere"}, {SIBUR, "sibur"},
	{MENDIANE, "mendiane"}, {PHIRAS, "phiras"},
	{THYSTAME, "thystame"}
};
