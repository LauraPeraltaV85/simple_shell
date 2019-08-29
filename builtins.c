#include "shell.h"
/**
 * builtins - lists of builtin commands
 *
 * @args: arguments given
 * @buffer: storage space
 * Return: 0
 */
int builtins(char **args, char *buffer)
{
	int idx = 0;
	bin option[] = {
		{"exit", exitfunc},
		{"env", _env},
		{"printenv", _env},
		{NULL, NULL}
	};

	if (args[0] == NULL)
		return (-1);
	while (option[idx].name != NULL)
	{
		if (_strcmp(args[0], option[idx].name) == 0)
			option[idx].func(args, buffer);
		idx++;
	}
	if (option[idx].name == NULL)
		return (-1);
	return (0);
}
/**
 * exitfunc - function called to exit shell
 *
 * @args: arguments given
 * @buffer: storage space
 * Return: 0 on success
*/
int exitfunc(char **args, char *buffer)
{
	free(buffer);
	free(args);
	exit(EXIT_SUCCESS);
}
/**
 * _env - function called to print env
 * @args: arguments given
 * @buffer: storage space
 * Return: 0
 */
int _env(char **args, char *buffer)
{
	int f = 0;
	(void) args;
	(void) buffer;

	for (; environ[f] != NULL; f++)
	{
		_puts(environ[f]);
	}
	return (0);
}
