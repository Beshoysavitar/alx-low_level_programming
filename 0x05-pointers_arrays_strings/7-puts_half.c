#include "main.h"
/**
 * puts_half - prints half of a string
 * @str: char to check
 *
 * Return: 0 is success
 */
void puts_half(char *str)
{
	int i = 0, j;
	for (i = 0; str[i] != '\0'; i++)
	if (i + 1 % 2 != '0')
		j = (i - 1) / 2;
	else
		j = (i / 2);
	j++;

	while (str[j] != '\0')
	{
		_putchar(str[j]);
		j++;
	}
	_putchar('\n');
}
