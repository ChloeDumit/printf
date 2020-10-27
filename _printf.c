#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "holberton.h"
/**
 *helper - helper
 *@format: format
 *@list: list
 *@types: types
 *Return: print
 */
int helper(const char *format, va_list list, sf types[])
{
	int i = 0;
	int j = 0;
	int flag = 0;
	int count = 0;

	while (format[i] != '\0' && format)
	{
		flag = 0;
		if (format[i] == '%')
		{
			while (types[j].test != NULL)
			{
				if (format[i + 1] == types[j].test[0])
				{
					flag = 1;
					count += types[j].printer(list);
					break;
				}
				j++;
			}
		}

		if (flag == 1)

		{
			if (format[i + 1] == '\0' || format[i + 2] == '\0')
				return (count);
			i += 2;
		}
		else
		{
			write(1, &format[i], 1);
			i++;
			count++;
		}
		j = 0;
	}
	va_end(list);
	return (count);
}

/**
 *_printf - prints format
 *@format: format
 *Return: print
 */
int _printf(const char *format, ...)
{
		sf types[] = {
			{"c", print_char},
			{"s", print_string},
			{"%", print_percent},
			{"i", print_integer},
			{"d", print_integer},
			{NULL, NULL}
		};
	int total = 0;
	va_list list;

	va_start(list, format);
	if (!format)
	{
		return (-1);
	}
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
	{
		return (-1);
	}
	total = helper(format, list, types);
	va_end(list);
	return (total);
}
