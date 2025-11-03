#include "main.h"

/**
 * _strncpy - copies at most n characters from src to dest
 * @dest: destination buffer
 * @src: source string
 * @n: maximum number of characters to copy
 *
 * Return: pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
int j = 0;

while (src[j] != '\0' && j < n)
{
	dest[j] = src[j];
	j++;
}
while (j < n)
{
	dest[j] = '\0';
	j++;
}
return (dest);
}
