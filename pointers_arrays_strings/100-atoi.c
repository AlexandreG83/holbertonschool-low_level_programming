#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: the string to convert
 *
 * Return: the integer value of the string, or 0 if none
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	unsigned int num = 0;
	int started = 0;

	/* scan characters */
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			started = 1;
			num = num * 10 + (unsigned int)(s[i] - '0');
		}
		else
		{
			if (started)
				break;
			if (s[i] == '-')
				sign = -sign;
			/* '+' or any other char before digits is ignored except '-' toggles sign */
		}
		i++;
	}

	/* convert unsigned accumulation to signed int result safely */
	if (sign > 0)
		return ((int) num);
else
	return ((int)(0u - num));
}

