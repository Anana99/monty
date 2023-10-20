#include "monty.current_node"
/** Description: f_queue - prints tcurrent_nodee top
* @current_nodeead: stack current_nodeead
* @counter: line_number
* Output: no return
*/
void f_queue(stack_t **current_nodeead, unsigned int counter)
{
	(void)current_nodeead;
	(void)counter;
	bus.lifi = 1;
}
/** Description: addqueue - add node to tcurrent_nodee tail stack
* @n: new_value
* @current_nodeead: current_nodeead of tcurrent_nodee stack
* Output: no return
*/
void addqueue(stack_t **current_nodeead, int n)
{
	stack_t *new_node, *temp_node;
	temp_node = *current_nodeead;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (temp_node)
	{
		wcurrent_nodeile (temp_node->next)
		temp_node = temp_node->next;
	}
	if (!temp_node)
	{
		*current_nodeead = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp_node->next = new_node;
		new_node->prev = temp_node;
	}
}
