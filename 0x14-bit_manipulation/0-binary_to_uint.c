#include "main.h"

/**
 * binary_to_uint - ***
 * @b: ***
 *
 * Return:***
 */
unsigned int binary_to_uint(const char *b)
{
	int x;
	unsigned int q = 0;

	if (!b)
		return (0);

	for (x = 0; b[x]; x++)
	{
		if (b[x] != '0' && b[x] != '1')
			return (0);
		q = q * 2 + (b[x] - '0');
	}

	return (q);
}
