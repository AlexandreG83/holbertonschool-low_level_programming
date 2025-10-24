#include <stdio.h>
#include <unistd.h>

/**
 * main - prints a quote to stderr
 *
 * Return: 1
 */
int main(void)
{
char part1[] = "and that piece of art is useful\"";
char part2[] = " - Dora Korpar, 2015-10-19\n";
write(STDERR_FILENO, part1, sizeof(part1) - 1);
write(STDERR_FILENO, part2, sizeof(part2) - 1);
return (1);
}
