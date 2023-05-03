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
	int i;

	if (*head == NULL)
		return (0);
	nod = *head;
	i = nod->i;
	*head = nod->next;
	free(nod);
	return (i);
}
