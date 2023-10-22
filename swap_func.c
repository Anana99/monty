#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode in the file
 * @n_str: Unused parameter
 *
 * Return: Nothing
 */
void swap(stack_t **stack, unsigned int line_number, const char *n_str)
{
	int temp_n;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	temp_n = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp_n;

	(void)n_str;
}
