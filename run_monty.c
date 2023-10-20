#define _POSIX_C_SOURCE 200809L
#include "monty.h"
#include <string.h>
void free_tokens(void);
unsigned int token_arr_len(void);
int is_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(monty_stack_t**, unsigned int);
int run_monty(FILE *script_fd);

/**
 * free_tokens - Frees the global opcode_tokens array of strings.
 */
void free_tokens(void)
{
	size_t i = 0;
	if (opcode_tokens == NULL)
		return;
	for (i = 0; opcode_tokens[i]; i++)
		free(opcode_tokens[i]);
	free(opcode_tokens);
}

int run_monty(FILE *script_fd)
{
	monty_stack_t *stack = NULL;
	char *line = NULL;
	char buffer[1024];
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_number = 0;
	
	if (init_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	
	while (fgets(buffer, sizeof(buffer), script_fd) != NULL)
	{
		line = strdup(buffer);
		len = strlen(line);
		if (line[len - 1] == '\n')
		{
			line[len - 1] = '\0';  /* remove the newline character */
		}
		line_number++;
		opcode_tokens = strtow(line, TOKEN_DELIMITERS);
		if (opcode_tokens == NULL)
		{
			if (is_empty_line(line, TOKEN_DELIMITERS))
				continue;
			free_stack(&stack);
			return (malloc_error());
		}
	}
	free_stack(&stack);
	if (line && *line == 0)
	{
		free(line);
		return (malloc_error());
	}
	free(line);
	return (exit_status);
}
