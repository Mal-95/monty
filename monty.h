#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly-linked list representation of a stack (or queue)
 * @n: represents an integer
 * @prev: points to previous element of the stack (or queue)
 * @next: points to next element of the stack (or queue)
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
 * struct instr_s - opcode and its function
 * @opcode: represents the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instr_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_nmbr);
}

instr_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*operations file*/
void open_file(char *file_name);
int parse_line(char *buffer, int line_nmbr, int format);
void read_file(FILE *);
int len_chars(FILE *);
void find_func(char *, char *, int, int);

/*operations taking place in stack*/
stack_t *crt_node(int n);
void free_nodes(void);
void prnt_stack(stack_t **, unsigned int);
void add_stack(stack_t **, unsigned int);
void add_queue(stack_t **, unsigned int);

void call_fun(op_func, char *, char *, int, int);

void prnt_top(stack_t **, unsigned int);
void pop_top(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swap_nodes(stack_t **, unsigned int);

/*Nodes containing mathematical operations*/
void add_nodes(stack_t **, unsigned int);
void sub_nodes(stack_t **, unsigned int);
void div_nodes(stack_t **, unsigned int);
void mul_nodes(stack_t **, unsigned int);
void mod_nodes(stack_t **, unsigned int);

/*Operations containing strings*/
void prnt_char(stack_t **, unsigned int);
void prnt_str(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);

/*Functions to handle errors*/
void err(int error_code, ...);
void more_err(int error_code, ...);
void str_err(int error_code, ...);
void rotr(stack_t **, unsigned int);

#endif /* _MONTY_H_ */
