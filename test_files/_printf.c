#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: The format to be printed
 * @...: The arguments to be used by the funtion
 * Return: 0
 */
int _printf(const char *format, ...)
{
	int count = 0;

	va_list args;
	int i = 0, (*func)(va_list);

	va_start(args, format);

	if (format[0] == '%' && format[1] == '\0')
		    return (count);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			count += _putc(format[i]);
		}
		else
		{
			if (format[i+1] == '%')
                {
                    count += _putc('%');
                    i++;
                }
			else
			{
				func = _select(format[i+1]);
                if (func != NULL)
                {
                    count += func(args);
                    i++;
                }
			}
		}
		i++;
	}
	va_end(args);
	return (count);
}
