#include "main.h"

/**
 * print_number - prints an integer using only _putchar
 * @n: integer to print
 */
void print_number(int n)
{
unsigned int nombre;

if (n < 0)
{
	_putchar('-');
	nombre = -n;
}
else
{
	nombre = n;
}
if (nombre / 10)
	print_number(nombre / 10);
_putchar((nombre % 10) + '0');
}
