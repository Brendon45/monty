#include "monty.h"

/**
  *bnp_sub- sustration
  *@custom_stack: stack head
  *@counter: line_number
  *Return: no return
 */
void bnp_sub(stack_t **custom_stack, unsigned int counter)
{
	stack_t *aux;
	int sus, nodes;

	aux = *custom_stack;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*custom_stack);
		exit(EXIT_FAILURE);
	}
	aux = *custom_stack;
	sus = aux->next->n - aux->n;
	aux->next->n = sus;
	*head = aux->next;
	free(aux);
}
