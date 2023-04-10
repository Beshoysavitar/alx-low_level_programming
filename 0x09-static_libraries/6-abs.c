#include "main.h"

/**
 * _abs - absolute value of an integer
 *
 * @c: takes in integer type input for function
 *
 * Return: Always 0 (Success)
 */
int _abs(int c)
{
	if (c < 0)
		c = (-1) * c;
	return (c);
}
