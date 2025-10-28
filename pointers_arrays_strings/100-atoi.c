#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: the string to convert
 *
 * Return: the integer value of the string, or 0 if none
 */
int _atoi(char *s)
{
int i = 0;
int signe = 1;
unsigned int num = 0;

/* Parcourir tous les caracteres avant le nombre */
while (s[i] != '\0')
	{
	/* les signes */
	if (s[i] == '-')
		signe *= -1;
	else if (s[i] >= '0' && s[i] <= '9')
	{
		/* Extraire le nombre */
		while (s[i] >= '0' && s[i] <= '9')
		{
			num = (num * 10) + (s[i] - '0');
			i++;
		}
	}
	i++;
}
return (num * signe);
}
