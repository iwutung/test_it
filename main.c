#include <stdio.h>
/**
putchar function
returns 1 if success, else 0
*/

#include <unistd.h>

int _putc(char c)
{
    return (write(1, &c, 1));
}

#include <stdarg.h>

int _printf(const char *format, ...)
{
    va_list args;
    int i = 0;

    va_start(args, format);

    while (format[i] != '\0')
    {
        if (format[i] != '%')
        {
            _putc(format[i]);
        }
        else if (format[i] == '%')
        {
            if (format[i+1] == 'c')
            {
                _putc(va_arg(args, int));
                i++;
            }
        }
        i++;
    }

    va_end(args);

    return (0);
}

#include <stdio.h>

int main(void)
{
	printf("Hello, i added this");
    _printf("Hello worl%c\n", '1');
    printf("Hello 100%%\n");

    return (0);
}
