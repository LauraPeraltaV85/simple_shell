#include "shell.h"
/**
 * command - executes given input
 * @args: arguments given
 * Return: 0
 */
int command(char **args)
{
	pid_t child_pid;
	int status;

	if (args == NULL)
		return (-1);

	child_pid = fork();
	if (child_pid < 0)
		return (-1);

	else if (child_pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			free(args[0]);
			return (-1);
		}
	}
	else
		child_pid = wait(&status);
	free(args[0]);
	return (0);
}
