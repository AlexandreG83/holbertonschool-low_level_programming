#include "main.h"

/**
 * times_table - prints the 9 times table, starting with 0
 *
 * Return: Nothing (void)
 */
void times_table(void)
{
int rangee, colonne, produit;

for (rangee = 0; rangee <= 9; rangee++)
{
	for (colonne = 0; colonne <= 9; colonne++)
	{
		produit = rangee * colonne;

		if (colonne == 0)
		{
			_putchar(produit + '0');
		}
		else
		{
			_putchar(',');
			_putchar(' ');

			if (produit < 10)
			{
				_putchar(' ');
				_putchar(produit + '0');
			}
			else
			{
				_putchar((produit / 10) + '0');
				_putchar((produit % 10) + '0');
			}
		}
	}
_putchar('\n');
}
}

