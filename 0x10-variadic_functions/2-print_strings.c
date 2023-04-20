#include "variadic_functions.h"

/**
 * print_strings - a function prints numbers followed by a new line
 * @n: number of parameter
 * @separator: separator between two numbers
 * Return: Always 0
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int j;
	va_list a;
	char *s;

	if (separator == NULL)
		separator = "";
	if (!n)
	{
		printf("\n");
		return;
	}
	va_start(a, n);
	for (j = 0; j < n; j++)
	{
		s = va_arg(a, char*);
		if (s == NULL)
			s = "(nil)";
		printf("%s", s);
		if (j < n - 1)
			printf("%s", separator);
	}
	printf("\n");
	va_end(a);
}
