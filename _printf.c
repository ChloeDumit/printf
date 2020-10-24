#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "holberton.h"
/**
 *
 */
int _printf(const char *format, ...)
{
	sf types [] = {
		{"%c", print_char},
		{"%s", print_string},
		{"%%", print_percent},
		{NULL, NULL}
	};

	va_list list;
	int i = 0;
	int j;

	va_start(list, format);

	while (format && format[i])
	{
		j = 0;
		while (types[j].test != NULL)
		{
			if (format[i] == types[j].test[0])
			{
				types[j].printer(list);
			}
			j++;
		}
		i++;
	}
	va_end(list);
	return(0);
}
