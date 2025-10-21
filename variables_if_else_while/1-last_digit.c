#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* more headers goes there */

/* betty style doc for function main goes there */
/**
 * main - prints the last digit of a random number
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;
	int dernier_chiffre;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	dernier_chiffre = n % 10;

	/* your code goes there */
	printf("Last digit of %d is %d\n", n, dernier_chiffre);

if (dernier_chiffre > 5)
	printf("and is greater than 5\n");
else if (dernier_chiffre == 0)
	printf("and is 0\n");
else
	printf("and is less than 6 and not 0\n");
return (0);
}
