#include "main.h"

/**
 * print_to_98 - prints all natural numbers from n to 98
 * @n: starting number
 *
 * Return: Nothing (void)
 */
void print_to_98(int n)
{
if (n <= 98)
{
	while (n < 98)
	{
		print_to_98("%d, ", n);
		n++;
	}
	print_to_98("98\n");
}
else
{
	while (n > 98)
	{
		print_to_98("%d, ", n);
		n--;
	}
}
}
