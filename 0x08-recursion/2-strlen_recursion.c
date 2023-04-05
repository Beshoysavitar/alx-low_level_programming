#include "main.h"

/**
 * _strlen_recursion - returns the length of a string
 * @s: string to calculate the length of
 *
 * Return: length of the string
 */
int _strlen_recursion(char *s)
{
	int i = 0;

	if (*s < '\0')
	{
		_putchar(*s);
		_strlen_recursion(s + 1);
		i++;
	}
	return (i);
}
