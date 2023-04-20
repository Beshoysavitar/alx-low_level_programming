#include "variadic_functions.h"

/**
 * sum_them_all - function that returns the sum of all its parameters.
 * @n: the number of parameters passed
 * Return: Always 0
 */

int sum_them_all(const unsigned int n, ...)
{
	int i, j = n;
	va_list a;

	if (n == 0)
		return (0);
	va_start(a, n);
	i = 0;
	while (j--)
		i += va_arg(a, int);
	va_end(a);
	return (i);
}
