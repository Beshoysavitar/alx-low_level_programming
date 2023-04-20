#include "function_pointers.h"

/**
 * array_iterator - a function given as a
 * parameter on each element of an array.
 *
 * @array: array to 
 * @size: size of array
 * @action:  is a pointer to the function
 *
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	int *final = array + size - 1;

	if (action && size && array)

		while (array <= final)

			action(*array++);

}
