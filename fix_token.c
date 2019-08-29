#include "shell.h"
/**
 * fix_token - Function concatenates 2 strings
 * @args: arguments given
 * @token: original token
 * Return: copy of token
 */
char *fix_token(char *args, char *token)
{
	char *new_token = NULL;
	int i = 0, j = 0;
	unsigned int total_strlen = 0;

	new_token = NULL;
	if (args == NULL || token == NULL)
		return (NULL);

	total_strlen = (_strlen(args)) + (_strlen(token));
	new_token = malloc((total_strlen + 2) * sizeof(char *));
	if (new_token == NULL)
		return (NULL);

	while (token[i] != '\0')
	{
		new_token[i] = token[i];
		i++;
	}
	new_token[i] = '/';
	while (args[j] != '\0')
	{
		new_token[i + 1] = args[j];
		j++;
		i++;
	}
	new_token[i + 1] = '\0';
	return (new_token);
}
