#include "main.h"

/**
 * *array_range - creates an array of integers
 * @min: minimum range
 *
 * @max: maximum range
 *
 * Return: the pointer to the newly created array
 */
int *array_range(int min, int max)
{
	int *poi, i, length;

	/*check if min > max*/
	if (min > max)
	{
		return (NULL);
	}

	/*calculate length*/
	length = max - min + 1;

	/*allocates memory*/
	poi = malloc(length * sizeof(int));

	/*check if null*/
	if (poi == NULL)
	{
		return (NULL);
	}

	/*computing the array*/
	for (i = 0; i < length; i++)
	{
		poi[i] = min++;
	}
	return (poi);
}
