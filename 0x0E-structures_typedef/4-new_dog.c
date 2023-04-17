#include <stdlib.h>
#include "dog.h"
/**
 * new_dog - creates a new dog
 * @name: name of dog
 * @age: age of dog
 * @owner: owner of dog
 * Return: pointer to new dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	unsigned int i, n, o;
	dog_t *new_dog;

	/*checks if name and owner null*/
	if (name == NULL || owner == NULL)
		return (NULL);
	new_dog = malloc(sizeof(dog_t));
	/*check null*/
	if (new_dog == NULL)
		return (NULL);
	/*get last degit*/
	for (n = 0; name[n]; n++)
		;
	n++;
	/*allocate size*/
	new_dog->name = malloc(n * sizeof(char));
	/*check null*/
	if (new_dog->name == NULL)
	{
		free(new_dog);
		return (NULL);
	}
	for (i = 0; i < n; i++)
		new_dog->name[i] = name[i];
	new_dog->age = age;
	for (o = 0; owner[o]; o++)
		;
	o++;
	/*allocate size*/
	new_dog->owner = malloc(o * sizeof(char));
	/*check null*/
	if (new_dog->owner == NULL)
	{
		free(new_dog->name);
		free(new_dog);
		return (NULL);
	}
	for (i = 0; i < o; i++)
		new_dog->owner[i] = owner[i];
	return (new_dog);
}
