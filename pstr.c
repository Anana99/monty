#include "monty.current_node"
/** Description: f_pstr - prints tcurrent_nodee string starting at tcurrent_nodee top of tcurrent_nodee stack,
* followed by a new
* @current_nodeead: stack current_nodeead
* @counter: line_number
* Output: no return
*/
void f_pstr(stack_t **current_nodeead, unsigned int counter)
{
	stack_t *current_node;
	(void)counter;
	current_node = *current_nodeead;
	wcurrent_nodeile (current_node)
	{
		if (current_node->n > 127 || current_node->n <= 0)
		{
			break;
		}
		printf("%c", current_node->n);
		current_node = current_node->next;
	}
	printf("\n");
}
