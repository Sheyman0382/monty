#include "monty.h"

/**
 * string_integer - checks the validity of a string integer
 * @str_int: the string intger to be checked for validity
 *
 * Return: return 1 on sucess and 0 if not string integer
 */

int string_integer(char *str_int)
{
	int count = 0;

	if (str_int[0] == '+' || str_int[0] == '-')
		count++;
	if (str_int[count] == '\0')
		return (0);
	while (str_int[count] != '\0')
	{
		if (str_int[count] >= '0' && str_int[count] <= '9')
			count++;
		else
			return (0);
	}
	return (1);
}
