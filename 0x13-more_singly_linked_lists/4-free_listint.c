#include "lists.h"

/**
 * free_listint - free
 * @head: pointer to the head of the list
 */
void free_listint(listint_t *head)
{
	listint_t *i;

	while (head != NULL)
	{
		i = head;
		head = head->next;
		free(i);
	}
}
