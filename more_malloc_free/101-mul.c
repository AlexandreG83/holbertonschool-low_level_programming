#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * is_number - checks if a string contains only digits
 * @s: input string
 * Return: 1 if all digits, 0 otherwise
 */
int is_number(char *s)
{
int i;
for (i = 0; s[i]; i++)
{
	if (!isdigit(s[i]))
		return (0);
}
if (!s || !*s)
	return (0);
else
	return (1);
}

/**
 * multiply - multiplies two positive numbers as strings
 * @num1: first number string
 * @num2: second number string
 */
void multiply(char *num1, char *num2)
{
int len1 = strlen(num1);
int len2 = strlen(num2);
int len = len1 + len2;
int *resultat, i_num1, i_num2, i, j, stock, n1, n2, somme;

resultat = calloc(len, sizeof(int));
if (!resultat)
	exit(98);

for (i = len1 - 1, i_num1 = 0; i >= 0; i--, i_num1++)
{
	n1 = num1[i] - '0';
	stock = 0;
	for (j = len2 - 1, i_num2 = 0; j >= 0; j--, i_num2++)
	{
		n2 = num2[j] - '0';
		somme = n1 * n2 + resultat[i_num1 + i_num2] + stock;
		stock = somme / 10;
		resultat[i_num1 + i_num2] = somme % 10;
	}
if (stock > 0)
	resultat[i_num1 + i_num2] += stock;
}

i = len - 1;
while (i >= 0 && resultat[i] == 0)
	i--;
if (i == -1)
	putchar('0');
else
{
	for (; i >= 0; i--)
	{
		putchar(resultat[i] + '0');
	}
}
putchar('\n');
free(resultat);
}

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument values
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
if (argc != 3 || !is_number(argv[1]) || !is_number(argv[2]))
{
	printf("Error\n");
	return (98);
}
multiply(argv[1], argv[2]);
return (0);
}
