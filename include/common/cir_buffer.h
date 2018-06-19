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
	uint8_t buffer[BUFF_SIZE];
	uint8_t *end;
	uint8_t *write_ptr;
	uint8_t *read_ptr;
	bool empty;
} cir_buffer_t;

void init_cbuf(cir_buffer_t *buf);
ssize_t write_cbuf(cir_buffer_t *, int);
int read_cbuf(cir_buffer_t *, uint8_t **line);
