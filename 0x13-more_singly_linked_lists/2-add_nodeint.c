#include "lists.h"

/**
 * add_nodeint - function that adds a new node at the beginning
 * @head: double pointer to the head of the list
 * @n: integer data for the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *nod;

	nod = malloc(sizeof(listint_t));
	if (nod = '\0')
		return (NULL);

	nod->n = n;
	nod->next = *head;
	*head = nod;

	return (nod);
}
