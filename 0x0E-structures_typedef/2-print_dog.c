#include <stdio.h>
#include "dog.h"

/**
 * print_dog - function that prints a struct dog
 * @d: int
 *
 * Return: void
 */

void print_dog(struct dog *d)
{
	/*checks if d not null*/

	if (d != NULL)
	{
		/*cheks if name null*/

		if (d->name != NULL)
			printf("Name: %s\n", d->name);
		else
			printf("Name: (nil)\n");

		printf("Age: %.6f\n", d->age);
		/*cheks owner name null*/

		if (d->owner != NULL)
			printf("Owner: %s\n", d->owner);
		else
			printf("Owner: (nil)\n");
	}
	/*return void*/
}
