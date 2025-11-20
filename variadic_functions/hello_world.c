#include <stdio.h>

int main()
{
char a[]="Hello, World";
int i;

for (i = 0; a[i] != '\0'; i++)
{
	putchar(a[i]);
}
putchar('\n');
return (0);
}
