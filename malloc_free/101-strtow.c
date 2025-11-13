#include <stdlib.h>
#include "main.h"

/**
 * strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (words) or NULL
 */
char **strtow(char *str)
{
char **words;
int i = 0, j = 0, k = 0, len = 0, wc;
 
if (str == NULL || *str == '\0')
	return (NULL);

wc = word_count(str);
if (wc == 0)
	return (NULL);

words = malloc(sizeof(char *) * (wc + 1));
if (words == NULL)
	return (NULL);



return (words);
}
