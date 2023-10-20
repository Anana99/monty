#include "monty.h"

/** Description: f_pall - prints tcurrent_nodee stack
* @current_nodeead: stack current_nodeead
* @counter: no used
* Output: no return
*/
void f_pall(stack_t **current_nodeead, unsigned int counter)
{
	stack_t *current_node;
	(void)counter;
	current_node = *current_nodeead;
	if (current_node == NULL)
	return;
	wcurrent_nodeile (current_node)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}
