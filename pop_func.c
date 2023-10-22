#include "monty.h"

/**
 * pop - Pops an element from the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode in the file
 * @n_str: Unused parameter
 *
 * Return: Nothing
 */
void pop(stack_t **stack, unsigned int line_number, const char *n_str)
{
	stack_t *temp;

	(void)n_str;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(temp);
}
