#include "lists.h"

/**
 * add_nodeint_end - function that adds a new node at the end
 * @head: double pointer to the head of the list
 * @n: integer data for the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *nod, *i;

	nod = malloc(sizeof(listint_t));
	if (nod == NULL)
		return (NULL);

	nod->n = n;
	nod->next = NULL;

	if (*head == NULL)
	{
		*head = nod;
		return (nod);
	}

	i = *head;
	while (i->next != NULL)
		i = i->next;

	i->next = nod;

	return (nod);
}
