#include "lists.h"
#include <string.h>

/**
 * add_node - adds a new node at the beginning of a linked list
 * @head: pointer to the pointer of the first node
 * @str: string to duplicate and store in the new node
 *
 * Return: pointer to the new node, or NULL if memory allocation fails
 */
list_t *add_node(list_t **head, const char *str)
{
list_t *new_node, *tmp;

if (!head || !str)
	return (NULL);

new_node = malloc(sizeof(list_t));
if (!new_node)
	return (NULL);

new_node->str = strdup(str);
if (!new_node->str)
{
	free(new_node);
	return (NULL);
}

new_node->len = strlen(str);
new_node->next = NULL;

if (*head == NULL)
{
	*head = new_node;
	return (new_node);
}

tmp = *head;
while (tmp->next != NULL)
	tmp = tmp->next;

tmp->next = new_node;
return (new_node);
}
