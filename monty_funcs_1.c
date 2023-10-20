#include "monty.h"
void monty_push(monty_stack_t **stack, unsigned int line_number);
void monty_pall(monty_stack_t **stack, unsigned int line_number);
void monty_pint(monty_stack_t **stack, unsigned int line_number);
void monty_pop(monty_stack_t **stack, unsigned int line_number);
void monty_swap(monty_stack_t **stack, unsigned int line_number);
/**
 * monty_push - Pushes a value to a monty_stack_t linked list.
 * @stack: A pointer to the top mode node of a monty_stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_push(monty_stack_t **stack, unsigned int line_number)
{
	monty_stack_t *tmp, *new;
	int i;
	new = malloc(sizeof(monty_stack_t));
	if (new == NULL)
	{
		set_op_tok_error(malloc_error());
		return;
	}
	if (opcode_tokens[1] == NULL)
	{
		set_op_tok_error(no_int_error(line_number));
		return;
	}
	for (i = 0; opcode_tokens[1][i]; i++)
	{
		if (opcode_tokens[1][i] == '-' && i == 0)
			continue;
		if (opcode_tokens[1][i] < '0' || opcode_tokens[1][i] > '9')
		{
			set_op_tok_error(no_int_error(line_number));
			return;
		}
	}
	new->n = atoi(opcode_tokens[1]);
	if (check_mode(*stack) == MODE_STACK) /* MODE_STACK mode insert at front */
	{
		tmp = (*stack)->next;
		new->prev = *stack;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	}
	else /* MODE_QUEUE mode insert at end */
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}
}
/**
 * monty_pall - Prints the values of a monty_stack_t linked list.
 * @stack: A pointer to the top mode node of a monty_stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_pall(monty_stack_t **stack, unsigned int line_number)
{
	monty_stack_t *tmp = (*stack)->next;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}
/**
 * monty_pint - Prints the top value of a monty_stack_t linked list.
 * @stack: A pointer to the top mode node of a monty_stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_pint(monty_stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pint_error(line_number));
		return;
	}
	printf("%d\n", (*stack)->next->n);
}
/**
 * monty_pop - Removes the top value element of a monty_stack_t linked list.
 * @stack: A pointer to the top mode node of a monty_stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_pop(monty_stack_t **stack, unsigned int line_number)
{
	monty_stack_t *next = NULL;
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pop_error(line_number));
		return;
	}
	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}
/**
 * monty_swap - Swaps the top two value elements of a monty_stack_t linked list.
 * @stack: A pointer to the top mode node of a monty_stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_swap(monty_stack_t **stack, unsigned int line_number)
{
	monty_stack_t *tmp;
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "swap"));
		return;
	}
	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}
