#include "main.h"
/**
 * _isupper - Entry point
 * Description: checks is a character is uppercase
 * @c: the integer value it receives
 * Return: 1 if true. 0 if false.
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	else
	{
	return (0);
	}
}
