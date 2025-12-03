#include <stdio.h>
#include <stdlib.h>
#include "hash_tables.h"

int main(void)
{
    hash_table_t *ht;
    char *keys[] = {
      "hetairas",
      "mentioner",
      "heliotropes",
      "neurospora"
    };
    char *values[] = {
      "value1",
      "value2",
      "value3",
      "value4"
    };
    int i;

    /* Creation d'une table de hachage petite pour forcer des collisions */
    ht = hash_table_create(10);
    if (!ht)
    {
        fprintf(stderr, "Error: could not create hash table\n");
        return (1);
    }

    /* Ajout des clefs */
    for (i = 0; i < 4; i++)
    {
        if (!hash_table_set(ht, keys[i], values[i]))
            fprintf(stderr, "Failed to insert key: %s\n", keys[i]);
    }

    /* Affichage de la table pour voir les collisions */
    hash_table_print(ht);

    /* Test recuperation des valeurs */
    for (i = 0; i < 4; i++)
        printf("%s -> %s\n", keys[i], hash_table_get(ht, keys[i]));

    /* Suppression de la table */
    hash_table_delete(ht);

    return (0);
}
