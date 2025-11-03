#include "main.h"

/**
 * _strstr - locates a substring
 * @haystack: pointer to the string to search in
 * @needle: pointer to the substring to find
 *
 * Return: pointer to the beginning of the located substring,
 *         or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
unsigned int i, j;

if (needle[0] == '\0')
{
	return (haystack);
}

i = 0;
while (haystack[i] != '\0')
{
	j = 0;
	while (needle[j] != '\0' && haystack[i + j] != '\0')
	{
		if (haystack[i + j] != needle[j])
		{
			break;
		}
		j++;
	}
	if (needle[j] == '\0')
	{
		return (haystack + i);
	}
	i++;
}
return (0);
}
