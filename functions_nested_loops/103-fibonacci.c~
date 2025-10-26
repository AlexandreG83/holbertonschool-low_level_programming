#include <stdio.h>

/**
 * main - finds and prints the sum of the even-valued terms in the
 * Fibonacci sequence below 4,000,000
 *
 * Return: Always 0.
 */
int main(void)
{
unsigned long a = 1, b = 2, sum = 0, even_sum = 0;

while (b <= 4000000)
{
	if (b % 2 == 0)
		even_sum += b;
	sum = a + b;
	a = b;
	b = sum;
}
printf("%lu\n", even_sum);
return (0);
}
