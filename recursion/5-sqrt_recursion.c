#include "main.h"

/**
 * find_sqrt - finds square root by testing values recursively
 * @n: the number to find square root of
 * @i: current value to test
 *
 * Return: the square root if found, -1 otherwise
 */
int find_sqrt(int n, int i)
{
if (i * i == n)
	return (i);
if (i * i > n)
	return (-1);
return (find_sqrt(n, i + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: the number to find square root of
 *
 * Return: natural square root of n, or -1 if no natural square root exists
 */
int _sqrt_recursion(int n)
{
if (n < 0)
	return (-1);
return (find_sqrt(n, 0));
}
