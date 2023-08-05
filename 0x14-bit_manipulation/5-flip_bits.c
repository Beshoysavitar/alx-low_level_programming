#include "main.h"

/**
 * flip_bits - ***
 *
 * @n: ***
 * @m: ***
 *
 * Return: number of bits to flip to convert numbers
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int c = 0;
	unsigned long int x = n ^ m;

	while (x)
	{
		c += x & 1;
		x >>= 1;
	}

	return (c);
}
