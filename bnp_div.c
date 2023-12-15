#include "monty.h"
/**
 * bnp_div - Divides the top two elements of the stack.
 * @custom_stack: stack head
 * @counter: line_number
 * Return: no return
*/
void bnp_div(stack_t **custom_stack, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *custom_stack;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*custom_stack);
		exit(EXIT_FAILURE);
	}
	h = *custom_stack;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*custom_stack);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n / h->n;
	h->next->n = aux;
	*custom_stack = h->next;
	free(h);
}
