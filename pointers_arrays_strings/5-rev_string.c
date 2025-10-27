#include "main.h"

/**
 * rev_string - reverses a string
 * @s: pointer to the string to reverse
 *
 * Return: void
 */
void rev_string(char *s)
{
int i = 0, j = 0;
char stock;

while (s[j] != '\0')
{
	j++;
}
j--;
while (i < j)
{
	stock = s[i];
	s[i] = s[j];
	s[j] = stock;

	i++;
	j--;
}
}
