#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure for stack double linked list */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/* Structure for opcode and its function */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function prototypes */
char *custom_strdup(const char *s);
char **tokenize_line(char *line);
void execute_opcode(stack_t **stack, char *opcode, unsigned int line_number, char *argument);
void push(stack_t **stack, unsigned int line_number, const char *n_str);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
int is_number(const char *str);
void free_stack(stack_t *stack);

#endif /* MONTY_H */
