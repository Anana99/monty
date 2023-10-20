#include "monty.h"
void monty_rotl(monty_stack_t **stack, unsigned int line_number);
void monty_rotr(monty_stack_t **stack, unsigned int line_number);
void monty_stack(monty_stack_t **stack, unsigned int line_number);
void monty_queue(monty_stack_t **stack, unsigned int line_number);
/**
 * monty_rotl - Rotates the top value of a monty_stack_t linked list to the bottom.
 * @stack: A pointer to the top mode node of a monty_stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_rotl(monty_stack_t **stack, unsigned int line_number)
{
	monty_stack_t *top, *bottom;
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;
	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;
	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;
	(void)line_number;
}
/**
 * monty_rotr - Rotates the bottom value of a monty_stack_t linked list to the top.
 * @stack: A pointer to the top mode node of a monty_stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_rotr(monty_stack_t **stack, unsigned int line_number)
{
	monty_stack_t *top, *bottom;
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;
	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;
	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;
	(void)line_number;
}
/**
 * monty_stack - Converts a queue to a stack.
 * @stack: A pointer to the top mode node of a monty_stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_stack(monty_stack_t **stack, unsigned int line_number)
{
	(*stack)->n = MODE_STACK;
	(void)line_number;
}
/**
 * monty_queue - Converts a stack to a queue.
 * @stack: A pointer to the top mode node of a monty_stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_queue(monty_stack_t **stack, unsigned int line_number)
{
	(*stack)->n = MODE_QUEUE;
	(void)line_number;
}
