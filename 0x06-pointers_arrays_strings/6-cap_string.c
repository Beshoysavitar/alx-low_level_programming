#include "main.h"

/**
 * cap_string -  function that capitalizes all words of a string.
 * @s: string that capitalize
 * Return: s
 */
char *cap_string(char *s)
{
	int i, q;
	char sep[] = " \t\n,;.!?\"(){}";

	for (i = 0; s[i] != '\0'; i++)
	{
		if (i == 0)
		{
			if ((s[i] >= 'a' && s[i] <= 'z'))
				s[i] -= 32;
			continue;
		}
		for (q = 0; q <= 13; q++)
		{
			if (s[i] == sep[q])
			{
				i++;

				if ((s[i] >= 'a' && s[i] <= 'z'))
				{
					s[i] -= 32;
					continue;
				}
			}
		}
	}
	return (s);
}
