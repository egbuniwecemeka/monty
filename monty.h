#ifndef MONTY_H
#define MONTY_H

#define GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctypes.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/* File functions */
void open_file(*file_name);
int parse_file(char *buffer, int line_number, int format);
void read_file(FILE *);
int len_chars(FILE *);
void find_finc(char, char, int, int);

/* Stack operations */
stack_t *create_node(int n);
void free_node(void);
void print_stack(stack_t **, unsigned int);
void add_to_stack(stack_t **, unsigned int);
void add_to_queue(stack_t **, unsigned int);

void call_fun(op_fun, char *, char *, int, int);

void print_top(stack_t **, unsigned int);
void pop_top(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swap_nodes(stack_t **, unsigned int);

/* Math operation for nodes */
void add_node(stack **, unsigned int);
void sub_node(stack **, unsigned int);
void div_node(stack **, unsigned int);
void mul_node(stack **, unsigned int);
void mod_node(stack **, unsigned int);

