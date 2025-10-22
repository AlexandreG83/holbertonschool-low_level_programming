#include <stdio.h>

/**
 * main - prints the last digit of a random number and its description
 * Return: Always 0 (Success)
 */
int main(void)
{
char lettre;

/* Your code goes there */
for (lettre = 0; lettre < 16; lettre++)
{
if (lettre < 10)
	putchar(lettre + '0');
else
	putchar('a' + (lettre - 10));
}
putchar('\n');
return (0);
}
