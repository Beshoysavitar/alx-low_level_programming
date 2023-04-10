#include "main.h"
/**
 * _strcat - Entry point
 * Description: function that concatenates two strings.
 * @dest: string 1
 * @src: string 2
 * Return: Always (dest)
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;
	char *s = dest;

	while (dest[i] != '\0')
	{
		s[j] = dest[i];
		i++;
		j++;
	}
	i = 0;

	while (src[i] != '\0')
	{
		s[j] = src[i];
		i++;
		j++;
	}
	s[j] = '\0';

	return (dest);
}
