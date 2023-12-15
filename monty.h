#ifndef MONTY_H
#define MONTY_H

#define MAX_LINE_LENGTH 1024 /*Maximum length of a line in the input file*/
#define STACKSIZE 1024 /*Maximum size of the stack*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

/*Function prototypes for the monty*/
void pall_f(stack_t **head, unsigned int counter);
void bnp_push(stack_t **custom_stack, unsigned int line_num);
int main(int argc, char *argv[]);
int bnp_getline(char **customBuf, size_t *customBufSize, FILE *inputStr);
int check_numeric(const char *input_str);
void bnp_pop(stack_t **custom_stack, unsigned int counter);
void bnp_swap(stack_t **custom_stack, unsigned int counter);
void bnp_add(stack_t **custom_stack, unsigned int counter);
void bnp_div(stack_t **custom_stack, unsigned int counter);
void bnp_mul(stack_t **custom_stack, unsigned int counter);
void bnp_sub(stack_t **custom_stack, unsigned int counter);
void bnp_mod(stack_t **custom_stack, unsigned int counter);
#endif /*MONTY_H*/
