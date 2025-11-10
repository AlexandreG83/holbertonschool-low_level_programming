#include <stdlib.h>
#include "main.h"

/**
 * str_concat - concatenates two strings into a newly allocated memory
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to the new string, or NULL if allocation fails
 * If NULL is passed for s1 or s2, treat it as an empty string
 */
char *str_concat(char *s1, char *s2)
{
char *concat;
int len1 = 0, len2 = 0, i, j;

if (s1 == NULL)
	s1 = "";
if (s2 == NULL)
	s2 = "";

while (s1[len1])
	len1++;
while (s2[len2])
	len2++;

concat = malloc(sizeof(char) * (len1 + len2 + 1));
if (concat == NULL)
	return (NULL);

for (i = 0; i < len1; i++)
	concat[i] = s1[i];

for (j = 0; j < len2; j++)
	concat[j] = s2[j];

concat[i + j] = '\0';
return (concat);
}
