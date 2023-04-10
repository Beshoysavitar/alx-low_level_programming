#include <stdio.h>
#include <stdlib.h>

/**
 * main - adds positive numbers.
 * @argc: argument count
 * @argv: arguments
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	int sum = 0;
	char *a;

	if (argc < 2)
	{
		printf("0\n");
		return (0);
	}
	while (--argc)
	{
		for (a = argv[argc]; *a; a++)
		{
			if (*a < '0' || *a > '9')
			{
				printf("Error\n");
				return (1);
			}
			sum += atoi(argv[argc]);
		}
	}
	printf("%d\n", sum);
	return (0);
}
