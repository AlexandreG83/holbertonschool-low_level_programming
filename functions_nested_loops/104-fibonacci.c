#include <stdio.h>

/**
 * main - prints the first 98 Fibonacci numbers, starting with 1 and 2
 *
 * Return: Always 0.
 */
int main(void)
{
int count;
unsigned long a = 1, b = 2, a_half1, a_half2, b_half1, b_half2;
unsigned long half1, half2;
unsigned long limit = 1000000000; /* 1 billion to split numbers */

printf("%lu, %lu", a, b);

for (count = 3; count <= 98; count++)
{
	if (a + b < limit)
	{
		unsigned long next = a + b;

		printf(", %lu", next);
		a = b;
		b = next;
	}
	else
	{
		if (count == 3)
		{
			a_half1 = a / limit;
			a_half2 = a % limit;
			b_half1 = b / limit;
			b_half2 = b % limit;
		}

		half1 = a_half1 + b_half1;
		half2 = a_half2 + b_half2;

		if (half2 >= limit)
		{
			half1 += 1;
			half2 -= limit;
		}

		printf(", %lu%09lu", half1, half2);

		a_half1 = b_half1;
		a_half2 = b_half2;
		b_half1 = half1;
		b_half2 = half2;
	}
}
printf("\n");
return (0);
}
