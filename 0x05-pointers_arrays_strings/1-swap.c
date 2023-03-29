#include "main.h"
/**
 * swap_int - Entry point
 * Description: swaps the values of two integers
 * @a: integer 1
 * @b: integer 2
 */
void swap_int(int *a, int *b)
{
	int p;

	p = *a;
	*a = *b;
	*b = p;
}
