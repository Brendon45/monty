#include "monty.h"

/**
* bnp_getline - A function that implements getline
* @customBuf: A pointer to the buffer where the line will be stored
* @customBufSize: A pointer to the size of the buffer
* @inputStr: The input stream to read from
*
* Return: The number of characters read, or -1 if an error occurs.
*/

int bnp_getline(char **customBuf, size_t *customBufSize, FILE *inputStr)
{
	int character;
	size_t position = 0;

	/*Allocate initial memory for the buffer if it is not already allocated*/
	if (!*customBuf)
	{
	*customBuf = malloc(128);
	if (!*customBuf)
	return (-1);

	*customBufSize = 128;
	}

	/*Read characters from the input stream until EOF or newline*/
	while ((character = getc(inputStr)) != EOF && character != '\n')
	{
	(*customBuf)[position++] = character;

	/*Check if the buffer needs to be resized*/
	if (position + 1 >= *customBufSize)
	{
		size_t newSize = *customBufSize * 2;
		char *newBuffer = realloc(*customBuf, newSize);
	if (!newBuffer)
	return (-1);

	*customBuf = newBuffer;
	*customBufSize = newSize;
	}
	}

	/*Handle case where EOF is encountered, and no characters were read*/
	if (character == EOF && position == 0)
	{
	free(*customBuf);		
	return (-1);
	}

	(*customBuf)[position] = '\0';
	return (position);
}
