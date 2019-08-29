#include "shell.h"
/**
 * findpath - searches the environment for PATH
 *
 * Return: NULL
 */
char *findpath(void)
{
	char *token = NULL, *copy = NULL;
	char keyword[] = "PATH";
	int i = 0;

	while (environ[i] != NULL)
	{
		copy  = _strdup(environ[i]);
		if (copy == NULL)
			return (NULL);

		token = strtok(copy, "=");
		if (strcmp(token, keyword) == 0)
		{
			free(copy);
			return (environ[i]);
		}
		i++;
		free(copy);
	}
	return (NULL);
}
