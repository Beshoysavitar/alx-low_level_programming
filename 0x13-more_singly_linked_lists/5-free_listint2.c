#include "lists.h"
/**
 * free_listint2 - ...
 * @head: ...
 * Return: void
 */
void free_listint2(listint_t **head)
{
	listint_t *i;

	if (head == NULL)
		return;
	while (*head != NULL)
	{
		i = *head;
		*head = (*head)->next;
		free(i);
	}
	*head = NULL;
}
