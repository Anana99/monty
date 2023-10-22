#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure for stack, queue
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number, const char *n_str);
} instruction_t;

/* Function Prototypes */
void execute_opcode(stack_t **stack, char *opcode, unsigned int line_number,
	char *argument);
int is_number(const char *str);
char *custom_strdup(const char *str);
void tokenize_line(char *line, char **opcode, char **argument);
void push(stack_t **stack, unsigned int line_number, const char *n_str);
void pall(stack_t **stack, unsigned int line_number, const char *n_str);
void pint(stack_t **stack, unsigned int line_number, const char *n_str);
void pop(stack_t **stack, unsigned int line_number, const char *n_str);
void swap(stack_t **stack, unsigned int line_number, const char *n_str);
void add(stack_t **stack, unsigned int line_number, const char *n_str);
void nop(stack_t **stack, unsigned int line_number, const char *n_str);
void free_stack(stack_t **stack);
ssize_t read_line(FILE *file, char **line);

#endif /* MONTY_H */
