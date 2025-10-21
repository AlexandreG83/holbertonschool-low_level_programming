#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - prints the last digit of a random number and its description
 * Return: Always 0 (Success)
 */
int main(void)
{
char lettre;

/* Your code goes there */
for (lettre = 0; lettre < 10; lettre++)
	{
	putchar(lettre + '0');
	}
putchar('\n');
return (0);
}
