#include "monty.h"
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * free_stack - frees a stack_t stack
 * @stack: stack to be freed
 */
void free_stack(stack_t **stack)
{
	stack_t *current;

	while (*stack != NULL)
	{
		current = *stack;
		*stack = (*stack)->next;
		free(current);
	}
}

/**
 * read_line - reads a line from a file
 * @file: file to read from
 * @line: address of a pointer to store the line
 * Return: the number of characters in the line, or -1 on failure or EOF
 */
ssize_t read_line(FILE *file, char **line)
{
	const size_t chunk_size = 512;
	size_t capacity = chunk_size, length = 0;
	char *buffer = malloc(chunk_size);
	char *temp = NULL;

	if (!buffer)
		return(-1);

	*line = malloc(capacity);
	if (!*line)
	{
		free(buffer);
		return(-1);
	}

	while (fgets(buffer, chunk_size, file) != NULL)
	{
		size_t buffer_length = strlen(buffer);

		while (length + buffer_length + 1 > capacity)
		{
			capacity *= 2;
			temp = realloc(*line, capacity);
			if (!temp)
			{
				free(buffer);
				free(*line);
				return(-1);
			}
			*line = temp;
		}

		strcpy(*line + length, buffer);
		length += buffer_length;

		if (buffer[buffer_length - 1] == '\n')
			break;
	}

	free(buffer);

	if (length == 0)
	{
		free(*line);
		return(-1);
	}

	return (ssize_t)length;
}

