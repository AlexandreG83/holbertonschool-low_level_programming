#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - prints the last digit of a random number and its description
 * Return: Always 0 (Success)
 */
int main(void)
{
char lettre = 'a';

/* your code goes there */
for (lettre = 'a'; lettre <= 'z' ; lettre++)
	{
	putchar(lettre);
	}
for (lettre = 'A'; lettre <= 'Z' ; lettre++)
	{
	putchar(lettre);
	}
putchar('\n');
return (0);
}
