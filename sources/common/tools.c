/*
** EPITECH PROJECT, 2018
** Project
** File description:
** tools
*/

#include "tools.h"

uint32_t wrapped_coord(int32_t coord, uint32_t range)
{
	return ((coord + range) % range);
}
