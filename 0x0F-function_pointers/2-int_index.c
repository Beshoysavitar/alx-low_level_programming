#include "function_pointers.h"

/**
  * int_index - Entry point
  * Descripion: a function that searches for an integer.
  * @array: array
  * @size: size
  * @cmp: comtare
  *
  * Return: -1
  */
int int_index(int *array, int size, int (*cmp)(int))
{
	int x = 0;

	if (array && size && cmp)
	{
		while (x < size)
		{
			if (cmp(array[x]))
			{
				return (x);
			}
			x++;
		}
	}
	return (-1);
}
