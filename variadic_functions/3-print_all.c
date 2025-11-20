#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - Prints anything, depending on the format
 * @format: A list of types of arguments passed to the function
 */
void print_all(const char * const format, ...)
{
int i = 0, printed;
char *str;
va_list args;
va_start(args, format);

while (format && format[i])
{
	printed = 1;
	switch (format[i])
	{
		case 'c':
			printf("%c", va_arg(args, int));
			break;
		case 'i':
			printf("%d", va_arg(args, int));
			break;
		case 'f':
			printf("%f", va_arg(args, double));
			break;
		case 's':
			str = va_arg(args, char *);
			if (str == NULL)
			{
				printf("(nil)");
				break;
			}
			printf("%s", str);
			break;
		default:
			printed = 0;
			break;
	}

	if (format[i + 1] && printed)
		printf(", ");
	i++;
	}
printf("\n");
va_end(args);
}
