#include <stdio.h>

/**
 * first - prints a sentence before main
 *
 * Description: This function is executed before main
 *              thanks to the constructor attribute.
 */
void __attribute__((constructor)) first(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
