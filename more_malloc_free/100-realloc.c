#include <stdlib.h>
#include "main.h"

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the previous memory block
 * @old_size: size of the allocated space for ptr
 * @new_size: new size of the new memory block
 *
 * Return: pointer to the new memory block, or NULL on failure
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
unsigned int i;
char *new_ptr, *old_ptr;

if (new_size == old_size)
	return (ptr);

if (new_size == 0 && ptr)
{
	free(ptr);
	return (NULL);
}

if (ptr == NULL)
	return (malloc(new_size));

new_ptr = malloc(new_size);
if (new_ptr == NULL)
	return (NULL);

old_ptr = ptr;

for (i = 0; i < old_size && i < new_size; i++)
	new_ptr[i] = old_ptr[i];

free(ptr);

return (new_ptr);
}
