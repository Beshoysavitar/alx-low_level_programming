#include "main.h"

/**
 * string_nconcat - function that concatenates two strings.
 *
 * @s1: char
 *
 * @s2: char
 *
 * @n: unsigned int
 *
 * Return: fail return NULL
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i, q, s1L, s2L;
	char *string;

	/*Check if the s1 passed null and copmute length*/
	if (s1 == NULL)
		s1 = "";
	for (s1L = 0; s1[s1L] != '\0'; s1L++)
		;
	/*Check if the s2 passed null and copmute length*/
	if (s2 == NULL)
		s2 = "";
	for (s2L = 0; s2[s2L] != '\0'; s2L++)
		;
	/*Memory allocate*/
	string = malloc((s1L + n + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	for (i = 0; s1[i] != '\0'; i++)
	{
		string[i] = s1[i];
	}
	for (q = 0; q < n; q++)
	{
		string[i] = s2[q];
			i++;
	}
	string[i] = '\0';
	return (string);
}
