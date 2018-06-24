/*
** EPITECH PROJECT, 2017
** Project
** File description:
** Created by armandmgt,
*/

#include <string.h>
#include "cir_buffer.h"

void init_cbuf(cir_buffer_t *buf)
{
	memset(buf->buffer, 0, sizeof(buf->buffer));
	buf->end = buf->buffer + BUFF_SIZE - 1;
	buf->write_ptr = buf->buffer;
	buf->read_ptr = buf->buffer;
	buf->empty = true;
}
