#include "monty.h"
void monty_nop(monty_stack_t **stack, unsigned int line_number);
void monty_pchar(monty_stack_t **stack, unsigned int line_number);
void monty_pstr(monty_stack_t **stack, unsigned int line_number);
/**
 * monty_nop - Does absolutely nothing for the Monty opcode 'nop'.
 * @stack: A pointer to the top mode node of a monty_stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_nop(monty_stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * monty_pchar - Prints the character in the top value
 *			   node of a monty_stack_t linked list.
 * @stack: A pointer to the top mode node of a monty_stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_pchar(monty_stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pchar_error(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_op_tok_error(pchar_error(line_number, "value out of range"));
		return;
	}
	printf("%c\n", (*stack)->next->n);
}
/**
 * monty_pstr - Prints the string contained in a monty_stack_t linked list.
 * @stack: A pointer to the top mode node of a monty_stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_pstr(monty_stack_t **stack, unsigned int line_number)
{
	monty_stack_t *tmp = (*stack)->next;
	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
	(void)line_number;
}
