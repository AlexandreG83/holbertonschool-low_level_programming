#include <stdlib.h>
#include "main.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * containing a copy of the string given as a parameter
 * @str: the string to duplicate
 *
 * Return: pointer to duplicated string, or NULL if str is NULL or memory fails
 */
char *_strdup(char *str)
{
char *copy;
int i, length = 0;

if (str == NULL)
	return (NULL);

while (str[length])
	length++;

copy = malloc((length + 1) * sizeof(char));
if (copy == NULL)
	return (NULL);

for (i = 0; i < length; i++)
	copy[i] = str[i];

copy[length] = '\0';
return (copy);
}
