#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include "holberton.h"
/**
 *rot13 - prints rot13
 *@list: list
 *Return: write
 */

int rot13(va_list list)
{
	int i, j;
	char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *str;
	str = va_arg(list, char*);

	if(str == NULL)
		return (-1);

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; j <= 52; j++)
		{
			if (str[i] == alpha[j])
			{
				_put_char(rot[j]);
				break;
			}
		}
		if(j == 53)
		{
			_put_char(str[i]);
		}
	}
	return (i);
}
