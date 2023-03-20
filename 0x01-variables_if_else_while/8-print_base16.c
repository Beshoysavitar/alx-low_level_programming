#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - Entry point
 *
 * Description: A C while function
 *
 * Return: Always 0 (Success)
*/
int main(void)
{
	char abc = 'a';
	int i;

	for (i = 0; i < 10; i++)
	{
		putchar(i + '0');
	}
	while (abc <= 'f')
	{
		putchar(abc);
		abc++;
	}
	putchar('\n');
	return (0);
}
