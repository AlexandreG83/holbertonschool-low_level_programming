#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - returns the length of a string
 * @s: string to measure
 * Return: length of string
 */
int _strlen(char *s)
{
int len = 0;

while (s && s[len])
	len++;
return (len);
}

/**
 * _strcpy - copies a string to another buffer
 * @dest: destination buffer
 * @src: source string
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
int i;

for (i = 0; src[i]; i++)
	dest[i] = src[i];
dest[i] = '\0';
return (dest);
}

/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: pointer to the new dog (dog_t), or NULL if it fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
dog_t *d;
int len_name, len_owner;

if (!name || !owner)
	return (NULL);

d = malloc(sizeof(dog_t));
if (!d)
	return (NULL);

len_name = _strlen(name);
len_owner = _strlen(owner);

d->name = malloc(len_name + 1);
if (!d->name)
{
	free(d);
	return (NULL);
}

d->owner = malloc(len_owner + 1);
if (!d->owner)
{
	free(d->name);
	free(d);
	return (NULL);
}

_strcpy(d->name, name);
_strcpy(d->owner, owner);
d->age = age;

return (d);
}
