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
	char abc = 'z';

	while (abc >= 'a')
	{
		putchar(abc);
		abc--;
	}
	putchar('\n');
	return (0);
}
