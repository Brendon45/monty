#include "monty.h"
void bnp(void);

/**
* main - This is the entry point for the Monty ByteCodes interpreter
* @argc: Number of command-line arguments
* @argv: Array of command-line arguments
*
* Return: 0 on success, EXIT_FAILURE on error
*/

int main(int argc, char *argv[])
{
	char *cunt_instru;
	stack_t *stack;
	char *current_line = NULL;
	size_t line_length = 0;
	unsigned int cunt_line_num = 0;
	FILE *source_file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	source_file = fopen(argv[1], "r");
	if (source_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	/*Read each line from the source file*/
	while (bnp_getline(&current_line, &line_length, source_file) != -1)
	{
	cunt_line_num++;
	/*Extract the current instruction from the line*/
	cunt_instru = strtok(current_line, " \t\n");

	if (cunt_instru == NULL || cunt_instru[0] == '#')
		continue;
	/*Check and execute the corresponding instruction*/
	if (strcmp(cunt_instru, "push") == 0)
	{
		bnp_push(&stack, cunt_line_num);
	}
	else if (strcmp(cunt_instru, "pall") == 0)
	{
		bnp_pall(&stack);
	}
	else if (strcmp(cunt_instru, "pint") == 0)
	{
		bnp_pint(&stack, cunt_line_num);
	}
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", cunt_line_num, cunt_instru);
		exit(EXIT_FAILURE);
	}
	}

	fclose(source_file);
	free(current_line);
	return (0);
}
