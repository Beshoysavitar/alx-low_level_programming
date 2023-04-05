#include "main.h"

int _sqrt(int i, int j);

/**
 * _sqrt_recursion - returns the natural square root of a number.
 * @n: input number.
 * Return: natural square root.
 */
int _sqrt_recursion(int n)
{
	return (_sqrt(n, 1));
}

/**
 * _sqrt - recurses to find the natural
 * square root of a number
 * @i: number to calculate the sqaure root of
 * @j: iterator
 *
 * Return: the resulting square root
 */
int _sqrt(int i, int j)
{
	if (j * j == i)
		return (j);
	else if (j * j < i)
		return (_sqrt(i, j + 1));
	else
		return (-1);
}
