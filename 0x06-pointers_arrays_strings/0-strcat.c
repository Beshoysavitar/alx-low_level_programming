#include "main.h"
/**
 * _strcat - Entry point
 * Description: function that concatenates two strings.
 * @dest: string 1
 * @src: string 2
 * Return: Always (0)
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
	{
		printf("%c", dest[i]);
		i++;
	}

	while (src[j] != '\0')
	{
		printf("%c", src[j]);
		j++;
	}
	printf("\n");
	return (0);
}
