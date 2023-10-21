#include "monty.h"

/**
 * custom_strdup - Duplicates a string.
 * @s: The string to duplicate.
 *
 * Return: A pointer to the duplicated string.
 */
char *custom_strdup(const char *s)
{
	char *dup;
	int len = strlen(s) + 1;

	dup = malloc(len);
	if (!dup)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	return memcpy(dup, s, len);
}

/**
 * execute_opcode - Executes the given opcode.
 * @stack: A pointer to the stack.
 * @opcode: The opcode to execute.
 * @line_number: The current line number.
 * @argument: The argument for the opcode.
 */
void execute_opcode(stack_t **stack, char *opcode, unsigned int line_number, char *argument)
{
	int i;
	instruction_t opcodes[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	if (strcmp(opcode, "push") == 0)
	{
		push(stack, line_number, argument);
		return;
	}

	for (i = 0; opcodes[i].opcode; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}

/**
 * tokenize_line - Tokenizes a line into opcode and argument.
 * @line: The line to tokenize.
 *
 * Return: A pointer to an array of strings (tokens).
 */
char **tokenize_line(char *line)
{
	char **tokens = malloc(sizeof(char *) * 2);
	char *token = strtok(line, " \t\n");

	tokens[0] = token ? custom_strdup(token) : NULL;
	token = strtok(NULL, " \t\n");
	tokens[1] = token ? custom_strdup(token) : NULL;

	return tokens;
}

/* ... The rest of the opcode functions from the previous content ... */
