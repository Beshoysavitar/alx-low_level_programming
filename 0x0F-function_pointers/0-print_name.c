#include "function_pointers.h"

/**
 * print_name - a function that prints a name.
 * @name: char
 * @f: void
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != '\0' && f != '\0')
		f(name);
}
