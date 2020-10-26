#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include "holberton.h"
/**
 *print_char - prints char
 *@list: list
 *Return: write
 */

int print_char(va_list list)
{
	char c;

	c = va_arg(list, int);
	write(1, &c, 1);
	return (1);
}

/**
 *print_string - prints string
 *@list: list
 *Return: write
 */

int print_string(va_list list)
{
	int n = 0;
	char *str;

	str = va_arg(list, char*);

	if (str == NULL)
	{
		str = "(null)";
	}
	n = _strlen(str);
	write(1, str, n);
	return (n);
}

/**
 *print_percent - prints percent
 *@list: list
 *Return: write
 */

int print_percent(__attribute__((unused)) va_list list)
{
	_put_char('%');
	return (1);
}
/**
 *_strlen - get lenght
 *@s: s
 *Return: lenght
 */

int _strlen(char *s)
{
	int b = 0;

	while (*(s + b) != 0)
	{
		b++;
	}
	return (b);
}

/**
 *print_integer - print integer
 *@list: list
 *Return: count
 */
int print_integer(va_list list)
{
  int i, div, len;
  unsigned int num;

  i = va_arg(valist, int);
  div = 1;
  len = 0;
  if (i < 0)
    {
      len += _putchar('-');
      num = i * -1;
    }
  else
    {
      num = i;
    }

  for (; num / div > 9;)
    {
      div *= 10;
    }

  for (; div != 0;)
    {
      len += _putchar('0' + (num / div));
      num %= div;
      div /= 10;
    }

  return (len);
