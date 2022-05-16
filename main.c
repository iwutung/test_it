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

int _prints(char *s)
{
    int j = 0;

    while (s[j] != '\0')
    {
        _putc(s[j]);
        j++;

    }
    return (0);
}

#include <stdarg.h>

int _printf(const char *format, ...)
{
    va_list args;
    int i = 0;
    char *str;


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

            else if (format[i+1] == 's')
            {
                str = va_arg(args, char *);
                _prints(str);
                /*int j = 0;

                while (str[j] != '\0')
                {
                    _putc(str[j]);
                    j++;

                }*/
                i++;
            }
            else if (format[i+1] == '%')
            {
                _putc('%');
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
    _printf("Hello worl%c\n", 'd');
    _printf("Hello %s\n", "world");
    /*printf("Hello 100%%\n");*/
    _printf("Hello 100%%\n");

    return (0);
}
