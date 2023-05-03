#include "lists.h"
/**
 * sum_listint - ...
 * @head: ...
 * Return: ...
 */
int sum_listint(listint_t *head)
{
	int i = 0;

	for (; head != NULL; head = head->next)
	{
		i += head->n;
	}
	return (i);
}
