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

//_print-string using _putc
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

//_printi funtion
void _printi(int n)
{
    unsigned int num = n;

    if (n < 0)
    {
        _putc('-');
        num = -num;
    }
                
    if ((num / 10) > 0)
    {
        _printi(num / 10);
                    
    }
    _putc((num % 10) + '0');
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
            else if (format[i+1] == 's')
            {
                _prints(va_arg(args, char *));
                i++;
            }
            else if (format[i+1] == '%')
            {
                _putc('%');
                i++;
            }
            else if (format[i+1] == 'd' || format[i+1] == 'i')
            {
                _printi(va_arg(args, int));
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
    _printf("Hell%c worl%c\n", 'o', 'd');
    _printf("Hello %s\n", "world");
    /*printf("Hello 100%%\n");*/
    _printf("Hello 100%%\n");
    _printf("Hello %d%%\n", 100);

    return (0);
}