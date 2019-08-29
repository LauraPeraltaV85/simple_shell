#include "shell.h"
/**
 * getline_func - reads input from user
 *
 * @buffer: storage space for input
 * @size: size in bytes of input
 * Return: Pointer to the buffer
 */
char *getline_func(char *buffer, size_t size)
{
	int input;

	input = getline(&buffer, &size, stdin);
	if (input == EOF)
	{
		free(buffer);
		exit(0);
	}
	if (input == 1 || input == -1 || buffer == NULL)
	{
	free(buffer);
	return (NULL);
	}
	return (buffer);
}

