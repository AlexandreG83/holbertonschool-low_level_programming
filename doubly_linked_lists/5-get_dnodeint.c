#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a doubly linked list
 * @head: pointer to the head of the list
 * @index: index of the node (0-based)
 *
 * Return: pointer to the node at index, or NULL if index is out of range
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
unsigned int i = 0;

if (head == NULL)
	return (0);

while (head != NULL)
{
	if (i == index)
		return (head);
	head = head->next;
	i++;
}
return (NULL);
}
