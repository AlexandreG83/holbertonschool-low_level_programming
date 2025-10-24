#include <stdio.h>
#include "main.h"

/**
 * print_to_98 - prints all natural numbers from n to 98
 * @n: starting number
 *
 * Description: Numbers must be separated by a comma and space,
 * printed in order, ending with 98 and followed by a newline.
 */
void print_to_98(int n)
{
if (n <= 98)
{
	for (; n <= 98; n++)
	{
		printf("%d", n);
		if (n != 98)
			printf(", ");
	}
}
else
{
	for (; n >= 98; n--)
	{
	printf("%d", n);
	if (n != 98)
	printf(", ");
	}
}
printf("\n");
}
