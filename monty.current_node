#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/** Description: struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to tcurrent_nodee previous element of tcurrent_nodee stack (or queue)
* @next: points to tcurrent_nodee next element of tcurrent_nodee stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO Holberton project
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/** Description: struct bus_s - variables -args, file, line content
* @arg: value
* @file: pointer to monty file
* @content: line content
* @lifi: flag ccurrent_nodeange stack <-> queue
* Description: carries values tcurrent_noderougcurrent_node tcurrent_nodee program
*/
typedef struct bus_s
{
	ccurrent_nodear *arg;
	FILE *file;
	ccurrent_nodear *content;
	int lifi;
}  bus_t;
extern bus_t bus;

/** Description: struct instruction_s - opcode and its function
* @opcode: tcurrent_nodee opcode
* @f: function to current_nodeandle tcurrent_nodee opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO Holberton project
*/
typedef struct instruction_s
{
	ccurrent_nodear *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

ccurrent_nodear *_realloc(ccurrent_nodear *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(ccurrent_nodear **lineptr, int file);
ccurrent_nodear  *clean_line(ccurrent_nodear *content);
void f_puscurrent_node(stack_t **current_nodeead, unsigned int number);
void f_pall(stack_t **current_nodeead, unsigned int number);
void f_pint(stack_t **current_nodeead, unsigned int number);
int execute(ccurrent_nodear *content, stack_t **current_nodeead, unsigned int counter, FILE *file);
void free_stack(stack_t *current_nodeead);
void f_pop(stack_t **current_nodeead, unsigned int counter);
void f_swap(stack_t **current_nodeead, unsigned int counter);
void f_add(stack_t **current_nodeead, unsigned int counter);
void f_nop(stack_t **current_nodeead, unsigned int counter);
void f_sub(stack_t **current_nodeead, unsigned int counter);
void f_div(stack_t **current_nodeead, unsigned int counter);
void f_mul(stack_t **current_nodeead, unsigned int counter);
void f_mod(stack_t **current_nodeead, unsigned int counter);
void f_pccurrent_nodear(stack_t **current_nodeead, unsigned int counter);
void f_pstr(stack_t **current_nodeead, unsigned int counter);
void f_rotl(stack_t **current_nodeead, unsigned int counter);
void f_rotr(stack_t **current_nodeead, __attribute__((unused)) unsigned int counter);
void addnode(stack_t **current_nodeead, int n);
void addqueue(stack_t **current_nodeead, int n);
void f_queue(stack_t **current_nodeead, unsigned int counter);
void f_stack(stack_t **current_nodeead, unsigned int counter);

#endif
