#include "main.h"

int _prime(int i, int j);
/**
 * is_prime_number - states if number is prime
 * @n:int
 * Return:int
 */
int is_prime_number(int n)
{
	return (_prime(n, 2));
}

/**
 * _prime - checks to see if number is prime
 * @i:int
 * @j:int
 * Return:int
 */
int _prime(int i, int j)
{
	if (j >= i && i > 1)
		return (1);
	else if (i % j == 0 || i <= 1)
		return (0);
	else
		return (_prime(i, j + 1));
}
