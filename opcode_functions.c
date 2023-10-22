#include "monty.h"

/**
 * custom_strdup - Duplicates a string.
 * @str: The string to duplicate.
 *
 * Return: A pointer to the duplicated string, or NULL on failure.
 */
char *custom_strdup(const char *str)
{
	char *dup;
	size_t len = strlen(str) + 1;

	dup = malloc(len);
	if (!dup)
		return (NULL);

	memcpy(dup, str, len);
	return (dup);
}

/**
 * execute_opcode - Executes an opcode.
 * @stack: A pointer to the top (stack) or bottom (queue) of a stack_t.
 * @opcode: The opcode to execute.
 * @line_number: The current line number.
 * @argument: The argument for the opcode (if any).
 */
void execute_opcode(stack_t **stack, char *opcode, unsigned int line_number,
	char *argument)
{
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	int i = 0;

	for (i = 0; opcodes[i].opcode; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, line_number, argument);
			return;
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}

/**
 * tokenize_line - Tokenizes a line into opcode and argument.
 * @line: The line to tokenize.
 * @opcode: A pointer to a string where the opcode will be stored.
 * @argument: A pointer to a string where the argument will be stored.
 */
void tokenize_line(char *line, char **opcode, char **argument)
{
	char *token = strtok(line, " \t\r\n");

	*opcode = token ? custom_strdup(token) : NULL;

	token = strtok(NULL, " \t\r\n");
	*argument = token ? custom_strdup(token) : NULL;
}
