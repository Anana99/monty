#include "monty.h"

/**
 * pall - Prints all the values on the stack, starting f
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode in the file
 * @n_str: Unused parameter
 *
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int line_number, const char *n_str)
{
	stack_t *temp = *stack;

	(void)line_number;
	(void)n_str;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
