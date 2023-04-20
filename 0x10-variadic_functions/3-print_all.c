#include "variadic_functions.h"

/**
 * print_all - Prints all
 * @format: specifies the necessary operations
 * Return: void
 */

void print_all(const char * const format, ...)
{
	int i = 0;
	int f;
	char *s;
	va_list a;

	va_start(a, format);

	while (format != NULL && format[i] != '\0')
	{
		switch (format[i])
		{
			case 's':
				s = va_arg(a, char*);
				if (s == NULL)
					s = "(nil)";
				printf("%s", s);
				f = 0;
				break;

			default:
				f = 1;
				break;

			case 'f':
				printf("%f", va_arg(a, double));
				f = 0;
				break;

			case 'c':
				printf("%c", va_arg(a, int));
				f = 0;
				break;

			case 'i':
				printf("%i", va_arg(a, int));
				f = 0;
				break;

		}
		if (format[i + 1] != '\0' && f == 0)
			printf(", ");
		i++;
	}
	printf("\n");
	va_end(a);
}
