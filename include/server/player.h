/*
** EPITECH PROJECT, 2018
** Project
** File description
** player.h
*/

#pragma once

#include "resources.h"
#include "cir_buffer.h"
#include "position.h"
#include "linked_list.h"

#define TEAM_NAME_LEN 64

typedef struct team_s {
	char name[TEAM_NAME_LEN];
	uint32_t max_members;
	list_t *members;
} team_t;

typedef struct player_s {
	uint16_t level;
	uint32_t inventory[NB_RESOURCE];
	uint32_t lifetime;
	vec2i_t pos;
	direction_t direction;
} player_t;

typedef struct client_s {
	int sock;
	cir_buffer_t buffer;
	player_t *infos;
	team_t *team;
	clock_t last_tick;
	list_t *cmds;
} client_t;
