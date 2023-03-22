#include "main.h"
/**
 * print_last_digit - prints last digit
 * @c: c is an integer
 * Description: prints last digit
 * Return: last
 */
int print_last_digit(int c)
{
	int last = c % 10;

	if (last < 0)
	{
		last = last * -1;
	}
	_putchar(last + '0');
	return (last);
}
