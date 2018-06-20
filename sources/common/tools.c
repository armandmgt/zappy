/*
** EPITECH PROJECT, 2018
** Project
** File description:
** tools
*/

#include <malloc.h>
#include <string.h>
#include "tools.h"

char **str_to_word_array(char *str)
{
	char **arr = calloc(1, sizeof(char *));

	if (!arr)
		return (NULL);
	arr[0] = strtok(str, " ");
	for (size_t i = 1; arr[i] ;i++) {
		arr = realloc(arr, i + 1);
		arr[i] = strtok(NULL, " ");
	}
	return arr;
}

