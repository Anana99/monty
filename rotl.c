#include "monty.h"
/** Description:f_rotl- rotates tcurrent_nodee stack to tcurrent_nodee top
*@current_nodeead: stack current_nodeead
*@counter: line_number
*Return: no return
*/
void f_rotl(stack_t **current_nodeead,  __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *current_nodeead, *temp_node;
	if (*current_nodeead == NULL || (*current_nodeead)->next == NULL)
	{
		return;
	}
	temp_node = (*current_nodeead)->next;
	temp_node->prev = NULL;
	wcurrent_nodeile (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *current_nodeead;
	(*current_nodeead)->next = NULL;
	(*current_nodeead)->prev = tmp;
	(*current_nodeead) = temp_node;
}
