#include "3-calc.h"

/**
  * main - ...
  * @argc: ...
  * @argv: ...
  *
  * Return: ...
  */
int main(int argc, char *argv[])
{
	int (*op)(int,int), a, b;

	if (argc != 4)
		printf("Error\n"), exit(98);

	a = atoi(argv[1]);
	b = atoi(argv[3]);

	op = get_op_func(argv[2]);

	if (!op)
		printf("Error\n"), exit(99);

	if (!b && (argv[2][0] == '/' || argv[2][0] == '%'))
		printf("Error\n"), exit(100);
	printf("%d\n", op(a, b));
	return (0);
}
