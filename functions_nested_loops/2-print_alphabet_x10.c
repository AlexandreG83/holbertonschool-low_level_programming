#include "main.h"

/**
 * print_alphabet_x10 - prints 10 times the alphabet in lowercase
 *
 * Description: This function uses _putchar to print the alphabet
 * from 'a' to 'z', followed by a new line, ten times in total.
 */
void print_alphabet_x10(void)
{
	int ligne;
	int lettre;

	for (ligne = 0; ligne < 10; ligne++)
	{
		for (lettre = 'a'; lettre <= 'z'; lettre++)
		{
			_putchar(lettre);
		}
		_putchar('\n');
	}
}
