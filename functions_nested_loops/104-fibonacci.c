#include <stdio.h>

/**
 * main - prints the first 98 Fibonacci numbers, starting with 1 and 2
 * Return: Always 0.
 */
int main(void)
{
int count;
unsigned long a = 1, b = 2, next;
unsigned long a1, a2, b1, b2, half1, half2;
unsigned long limit = 1000000000;

printf("%lu, %lu", a, b);

for (count = 3; count <= 98; count++)
{
	if (b < 1000000000000000000)
	{
		next = a + b;
		printf(", %lu", next);
		a = b;
		b = next;
	}
	else
	{
		a1 = a / limit;
		a2 = a % limit;
		b1 = b / limit;
		b2 = b % limit;

		for (; count <= 98; count++)
		{
			half1 = a1 + b1;
			half2 = a2 + b2;
			if (half2 >= limit)
			{
				half1 += 1;
				half2 -= limit;
			}
			printf(", %lu%09lu", half1, half2);
			a1 = b1;
			a2 = b2;
			b1 = half1;
			b2 = half2;
		}
	}
}
printf("\n");
return (0);
}
