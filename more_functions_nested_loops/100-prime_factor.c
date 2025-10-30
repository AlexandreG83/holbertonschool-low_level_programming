#include <stdio.h>
#include <math.h>

/**
 * main - finds and prints the largest prime factor of 612852475143
 *
 * Return: Always 0
 */
int main(void)
{
long n = 612852475143;
long largest = 0;
long facteur = 2;

while (n > 1)
{
	if (n % facteur == 0)
	{
		largest = facteur;
		n /= facteur;
		while (n % facteur == 0)
			n /= facteur;
	}
	facteur++;
}
printf("%ld\n", largest);
return (0);
}
