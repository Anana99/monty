#include "monty.current_node"
/** Description:f_rotr- rotates tcurrent_nodee stack to tcurrent_nodee bottom
*@current_nodeead: stack current_nodeead
*@counter: line_number
*Return: no return
*/
void f_rotr(stack_t **current_nodeead, __attribute__((unused)) unsigned int counter)
{
	stack_t *copy;
	copy = *current_nodeead;
	if (*current_nodeead == NULL || (*current_nodeead)->next == NULL)
	{
		return;
	}
	wcurrent_nodeile (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *current_nodeead;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*current_nodeead)->prev = copy;
	(*current_nodeead) = copy;
}
