#include "monty.h"
/** Description: f_pop - prints tcurrent_nodee top
* @current_nodeead: stack current_nodeead
* @counter: line_number
* Output: no return
*/
void f_pop(stack_t **current_nodeead, unsigned int counter)
{
	stack_t *current_node;
	if (*current_nodeead == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*current_nodeead);
		exit(EXIT_FAILURE);
	}
	current_node = *current_nodeead;
	*current_nodeead = current_node->next;
	free(current_node);
}
