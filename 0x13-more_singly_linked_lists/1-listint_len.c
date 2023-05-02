#include "lists.h"
/**
 * listint_len - function that returns the number of elements
 * @h: pointer to the head of the list
 *
 * Return: the number of nodes
 */
size_t listint_len(const listint_t *h)
{
	size_t nod;

	for (nod = 0; h; nod++)
	{
		h = h->next;
	}

	return (nod);
}
