#include "function_pointers.h"
/**
 * main - ...
 * @argc: ...
 * @argv: ...
 *
 * Return: ...
 */
int main(int argc, char **argv)
{
	int i;
	char *s = (char *)main;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
	i = atoi(argv[1]);
	if (i < 0)
	{
		printf("Error\n");
		exit(2);
	}
	while (i--)
		printf("%02hhx%s", *s++, i ? " " : "\n");
	return (0);
}

