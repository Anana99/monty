#include "monty.h"
#include <string.h>
void free_stack(monty_stack_t **stack);
int init_stack(monty_stack_t **stack);
int check_mode(monty_stack_t *stack);
/**
 * free_stack - Frees a monty_stack_t stack.
 * @stack: A pointer to the top (stack) or
 *		 bottom (queue) of a monty_stack_t.
 */
void free_stack(monty_stack_t **stack)
{
	monty_stack_t *tmp = *stack;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
/**
 * init_stack - Initializes a monty_stack_t stack with beginning
 *			  stack and ending queue nodes.
 * @stack: A pointer to an unitialized monty_stack_t stack.
 *
 * Return: If an error occurs - EXIT_FAILURE.
 *		 Otherwise - EXIT_SUCCESS.
 */
int init_stack(monty_stack_t **stack)
{
	monty_stack_t *s;
	s = malloc(sizeof(monty_stack_t));
	if (s == NULL)
		return (malloc_error());
	s->n = MODE_STACK;
	s->prev = NULL;
	s->next = NULL;
	*stack = s;
	return (EXIT_SUCCESS);
}
/**
 * check_mode - Checks if a monty_stack_t linked list is in stack or queue mode.
 * @stack: A pointer to the top (stack) or bottom (queue)
 *		 of a monty_stack_t linked list.
 *
 * Return: If the monty_stack_t is in stack mode - MODE_STACK (0).
 *		 If the monty_stack_t is in queue mode - MODE_QUEUE (1).
 *		 Otherwise - 2.
 */
int check_mode(monty_stack_t *stack)
{
	if (stack->n == MODE_STACK)
		return (MODE_STACK);
	else if (stack->n == MODE_QUEUE)
		return (MODE_QUEUE);
	return (2);
}
