#include "lists.h"

/**
 * pop_listint - ...
 *
 * @head: ...
 *
 * Return: ...
 */
int pop_listint(listint_t **head)
{
	listint_t *nod;
	int n;

	if (*head == NULL)
		return (0);
	nod = *head;
	n = nod->n;
	*head = nod->next;
	free(nod);
	return (n);
}
