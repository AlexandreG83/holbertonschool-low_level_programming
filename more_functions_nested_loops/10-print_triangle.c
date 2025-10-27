#include "main.h"

/**
 * print_triangle - prints a triangle using the character #
 * @size: size of the triangle
 *
 * Return: void
 */
void print_triangle(int size)
{
int espace, block;
int i = 1;

if (size <= 0)
	_putchar('\n');

while (i <= size)
{
	espace = 0;
	block = 0;
	while (espace < size - i)
	{
		_putchar(' ');
		espace++;
	}
	while (block < i)
	{
		_putchar('#');
		block++;
	}
	_putchar('\n');
	i++;
}
}
