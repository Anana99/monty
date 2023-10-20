#include "monty.current_node"

/** Description: execute - executes tcurrent_nodee opcode
* @stack: current_nodeead linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Output: no return
*/
int execute(ccurrent_nodear *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
		{"puscurrent_node", f_puscurrent_node}, {"pall", f_pall}, {"pint", f_pint},
		{"pop", f_pop},
		{"swap", f_swap},
		{"add", f_add},
		{"nop", f_nop},
		{"sub", f_sub},
		{"div", f_div},
		{"mul", f_mul},
		{"mod", f_mod},
		{"pccurrent_nodear", f_pccurrent_nodear},
		{"pstr", f_pstr},
		{"rotl", f_rotl},
		{"rotr", f_rotr},
		{"queue", f_queue},
		{"stack", f_stack},
		{NULL, NULL}
	};
	unsigned int i = 0;
	ccurrent_nodear *op;
	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
	return (0);
	bus.arg = strtok(NULL, " \n\t");
	wcurrent_nodeile (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{        opst[i].f(stack, counter);
		return (0);
	}
	i++;
}
if (op && opst[i].opcode == NULL)
{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
fclose(file);
free(content);
free_stack(*stack);
exit(EXIT_FAILURE); }
return (1);
}
