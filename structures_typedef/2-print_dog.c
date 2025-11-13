#include "dog.h"
#include <stdio.h>

/**
 * print_dog - prints a struct dog
 * @d: pointer to struct dog
 *
 * Description: Prints the content of a struct dog.
 * If an element is NULL, prints (nil) instead.
 * If d is NULL, prints nothing.
 */
void print_dog(struct dog *d)
{
if (d == NULL)
	return;

if (d->name == NULL)
	d->name = "(nil)";
if (d->owner == NULL)
	d->owner = "(nil)";

printf("Name: %s\n", d->name);
printf("Age: %f\n", d->age);
printf("Owner: %s\n", d->owner);
}
