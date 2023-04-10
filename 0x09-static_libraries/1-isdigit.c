#include "main.h"
/**
 * _isdigit - Entry point
 * Description: checks for a digit
 * @c: the integer value it recevies
 * Return: 1 if true. 0 if false.
 */
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
	{
	return (0);
	}
}
