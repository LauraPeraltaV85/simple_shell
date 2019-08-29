#include "shell.h"
/**
 **_strdup - Function that returns a pointer to a newly allocated space in
 * memory, which contains a copy of the string given as a parameter
 * @str: string to be copied
 * Return: length of the string
 */
char *_strdup(char *str)
{
	char *point;

	if (str == NULL)
		return (NULL);
	point = malloc((_strlen(str) * sizeof(char)) + 1);
	if (point == NULL)
		return (NULL);
	_strcpy(point, str);
	return (point);
}
/**
 * _strcpy - function that copies the string pointed to by src to dest
 * @src:  string to be copied
 * @dest: returns the copied string
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int element = 0;

	while (src[element])
	{
		dest[element] = src[element];
		element++;
	}
	dest[element] = '\0';
	return (dest);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
