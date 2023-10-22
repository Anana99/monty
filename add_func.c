#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode in the file
 * @n_str: Unused parameter
 *
 * Return: Nothing
 */
void add(stack_t **stack, unsigned int line_number, const char *n_str)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number, n_str);
}

