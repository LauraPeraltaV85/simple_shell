#include "shell.h"
/**
*sighandler - inhibits ctrl c signal
*@sign: void
*/
void sighandler(int sign)
{
	(void) sign;

	write(1, "\n$ ", 3);
}
/**
 * main - entry point
 *
 * Return: 0 on success and -1 on failure
 */
int main(void)
{
	char *buffer = NULL, **args = NULL, *first_arg = NULL;
	size_t size = 0;
	int run = 0, i = 1;
	struct stat st;

	signal(SIGINT, sighandler);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			(write(STDOUT_FILENO, "$ ", 2));
		buffer = getline_func(buffer, size);
		if (buffer == NULL)
			continue;
		args = tokenizer(buffer);
		if (args[0] != NULL)
		{
			first_arg = args[0];
			if (builtins(args, buffer) == -1)
			{
				if (stat(args[0], &st) == 0)
					run = command(args);
				else if (stat(args[0], &st) == -1)
				{
					args[0] = path(args[0]);
					if (args[0] == NULL)
					{
						error_msg(first_arg, i), i++; }
					else
						run = command(args); }
				if (run == -1)
				{
					error_msg(first_arg, i);
					i++; } }
				free(args);
				args = NULL;
				buffer = NULL; }
		free(args);
		free(buffer); }
	return (0);
}
