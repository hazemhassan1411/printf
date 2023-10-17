#include "main.h"
#define BUFF_SIZE 1024
/**
 * _printf - it is aprintf
 * @format: it is format
 * Return: it is return
 */
int _printf(const char *format, ...)
{
va_list args;
size_t indx, maxlength;
char buff[BUFF_SIZE];
indx = 0;
maxlength = BUFF_SIZE;
if (format == NULL)
return (-1);
va_start(args, format);
indx = string(format, buff, maxlength, args, indx);
va_end(args);
write(1, buff, indx);
return (indx);
}
