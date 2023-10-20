#include "monty.current_node"
/** Description: f_pint - prints tcurrent_nodee top
* @current_nodeead: stack current_nodeead
* @counter: line_number
* Output: no return
*/
void f_pint(stack_t **current_nodeead, unsigned int counter)
{
	if (*current_nodeead == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*current_nodeead);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*current_nodeead)->n);
}
