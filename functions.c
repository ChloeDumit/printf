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
 * */
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
 *
 */
int print_integer(va_list list)
{
	int n = va_arg(list, int);
	if (n < 0)
	{
		_put_char('-');
		n = -n;
	}
	else if (n == 0)
	{
		_put_char('0');
		return(0);
	}
	while (n != 0)
	{
		_put_char ('0' + (n%10));
		n /= 10;
	}
	return(n);
}
/**
 *convert - convert
 *@num: num
 *@base: base
 *Return: number 
 */
char *convert(unsigned int num, int base) 
{ 
	static char Representation[]= "0123456789ABCDEF";
	static char buffer[50]; 
	char *ptr; 
	
	ptr = &buffer[49]; 
	*ptr = '\0'; 
	
	do 
	{ 
		*--ptr = Representation[num%base]; 
		num /= base; 
	}while(num != 0); 
	
	return(ptr);
}
