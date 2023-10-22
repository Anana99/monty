#include "monty.h"

/**
 * pint - Prints the value at the top of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode in the file
 * @n_str: Unused parameter
 *
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int line_number, const char *n_str)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
	(void)n_str;
}
