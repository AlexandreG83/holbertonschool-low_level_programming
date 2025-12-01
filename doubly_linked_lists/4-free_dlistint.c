#include "lists.h"

/**
 * free_dlistint - frees a doubly linked list
 * @head: pointer to the head of the list
 */
void free_dlistint(dlistint_t *head)
{
dlistint_t *tmp;

if (head == NULL)
	return;

while (head != NULL)
{
	tmp = head->next;
	free(head);
	head = tmp;
}
}
