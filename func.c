#include "main.h"

/**
 * print_num - Helper function to print an integer
 * @n: The integer to print
 */
void print_num(int n)
{
	char digit;

	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
	}

	if (n / 10)
	{
		print_num(n / 10);
	}

	digit = (n % 10) + '0';
	write(1, &digit, 1);
}

/**
 * num_printf - Custom printf function
 * @format: The format string
 * @...: The variable number of arguments
 *
 * Return: The number of characters printed
 */
int num_printf(const char *format, ...)
{
	va_list args;
	int num;
	int printed_chars = 0;

	va_start(args, format);

	while (*format)
	{
	if (*format == '%' && (format[1] == 'd' || format[1] == 'i'))
	{
		num = va_arg(args, int);
		print_num(num);
		printed_chars += 1;
		format += 2;
	}
	else
	{
		write(1, format, 1);
		printed_chars += 1;
		format += 1;
	}
	}

	va_end(args);
	return (printed_chars);
}
