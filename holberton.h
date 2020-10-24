#ifndef HOLBERTON_H
#define HOLBERTON_H

typedef struct sfun
{
	char *test;
	void (*printer)();
} sf;

void print_char(va_list list);
void print_string(va_list list);
void print_percent(va_list list);
int _put_char(char c);
int _printf(const char *format, ...);
#endif
