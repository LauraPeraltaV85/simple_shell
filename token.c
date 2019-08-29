#include "shell.h"
/**
 * tokenizer - parses strings into tokens
 *
 * @buffer: storage space
 * Return: split tokens
 */
char **tokenizer(char *buffer)
{
	char **tokens;
	char *token;
	int i = 0;

	tokens = malloc(sizeof(char *) * 128);
	if (tokens == NULL)
		return (NULL);
	token = strtok(buffer, " \t\n\r");
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, " \t\n\r");
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
