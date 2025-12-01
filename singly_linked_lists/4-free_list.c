#include "lists.h"

/**
 * free_list - frees a singly linked list
 * @head: pointer to the first node of the list
 */
void free_list(list_t *head)
{
	list_t *tmp;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		tmp = head->next;
		free(head->str);
		free(head);
		head = tmp;
	}
}
