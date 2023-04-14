#include "main.h"

/**
 * _calloc - allocates memory for an array
 *
 * @nmemb: int elements
 *
 * @size: int size
 *
 * Return: allocated memory.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *s;

	/*checks if null*/
	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}

	/*allocate memory*/
	s = malloc(size * nmemb);

	/*check null*/
	if (s == NULL)
	{
		return (NULL);
	}

	/*allocates memory for an array*/
	for (i = 0; i < (size * nmemb * sizeof(char)); i++)
	{
		s[i] = 0;
	}

	/*alocated memory*/
	return (s);
}
