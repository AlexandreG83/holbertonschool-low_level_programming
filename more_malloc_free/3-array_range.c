#include <stdlib.h>
#include "main.h"

/**
 * array_range - creates an array of integers from min to max (inclusive)
 * @min: minimum integer value
 * @max: maximum integer value
 *
 * Return: pointer to newly allocated array, or NULL if fail
 */
int *array_range(int min, int max)
{
int *arr;
int i;
int size = max - min + 1;
if (min > max)
	return (NULL);

arr = malloc(size * sizeof(int));
if (arr == NULL)
	return (NULL);

for (i = 0; i < size; i++)
	arr[i] = min + i;

return (arr);
}
