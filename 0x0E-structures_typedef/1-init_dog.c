#include "dog.h"

/**
 * init_dog - initializes a structure of type dog
 *
 * @d: int
 * @name: dog's name
 * @age: dog's age
 * @owner: name owner of the dog
 *
 * Return: void
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}

