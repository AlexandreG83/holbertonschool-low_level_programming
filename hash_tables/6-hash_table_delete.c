#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table
 * @ht: pointer to the hash table to delete
 *
 * Description: Frees all memory used by the hash table, including
 * all nodes and their keys and values.
 */
void hash_table_delete(hash_table_t *ht)
{
unsigned long int i;
hash_node_t *node, *tmp;

if (ht == NULL)
	return;

for (i = 0; i < ht->size; i++)
{
	node = ht->array[i];
	while (node != NULL)
	{
		tmp = node->next;
		free(node->key);
		free(node->value);
		free(node);
		node = tmp;
	}
}

free(ht->array);
free(ht);
}
