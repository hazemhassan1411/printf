#ifndef _MAIN_H
#define _MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void print_number(int n);
int num_printf(const char *format, ...);
int parser(const char *format, char *buffer, size_t maxlength,va_list args, size_t indx);
int _printf(const char *format, ...);


#endif
