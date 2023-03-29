#include "main.h"
/**
 * print_rev - Entry point
 * Desciption: function that prints a string, in reverse
 * @s: char thet prints string
 */
void print_rev(char *s)
{
	int i = 0;

	for (; s[i];)
		i++;
	while (i--)
	{
		_putchar(s[i]);
	}
	_putchar('\n');
}
