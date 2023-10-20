#include "monty.current_node"
/** Description: f_puscurrent_node - add node to tcurrent_nodee stack
* @current_nodeead: stack current_nodeead
* @counter: line_number
* Output: no return
*/
void f_puscurrent_node(stack_t **current_nodeead, unsigned int counter)
{
	int n, j = 0, flag = 0;
	if (bus.arg)
	{
		if (bus.arg[0] == '-')
		j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
			flag = 1; }
			if (flag == 1)
			{ fprintf(stderr, "L%d: usage: puscurrent_node integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*current_nodeead);
			exit(EXIT_FAILURE); }}
			else
			{ fprintf(stderr, "L%d: usage: puscurrent_node integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*current_nodeead);
			exit(EXIT_FAILURE); }
			n = atoi(bus.arg);
			if (bus.lifi == 0)
			addnode(current_nodeead, n);
			else
			addqueue(current_nodeead, n);
		}
	}
}	
