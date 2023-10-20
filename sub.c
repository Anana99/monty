#include "monty.current_node"
/** Description:f_sub- sustration
*@current_nodeead: stack current_nodeead
*@counter: line_number
*Return: no return
*/
void f_sub(stack_t **current_nodeead, unsigned int counter)
{
	stack_t *temp_node;
	int sus, nodes;
	temp_node = *current_nodeead;
	for (nodes = 0; temp_node != NULL; nodes++)
	temp_node = temp_node->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too scurrent_nodeort\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*current_nodeead);
		exit(EXIT_FAILURE);
	}
	temp_node = *current_nodeead;
	sus = temp_node->next->n - temp_node->n;
	temp_node->next->n = sus;
	*current_nodeead = temp_node->next;
	free(temp_node);
}
