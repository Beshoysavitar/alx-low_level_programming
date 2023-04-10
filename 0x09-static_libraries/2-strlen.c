#include "main.h"
#include <string.h>
/**
 * _strlen - Entry point
 * Description: function that returns the length of a string
 * @s: char
 * Return: length of string
 */
int _strlen(char *s)
{
	int i = 0;

	for (; *s++;)
		i++;
	return (i);
}
