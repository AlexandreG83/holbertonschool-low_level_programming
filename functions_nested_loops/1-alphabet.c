#include "main.h"

/**
 * print_alphabet - prints the alphabet in lowercase
 *
 * Description: Uses _putchar to print each letter from 'a' to 'z',
 * followed by a newline.
 */
void print_alphabet(void)
{
int lettre;

/* your code goes there */
for (lettre = 'a'; lettre <= 'z' ; lettre++)
	{
	_putchar(lettre);
	}
_putchar('\n');
}
