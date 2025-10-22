#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - prints the last digit of a random number
 * Return: Always 0 (Success)
 */
int main(void)
{
char lettre = 'a';

/* your code goes there */
for (lettre = 'z'; lettre >= 'a' ; lettre--)
	{
	putchar(lettre);
	}
putchar('\n');
return (0);
}
