#include "monty.h"
/**
 * bnp_pop - prints the top
 * @custom_stack: stack head
 * @counter: line_number
 * Return: no return
*/
void bnp_pop(stack_t **custom_stack, unsigned int counter)
{
	stack_t *h;

	if (*custom_stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*custom_stack);
		exit(EXIT_FAILURE);
	}
	h = *custom_stack;
	*custom_stack = h->next;
	free(h);
}
