#include "shell.h"
/**
*_puts - print a string
*@str: string
*Return: 0
*/
void _puts(char *str)
{
int s;
s = 0;

while (str[s] != '\0')
{
_putchar(str[s]);
s++;
}
_putchar('\n');
}
/**
 *_strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: elem2
 */
int _strcmp(char *s1, char *s2)
{
	int elem1, elem2;

	elem1 = 0;
	while (s1[elem1] == s2[elem1] && s1[elem1] != '\0' && s2[elem1] != '\0')
	{
		elem1++;
	}
	if (s1[elem1] < s2[elem1] || s1[elem1] > s2[elem1])
	{
		elem2 = s1[elem1] - s2[elem1];
	}
	else
	{
		elem2 = 0;
	}
	return (elem2);
}
/**
 * _strlen - returns length of the string
 * @s: string to be evaluated
 * Return: length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

