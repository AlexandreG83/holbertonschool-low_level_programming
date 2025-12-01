#include "lists.h"

/**
 * add_dnodeint - adds a new node at the beginning of a doubly linked list
 * @head: pointer to the pointer of the first node
 * @n: integer to store in the new node
 *
 * Return: pointer to the new node, or NULL if memory allocation fails
 */
dlistint_t *add_dnodeint(dlistint_t **head, int n)
{
	dlistint_t *new = malloc(sizeof(dlistint_t));

	if (head == NULL || new == NULL)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	new->next = *head;

	if (*head != NULL)
		(*head)->prev = new;
	*head = new;

	return (new);
}
