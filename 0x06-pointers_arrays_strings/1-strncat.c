#include "main.h"

/**
 * _strncat - concatenates two strings
 *
 * @src: The source of strings
 * @dest: The destination of the string
 * @n: The length of int
 *
 * Return: pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0, j = 0;
	char *s = dest;

	while (dest[i] != '\0')
	{
		s[j] = dest[i];
		i++;
		j++;
	}
	i = 0;

	while (src[i] != '\0' && i < n)
	{
		s[j] = src[i];
		i++;
		j++;
	}
	s[j] = '\0';

	return (dest);
}
