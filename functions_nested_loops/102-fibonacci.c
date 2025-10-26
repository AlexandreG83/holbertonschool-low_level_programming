#include <stdio.h>

/**
 * main - prints the first 50 Fibonacci numbers, starting with 1 and 2
 *
 * Return: Always 0
 */
int main(void)
{
long int i, n1 = 1, n2 = 2, next;

for (i = 1; i <= 50; i++)
{
	printf("%ld", n1);
	if (i != 50)
	{
		printf(", ");
	}
	next = n1 + n2;
	n1 = n2;
	n2 = next;
	}
printf("\n");
return (0);
}
