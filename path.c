#include "shell.h"
/**
 * path - finds the directory a command is located at
 * @args: arguments given
 * Return: NULL
 */
char *path(char *args)
{
char *dir = NULL;
	char *token = NULL, *new_token = NULL, *holder_token = NULL;
	struct stat st;

	if (args == NULL)
		return (NULL);

	dir = findpath();
	if (dir == NULL)
		return (NULL);
	dir = _strdup(dir);
	if (dir == NULL)
		return (NULL);

	token = strtok(dir, "=:");
	while (token != NULL)
	{
		holder_token = token;
		new_token = fix_token(args, holder_token);
		if (new_token == NULL)
		{
			free(dir);
			return (NULL);
		}
		if (stat(new_token, &st) == 0)
		{
			free(dir);
			return (new_token);
		}
		token = strtok(NULL, "=:");
		free(new_token);
	}
	free(dir);
	return (NULL);
}
