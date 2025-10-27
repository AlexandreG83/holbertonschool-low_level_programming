#include "main.h"

/**
 * more_numbers - prints 10 times the numbers from 0 to 14
 *
 * Return: void
 */
void more_numbers(void)
{
int ligne, suite;

for (ligne = 0; ligne <= 9; ligne++)
{
	for (suite = 0; suite <= 14; suite++)
	{
		if (suite >= 10)
			_putchar('1');
		_putchar(suite % 10 + '0');
	}
	_putchar('\n');
}
}
