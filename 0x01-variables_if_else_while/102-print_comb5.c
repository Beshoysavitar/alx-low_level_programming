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
	int x1, x2, x3, x4;

	for (x1 = 0; x1 < 10; x1++)
	{
		for (x2 = 0 ; x2 < 9; x2++)
		{
			for (x3 = 0 ; x3 < 10; x3++)
			{
				for (x4 = 1 ; x4 < 10; x4++)
				{
					putchar(x1 % 10 + '0');
					putchar(x2 % 10 + '0');
					putchar(x3 % 10 + '0');
					putchar(x4 % 10 + '0');

					if (x1 == 9 && x2 == 8 && x3 == 9 && x4 == 9)
						continue;
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
