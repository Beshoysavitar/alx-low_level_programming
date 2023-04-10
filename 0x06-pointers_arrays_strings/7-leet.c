#include "main.h"

/**
 * leet - encodes a string into 1337
 * @s: string to encode
 *
 * Return: address of s
 */
char *leet(char *s)
{
	int i, j;
	char letter[] = "aAeEoOtTlL";
	char leet[] = "4433007711";

	for (i = 0; *(s + i); i++)
	{
		for (j = 0; j <= 9; j++)
		{
			if (letter[j] == s[i])
				s[i] = leet[j];
		}
	}
	return (s);
}
