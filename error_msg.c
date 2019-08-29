#include "shell.h"
/**
 * error_msg - Function that prints error messages
 * @first_arg: user input command
 * @error: Error iteration
 * Return: void
 */
void error_msg(char *first_arg, int error)
{
write(STDERR_FILENO, "./hsh: ", 7);
_printint(error);
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, first_arg, _strlen(first_arg));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, "not found\n", 11);

}
