#include "main.h"
/**
 * flip_bits - ...
 * @n: the first number
 * @m: the second number
 * Return: the number of bits you would need to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int i = 0;
	unsigned long int x = n ^ m;

	while (x)
	{
		i += x & 1;
		x >>= 1;
	}
	return (i);
}
