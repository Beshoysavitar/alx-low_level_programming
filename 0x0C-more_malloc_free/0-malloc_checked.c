#include "main.h"

/**
 * *malloc_checked - cause normal process termination with a status value of 98
 *
 * @b: int
 *
 * Return: pointer to the allocated memory
 */
void *malloc_checked(unsigned int b)
{
	int *i;

	i = malloc(b);

	if (i == 0)
		exit(98);

	return (i);
}
