#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int _putc(char c);
int _printc(va_list args);
int _prints(va_list args);
void _printi(va_list args);
int (*_select(char c))(va_list);
int _printf(const char *format, ...);

#endif
