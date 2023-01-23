#include "main.h"

/**
 * _printf - function that produces output according to a format.
 * @format: character string.
 *
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int i = 0;

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					count += _char(args);
					break;
				case 's':
				{
					count += _str(args);
					break;
				}
				case '%':
					count += _putchar('%');
					break;
				case 'd':
				case 'i':
					count += _int(args);
					break;
				default:
				return (count);
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
	}
	va_end(args);
	return (count);
}
