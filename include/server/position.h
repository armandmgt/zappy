/*
** EPITECH PROJECT, 2018
** Project
** File description
** position.h
*/

#pragma once

#include <stdint.h>

typedef enum direction_t
{
	NORTH,
	EAST,
	SOUTH,
	WEST
} direction_t;

typedef struct vec2i_s
{
	uint32_t x;
	uint32_t y;
} vec2i_t;
