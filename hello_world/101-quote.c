#include <stdio.h>
#include <unistd.h>

/**
 * main - prints a quote to stderr
 *
 * Return: 1
 */
int main(void)
{
char message[] = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";
write(STDERR_FILENO, message, 59);
return (1);
}
