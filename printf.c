#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - prints anything
 *
 * @format: list of argument types passed to the function
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, count = 0;
	va_list args;
	char *str;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	for (i = 0; format[i]; i++)
		if (format[i] == '%')
		{
			if (format[++i] == '\0')
				return (-1);
			if (format[i] == '%')
				count += _putchar('%');
			else if (format[i] == 'c')
				count += _putchar(va_arg(args, int));
			else if (format[i] == 's')
			{
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				count += print_string(str);
			}
			else if (format[i] == 'd' || format[i] == 'i')
				count += print_number(va_arg(args, int));
			else
			{
				count += _putchar('%');
				count += _putchar(format[i]);
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
	va_end(args);
	return (count);
}
