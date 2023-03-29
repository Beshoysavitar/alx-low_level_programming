#include "main.h"
/**
 * rev_string - reverses a string
 * _putchar - print each character
 * @s: char to check
 *
 * Description: This will reverse a string
 * Return: 0 is success
 */
void rev_string(char *s)
{
	int i = 0, j, x;
	char t;

	for (; s[i];)
		i++;
	j = i - 1;

	for (x = 0; j >= 0 && x < j; j--, x++)
	{
		t = s[x];
		s[x] = s[j];
		s[j] = t;
	}
}

