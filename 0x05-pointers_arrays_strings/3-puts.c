#include "main.h"
/**
 * _puts - Entry point
 * Descripton:  function that prints a string
 * @str: string
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}
