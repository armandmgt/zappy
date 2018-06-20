/*
** EPITECH PROJECT, 2018
** Project
** File description
** print_content.h
*/

#pragma once
#include "server.h"

void print_line_content(map_t *map_infos, client_t *client,
	int32_t y, uint32_t tiles);
void print_row_content(map_t *map_infos, client_t *client,
	int32_t y, uint32_t tiles);