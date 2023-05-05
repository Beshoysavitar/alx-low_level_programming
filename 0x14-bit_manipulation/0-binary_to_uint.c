#include "main.h"
/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: ...
 * Return: ...
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int n = 0;
	int i;

	if (!b)
		return (0);

	for (i = 0; b[i]; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
		n = n * 2 + (b[i] - '0');
	}
	return (n);
}
