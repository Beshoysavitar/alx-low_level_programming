#include "main.h"

/**
 * set_bit - ...
 * @index: ...
 * @n: ...
 * Return: 1
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > (sizeof(*n) * 8 - 1))
		return (-1);
	*n |= (1 << index);
	return (1);
}
