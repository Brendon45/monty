#include "monty.h"

/**
* bnp_push - A function that implements the push opcode
* @custom_stack: A pointer to the stack
* @line_num: The current line number in the file
*/

void bnp_push(stack_t **custom_stack, unsigned int line_num)
{
	stack_t *new_element;
	char *input_arg;

	/* Extract the integer argument from the line */
	input_arg = strtok(NULL, " \t\n");
	if (input_arg == NULL || !check_numeric(input_arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}

	/* Allocate memory for a new custom stack node */
	new_element = malloc(sizeof(stack_t));
	if (new_element == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	 /* initialisation of  the new node and push it onto the custom stack */
	new_element->n = atoi(input_arg);
	new_element->prev = NULL;
	new_element->next = *custom_stack;
	if (*custom_stack)
		(*custom_stack)->prev = new_element;
	*custom_stack = new_element;
}
