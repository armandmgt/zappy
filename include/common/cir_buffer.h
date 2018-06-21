/*
** EPITECH PROJECT, 2017
** Project
** File description:
** Created by armandmgt,
*/

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>

/*
** This must be a MACRO because of the array declaration below
*/
#define BUFF_SIZE 4096

typedef struct cir_buffer_s {
	char buffer[BUFF_SIZE];
	char *end;
	char *write_ptr;
	char *read_ptr;
	bool empty;
} cir_buffer_t;

void init_cbuf(cir_buffer_t *buf);
ssize_t write_cbuf(cir_buffer_t *buf, int fd);
int read_cbuf(cir_buffer_t *buf, char **line);
