#include "main.h"
#include <stdio.h>

/**
 * print_square - prints a square using the character #
 * @size: size of the square
 *
 * Return: void
 */
void print_square(int size)
{
int largeur, hauteur;
if (size <= 0)
	_putchar('\n');
else
{
	for (hauteur = 0; hauteur < size; hauteur++)
	{
		for (largeur = 0; largeur < size; largeur++)
		{
			_putchar('#');
		}
		_putchar('\n');
	}
}
}
