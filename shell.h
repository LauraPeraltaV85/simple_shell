#ifndef SHELL_HOLBI_
#define SHELL_HOLBI_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

void error_msg(char *first_arg, int error);
int _printint(int error);
char *fix_token(char *args, char *token);
char *path(char *args);
char *findpath(void);
int command(char **args);
int commandpath(char **args, char **env);
char **tokenizer(char *buffer);
int builtins(char **args, char *buffer);
int _env(char **args, char *buffer);
int exitfunc(char **args, char *buffer);
char *getline_func(char *buffer, size_t size);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strlen(char *s);
int _putchar(char c);
void _puts(char *str);
/**
 * struct builtins - Struct for built-ins
 * @name: built-in name
 * @func: pointer to function
 */
typedef struct builtins
{
	char *name;
	int (*func)(char **args, char *buffer);
} bin;

extern char **environ;

#endif
