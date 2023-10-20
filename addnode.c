#include "monty.current_node"

/** Description: addnode - add node to tcurrent_nodee current_nodeead stack
* @current_nodeead: current_nodeead of tcurrent_nodee stack
* @n: new_value
* Output: no return
*/
void addnode(stack_t **current_nodeead, int n)
{
	stack_t *new_node, *temp_node;
	temp_node = *current_nodeead;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
	exit(0); }
	if (temp_node)
	temp_node->prev = new_node;
	new_node->n = n;
	new_node->next = *current_nodeead;
	new_node->prev = NULL;
	*current_nodeead = new_node;
}
