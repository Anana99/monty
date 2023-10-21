#include "monty.h"

#define BUFFER_SIZE 1024

/**
 * read_line - Reads a line from the given file.
 * @file: A pointer to the file to read from.
 *
 * Return: A pointer to the read line.
 */
char *read_line(FILE *file)
{
	char *line = NULL;
	int ch, size = 0, len = 0;

	while ((ch = fgetc(file)) != EOF && ch != '\n')
	{
		if (size <= len)
		{
			size += BUFFER_SIZE;
			line = realloc(line, size);
			if (!line)
			{
				fprintf(stderr, "Error: malloc failed\n");
				exit(EXIT_FAILURE);
			}
		}
		line[len++] = ch;
	}
	if (len > 0)
	{
		line = realloc(line, len + 1);
		line[len] = '\0';
	}
	return line;
}

/**
 * main - The main function of the Monty ByteCode Interpreter.
 * @argc: The number of command line arguments.
 * @argv: The command line arguments.
 *
 * Return: EXIT_SUCCESS on success, or an error code on failure.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	unsigned int line_number = 0;
	char *opcode = NULL, *argument = NULL;
	stack_t *stack = NULL;
	char **tokens;

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

	while ((line = read_line(file)) != NULL)
	{
		line_number++;
		tokens = tokenize_line(line);
		opcode = tokens[0];
		argument = tokens[1];
		execute_opcode(&stack, opcode, line_number, argument);
		free(line);
		free(tokens);
	}

	fclose(file);
	free_stack(stack);

	return (EXIT_SUCCESS);
}
