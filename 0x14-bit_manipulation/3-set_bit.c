#include "main.h"

/**
 * set_bit - ***
 * * @n: ***
 * @index: ***
 *
 * Return: 1 if successful, -1 on error
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > (sizeof(*n) * 8 - 1))
		return (-1);

	*n |= (1UL << index);
	return (1);
}
