#include "hash_tables.h"

int free_value_dup(char *value_dup);

/**
 * hash_table_set - adds an element to the hash table
 * @ht: the hash table
 * @key: the key, cannot be an empty string
 * @value: the value to store, duplicated
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node, *current;
	char *value_dup;
	unsigned long int index;

	if (!ht || !key || *key == '\0' || !value)
		return (0);

	value_dup = strdup(value);
	if (value_dup == NULL)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = value_dup;
			return (1);
		}
		current = current->next;
	}

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (free_value_dup(value_dup));

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (free_value_dup(value_dup));
	}
	new_node->value = value_dup;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}

int free_value_dup(char *value_dup)
{
	if (value_dup != NULL)
		free(value_dup);
	return (0);
}
