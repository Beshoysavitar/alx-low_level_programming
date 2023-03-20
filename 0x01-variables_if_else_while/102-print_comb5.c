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
	int x1, x2;

	for (x1 = 0; x1 < 100; x1++)
	{
		for (x2 = 0 ; x2 < 100; x2++)
		{
			if (x1 < x2)
			{

				putchar(x1 / 10 + '0');
				putchar(x1 % 10 + '0');
				putchar(' ');
				putchar(x2 / 10 + '0');
				putchar(x2 % 10 + '0');

				if (x1 == 98 && x2 == 99)
					continue;
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');
	return (0);
}
