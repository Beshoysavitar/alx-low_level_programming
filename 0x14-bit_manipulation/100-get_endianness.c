#include "main.h"

/**
 * get_endianness - ***
 *
 * Return: 0 if big endian, 1 if small
 */
int get_endianness(void)
{
	unsigned int q = 1;
	char *i = (char *) &q;

	return (*i);
}
