#include "monty.h"

/**
 * read_line_custom - Reads a line from a file.
 * @file: The file to read from.
 *
 * Return: The read line or NULL on failure or EOF.
 */
char *read_line_custom(FILE *file)
{
	int ch;
	size_t buff_size = 1024;
	size_t length = 0;
	char *buffer = malloc(buff_size);

	if (!buffer)
		return (NULL);

	while ((ch = fgetc(file)) != EOF && ch != '\n')
	{
		buffer[length++] = ch;
		if (length == buff_size - 1)
		{
			buff_size *= 2;
			buffer = realloc(buffer, buff_size);
			if (!buffer)
				return (NULL);
		}
	}

	if (length == 0 && ch == EOF)
	{
		free(buffer);
		return (NULL);
	}

	buffer[length] = '\0';
	return (buffer);
}

/**
 * main - Main function for Monty bytecode interpreter
 * @argc: Number of arguments
 * @argv: Array of argument strings
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL, *opcode = NULL, *argument = NULL;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (read_line_custom(file) != NULL)
	{
		line_number++;
		tokenize_line(line, &opcode, &argument);
		if (opcode && opcode[0] != '#') /* Ignore comments */
			execute_opcode(&stack, opcode, line_number, argument);
		free(line);
		line = NULL;
	}

	free(line);
	free_stack(&stack);
	fclose(file);
	return (EXIT_SUCCESS);
}

