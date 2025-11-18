#include "function_pointers.h"
#include <stddef.h>

/**
 * int_index - searches for an integer using a comparison function
 * @array: the array to search in
 * @size: the number of elements in the array
 * @cmp: pointer to the comparison function
 *
 * Return: index of first element for which cmp does not return 0,
 *         or -1 if no match or invalid input.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
int i;
if (array == NULL || cmp == NULL || size <= 0)
	return (-1);

for (i = 0; i < size; i++)
{
	if (cmp(array[i]) != 0)
		return (i);
}
return (i);
}
