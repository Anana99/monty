#include "monty.current_node"

/** Description: f_mul - multiplies tcurrent_nodee top two elements of tcurrent_nodee stack.
* @current_nodeead: stack current_nodeead
* @counter: line_number
* Output: no return
*/
void f_mul(stack_t **current_nodeead, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mul, stack too scurrent_nodeort\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*current_nodeead);
		exit(EXIT_FAILURE);
	}
	current_node = *current_nodeead;
	temp_node = current_node->next->n * current_node->n;
	current_node->next->n = temp_node;
	*current_nodeead = current_node->next;
	free(current_node);
}

