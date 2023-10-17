#include "main.h"
/**
 * append_outbuffer - append a character to out buff
 * @character: character to be appened
 * @buff: a pointer to the the buff
 * @idx: index to append to
 * @maxlen: max length of the buff
*/
void append_outbuffer(char character, void *buff, size_t idx, size_t maxlen)
{
	if (idx < maxlen)
		((char *)buff)[idx] = character;
}

/**
 * append_string - append a character to out buffer
 * @buff: a pointer to the the buufer
 * @indx: index to append to
 * @maxlen: max length of the buffer
 * @args: list of args
*/
void append_string(char *buff, va_list args, size_t *indx, size_t maxlen)
{
	char *str;

	str = va_arg(args, char*);
	if (str == NULL)
	{
		str = "(null)";
	}
	while (*str)
	{
		append_outbuffer(*str, buff, (*indx)++, maxlen);
		str++;
	}
}
/**
 * parser - Receives the main string and all the necessary parameters to
 * print a formated string.
 * @format: A string containing all the desired characters.
 * @buff: A list of all the posible functions
 * @maxlength: max length of buffer
 * @args: A list containing all the argumentents passed to the program.
 * @indx: size of buffer
 * Return: int number of printed
 */
int string(const char *format, char *buff, size_t maxlength,
	va_list args, size_t indx)
{

	while (*format)
	{
	if (*format != '%')
	{
		append_outbuffer(*format, buff, indx++, maxlength);
		format++;
	continue;
	}
	else
		format++;
	switch (*format)
	{
	case 'c':
		append_outbuffer((char)va_arg(args, int), buff, indx++, maxlength);
		format++;
	break;
	case 's':
		append_string(buff, args, &indx, maxlength);
		format++;
	break;
	case '%':
		append_outbuffer('%', buff, indx++, maxlength);
		format++;
	break;
	default:
		append_outbuffer(*format, buff, indx++, maxlength);
		format++;
	break;
	}
	}
	return (indx);
}
