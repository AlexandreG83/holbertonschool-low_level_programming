#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int is_digit_string(char *s);

/**
 * is_digit_string - checks if a string contains only digits
 * @s: string to check
 * Return: 1 if only digits, 0 otherwise
 */
int is_digit_string(char *s)
{
int i = 0;

if (s[0] == '\0')
	return 0;
while (s[i] != '\0')
{
	if (!isdigit(s[i]))
		return 0;
	i++;
}
return 1;
}

/**
 * main - adds positive numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
int i, somme = 0;

for (i = 1; i < argc; i++)
{
	if (!is_digit_string(argv[i]))
	{
		printf("Error\n");
		return (1);
	}
	somme = somme + atoi(argv[i]);
}
printf("%d\n", sum);
return (0);
}
