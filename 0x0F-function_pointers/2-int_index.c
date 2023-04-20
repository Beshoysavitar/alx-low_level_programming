#include "function_pointers.h"

/**
  * int_index - a function that searches for an integer.
  * @array: array
  * @size: size
  * @cmp: comtare
  */
int int_index(int *array, int size, int (*cmp)(int))
{
	int x;

	if (array && size && cmp)
	{
		x = 0;
		while (x < size)
		{
			if (cmp(array[i]))
			{
				return (i)
			}
			x++;
		}
	}
	return (-1);
}
