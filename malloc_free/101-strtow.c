#include <stdlib.h>
#include "main.h"

/**
 * word_count - counts the number of words in a string
 * @str: the string to analyze
 *
 * Return: number of words
 */
int word_count(char *str)
{
int count = 0, i = 0;

while (str[i])
{
	while (str[i] == ' ')
		i++;
	if (str[i] != '\0')
	{
		count++;
		while (str[i] != ' ' && str[i] != '\0')
			i++;
	}
}
return (count);
}

/**
 * word_len - returns length of next word
 * @str: string
 *
 * Return: length
 */
int word_len(char *str)
{
int len = 0;

while (str[len] && str[len] != ' ')
	len++;
return (len);
}

 /**
 * strtow - splits string into words
 * @str: input string
 *
 * Return: pointer to an array of strings
 */
char **strtow(char *str)
{
char **words;
int i = 0, j = 0, k = 0, n = 0, len = 0, wc;

if (str == NULL || *str == '\0')
	return (NULL);

wc = word_count(str);
if (wc == 0)
	return (NULL);

words = malloc(sizeof(char *) * (wc + 1));
if (words == NULL)
	return (NULL);

while (*str)
{
	while (*str == ' ')
		str++;
	if (*str)
	{
		len = word_len(str);
		words[k] = malloc(len + 1);
		if (!words[k])
		{
			while (k > 0)
			{
				free(words[k]);
				k--;
			}
			free(words);
			return (NULL);
		}
		for (n = 0; n < len; n++)
			words[k][n] = str[i + n];
		words[k][len] = '\0';
		k++;
		i = j;
	}
}
words[k] = NULL;
return (words);
}
