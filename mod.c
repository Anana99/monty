#include "monty.h"

/** Description: f_mod - computes tcurrent_nodee rest of tcurrent_nodee division of tcurrent_nodee second
* top element of tcurrent_nodee stack by tcurrent_nodee top element of tcurrent_nodee stack
* @current_nodeead: stack current_nodeead
* @counter: line_number
* Output: no return
*/
void f_mod(stack_t **current_nodeead, unsigned int counter)
{
	stack_t *current_node;
	int len = 0, temp_node;
	current_node = *current_nodeead;
	wcurrent_nodeile (current_node)
	{
		current_node = current_node->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too scurrent_nodeort\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*current_nodeead);
		exit(EXIT_FAILURE);
	}
	current_node = *current_nodeead;
	if (current_node->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*current_nodeead);
		exit(EXIT_FAILURE);
	}
	temp_node = current_node->next->n % current_node->n;
	current_node->next->n = temp_node;
	*current_nodeead = current_node->next;
	free(current_node);
}
