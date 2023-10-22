#include "monty.h"

/**
 * free_stack - Frees a stack.
 * @stack: A pointer to the top (stack) or bottom (queue) of a stack_t.
 *
 * Description: This function will free the entire stack.
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

/**
 * is_number - Checks if a string represents a valid integer.
 * @str: The string to check.
 *
 * Return: 1 if the string is a valid integer, otherwise 0.
 *
 * Description: This function checks if a given string represents
 * a valid number.
 */
int is_number(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

