#include "monty.h"

/**
* bnp_pall - A function that implements the pall opcode
* @stack: A pointer to the stack
*
* Return: Nothing on (Success)
*/
void bnp_pall(stack_t **stack)
{
	stack_t *current_node = *stack;
	/*Iterate through the custom stack and print each element*/
	while (current_node != NULL)
	{
	printf("%d\n", current_node->n);
	current_node = current_node->next;
	}
}
