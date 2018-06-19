/*
** EPITECH PROJECT, 2017
** Project
** File description:
** Created by armandmgt,
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "cir_buffer.h"

ssize_t write_cbuf(cir_buffer_t *buffer, int fd)
{
	ssize_t read_size = buffer->end - buffer->write_ptr;

	read_size = read(fd, buffer->write_ptr, (size_t)read_size);
	if (read_size <= 0)
		return (read_size);
	buffer->empty = false;
	buffer->write_ptr += read_size;
	if (buffer->write_ptr == buffer->end) {
		buffer->write_ptr = buffer->buffer;
	}
	return (read_size);
}

uint8_t *find_line_end(cir_buffer_t *buffer)
{
	uint8_t *delim;
	size_t search_size = buffer->write_ptr <= buffer->read_ptr ?
		buffer->end - buffer->read_ptr :
		buffer->write_ptr - buffer->read_ptr;
	delim = memchr(buffer->read_ptr, '\n', search_size);
	if (!delim && buffer->write_ptr < buffer->read_ptr) {
		search_size = buffer->write_ptr - buffer->buffer;
		delim = memchr(buffer->buffer, '\n', search_size);
	}
	if (!delim)
		return (NULL);
	return (delim);
}

uint8_t *alloc_line(cir_buffer_t *buffer, const uint8_t *endptr)
{
	size_t size = 0;

	size = endptr > buffer->read_ptr ? endptr - buffer->read_ptr :
		(buffer->end - buffer->read_ptr) + (endptr - buffer->buffer);
	return (calloc(sizeof(uint8_t), size + 1));
}

void copy_line(cir_buffer_t *buffer, uint8_t *line, const uint8_t *endptr)
{
	size_t offset;
	size_t len;

	if (endptr > buffer->read_ptr) {
		len = endptr - buffer->read_ptr;
		memcpy(line, buffer->read_ptr, len);
	} else {
		offset = len = buffer->end - buffer->read_ptr;
		memcpy(line, buffer->read_ptr, len);
		len = endptr - buffer->buffer;
		memcpy(line + offset, buffer->buffer, len);
	}
}

int read_cbuf(cir_buffer_t *buffer, uint8_t **line)
{
	uint8_t *endptr = find_line_end(buffer);

	if (buffer->empty || !endptr || !(*line = alloc_line(buffer, endptr)))
		return (0);
	copy_line(buffer, *line, endptr);
	buffer->read_ptr = endptr + 1;
	if (buffer->write_ptr == buffer->read_ptr) {
		buffer->empty = true;
	}
	return (1);
}
