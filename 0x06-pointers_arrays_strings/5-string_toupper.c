#include "main.h"

/**
 * string_toupper - function that changes lowercase letters to uppercase.
 *
 * @t: The string that will be changed for lowercase letters
 * Return: t
 */
char *string_toupper(char *t)
{
	int x;

	for (x = 0; t[x] != '\0'; x++)
	{
		if (t[x] >= 'a' && t[x] <= 'z')
			t[x] -= 32;
	}
	return (t);
}
