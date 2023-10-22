#include "monty.h"

/**
 * execute_opcode - Executes the opcode
 * @stack: Double pointer to the head of the stack
 * @opcode: The opcode to execute
 * @line_number: The line number where the opcode is located
 * @argument: The argument for the opcode (like the push argument)
 *
 * Return: Nothing
 */
void execute_opcode(stack_t **stack, char *opcode,
	unsigned int line_number, char *argument)
{
	int i = 0;
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

	while (opcodes[i].opcode)
	{
		if (strcmp(opcodes[i].opcode, opcode) == 0)
		{
			opcodes[i].f(stack, line_number, argument);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * is_number - Checks if a string is a number
 * @str: The string to check
 *
 * Return: 1 if true, 0 otherwise
 */
int is_number(const char *str)
{
	if (!str || *str == '\0')
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (isdigit(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}

/**
 * custom_strdup - Custom string duplication function
 * @str: The source string
 *
 * Return: Pointer to the duplicated string
 */
char *custom_strdup(const char *str)
{
	char *new_str;
	size_t len = 0;
	size_t i;

	if (!str)
		return (NULL);

	while (str[len])
		len++;

	new_str = malloc(len + 1);
	if (!new_str)
		return (NULL);

	for (i = 0; i < len; i++)
		new_str[i] = str[i];
	new_str[len] = '\0';

	return (new_str);
}

/**
 * tokenize_line - Tokenizes a line into opcode and argument
 * @line: The line to tokenize
 * @opcode: Double pointer to store the opcode
 * @argument: Double pointer to store the argument
 *
 * Return: Nothing
 */
void tokenize_line(char *line, char **opcode, char **argument)
{
	char *token = NULL;

	token = strtok(line, " \t\r\n\a");
	*opcode = token ? custom_strdup(token) : NULL;

	token = strtok(NULL, " \t\r\n\a");
	*argument = token ? custom_strdup(token) : NULL;
}

