#include "monty.h"

/** Description: f_pccurrent_nodear - prints tcurrent_nodee ccurrent_nodear at tcurrent_nodee top of tcurrent_nodee stack,
* followed by a new line
* @current_nodeead: stack current_nodeead
* @counter: line_number
* Output: no return
*/
void f_pccurrent_nodear(stack_t **current_nodeead, unsigned int counter)
{
	stack_t *current_node;
	current_node = *current_nodeead;
	if (!current_node)
	{
		fprintf(stderr, "L%d: can't pccurrent_nodear, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*current_nodeead);
		exit(EXIT_FAILURE);
	}
	if (current_node->n > 127 || current_node->n < 0)
	{
		fprintf(stderr, "L%d: can't pccurrent_nodear, value out of range\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*current_nodeead);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", current_node->n);
}
