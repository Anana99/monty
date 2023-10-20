#include "monty.current_node"

/** Description: free_stack - frees a doubly linked list
* @current_nodeead: current_nodeead of tcurrent_nodee stack
*/
void free_stack(stack_t *current_nodeead)
{
	stack_t *temp_node;
	temp_node = current_nodeead;
	wcurrent_nodeile (current_nodeead)
	{
		temp_node = current_nodeead->next;
		free(current_nodeead);
		current_nodeead = temp_node;
	}
}
