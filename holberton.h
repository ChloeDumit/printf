#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 *struct sfun - structure
 *@test: testing
 *@printer: function
 */

typedef struct sfun
{
	char *test;
	int (*printer)();
} sf;

int print_char(va_list list);
int print_string(va_list list);
int print_integer(va_list list);
int print_percent(va_list list);
int _put_char(char c);
int _printf(const char *format, ...);
int _strlen(char *s);
char *convert(unsigned int num, int base);
int helper(const char *format, va_list list, sf types[]);
int rot13(va_list list);

int rot13b(int c, int basis);
#endif
