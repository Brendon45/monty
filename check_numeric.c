#include "monty.h"

/**
 * check_numeric - This function checks if a string represents an integer
 * @input_str: The string to be examined
 *
 * Return: 1 if the string is an integer, 0 otherwise
 */

int check_numeric(const char *input_str)
{
	int index;

	/*Check if the input string is NULL or empty*/
	if (input_str == NULL || *input_str == '\0')
	return (0);

	index = 0;

	/*Skip leading sign (+ or -)*/
	if (input_str[index] == '-' || input_str[index] == '+')
		index++;

	/*Check each character in the string*/
	for (; input_str[index] != '\0'; index++)
	{
	/*If a non-digit character is encountered, return 0*/
	if (!isdigit(input_str[index]))
	return (0);
	}

	/*The string is a valid integer*/
	return (1);
}
