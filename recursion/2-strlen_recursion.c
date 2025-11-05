#include "main.h"

/**
 * _strlen_recursion - returns the length of a string
 * @s: string to measure
 *
 * Return: length of the string
 */
int _strlen_recursion(char *s)
{
int longueur;

if (*s == '\0')
	return (0);
s++;
longueur = _strlen_recursion(s);
longueur++;
return (longueur);
}
