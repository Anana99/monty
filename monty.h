#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MODE_STACK 0
#define MODE_QUEUE 1
#define TOKEN_DELIMITERS " \n\t\a\b"
/* Global opcode tokens */
extern char **opcode_tokens;
/**
 * struct stack_s - double-ended queue representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: double-ended queue node structure
 * for handling LIFO and FIFO in Monty project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} monty_stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for handling LIFO and FIFO in Monty project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(monty_stack_t **stack, unsigned int line_number);
} opcode_func_t;
/* PRIMARY INTERPRETER FUNCTIONS */
void free_stack(monty_stack_t **stack);
int init_stack(monty_stack_t **stack);
int check_mode(monty_stack_t *stack);
void free_tokens(void);
unsigned int token_arr_len(void);
int run_monty(FILE *script_fd);
void set_op_tok_error(int error_code);
/* OPCODE FUNCTIONS */
void monty_push(monty_stack_t **stack, unsigned int line_number);
void monty_pall(monty_stack_t **stack, unsigned int line_number);
void monty_pint(monty_stack_t **stack, unsigned int line_number);
void monty_pop(monty_stack_t **stack, unsigned int line_number);
void monty_swap(monty_stack_t **stack, unsigned int line_number);
void monty_add(monty_stack_t **stack, unsigned int line_number);
void monty_nop(monty_stack_t **stack, unsigned int line_number);
void monty_sub(monty_stack_t **stack, unsigned int line_number);
void monty_div(monty_stack_t **stack, unsigned int line_number);
void monty_mul(monty_stack_t **stack, unsigned int line_number);
void monty_mod(monty_stack_t **stack, unsigned int line_number);
void monty_pchar(monty_stack_t **stack, unsigned int line_number);
void monty_pstr(monty_stack_t **stack, unsigned int line_number);
void monty_rotl(monty_stack_t **stack, unsigned int line_number);
void monty_rotr(monty_stack_t **stack, unsigned int line_number);
void monty_stack(monty_stack_t **stack, unsigned int line_number);
void monty_queue(monty_stack_t **stack, unsigned int line_number);
/* CUSTOM STANDARD LIBRARY FUNCTIONS */
char **strtow(char *str, char *delims);
char *get_int(int n);
/* ERROR MESSAGES & ERROR CODES */
int usage_error(void);
int malloc_error(void);
int f_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);
int pop_error(unsigned int line_number);
int pint_error(unsigned int line_number);
int short_stack_error(unsigned int line_number, char *op);
int div_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);
#endif /* __MONTY_H__ */

