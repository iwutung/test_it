#include <stdarg.h>
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

/**
 * _printc - prints a character
 * 
 * @c: character to be printed 
 * Return: number of characters printed 
 */
int _printc(va_list args)
{
    char c = va_arg(args, int);
	int count = 0;

	count += _putc(c);
	//count++;

	return(count);
}

/**
 * _prints - prints a string
 *
 * @s: string to be printed
 * Return: number of characters printed
 */
int _prints(va_list args)
{
	int j = 0, count = 0;
	char *s = va_arg(args, char *);

    if (s == NULL)
    {
        s = "(null)";
    }
    
	while (s[j] != '\0')
	{
		count += _putc(s[j]);
		j++;
	}
	return (count);
}

//_printi funtion
int _printi(va_list args)
{
	unsigned int num, aux, countnum, count;
	int n;

	count = 0;
	n = va_arg(args, int);
		if (n < 0)
		{
			num = (n * -1);
			count += _putc('-');
		}
		else
			num = n;

	aux = num;
	countnum = 1;
	while (aux > 9)
	{
		aux /= 10;
		countnum *= 10;
	}
	while (countnum >= 1)
	{
		count += _putc(((num / countnum) % 10) + '0');
		countnum /= 10;
	}

    return (count);
}

/**
 * @brief 
 * 
 * @c 
 * Return: int(*)(va_list) 
 */
int (*_select(char c))(va_list)
{
	if (c == 'c')
	{
		return(_printc);
	}
	else if (c == 's')
	{
		return(_prints);
	}
	else if (c == 'i' || c == 'd')
	{
		return(_printi);
	}

	return(NULL);	
}

#include <stdarg.h>

int _printf(const char *format, ...)
{
    int count = 0;
    int (*func)(va_list);

    if (format != NULL)
    {
        va_list args;
        int i = 0;

        va_start(args, format);

        if (format[0] == '%' && format[1] == '\0')
		    return (count);

        while (format[i] != '\0')
        {
            if (format[i] == '%')
            {            
                /*if (format[i+1] == 'c')
                {
                    count += _printc(args);
                    //count++;
                    i++;
                }
                else if (format[i+1] == 's')
                {
                    i++;
                    count += _prints(args);
                    //count++;
                    
                }*/
                if (format[i+1] == '%')
                {
                    count += _putc('%');
                    //count++;
                    i++;
                }
                /*else if (format[i+1] == 'd' || format[i+1] == 'i')
                {
                    count += _printi(args);
                    //count++;
                    i++;
                }*/
                else if (format[i] == '%')
                {
                    _putc(format[i]);
                    count++;
                }

                else
                {
                    func = _select(format[i+1]);
                    if (func != NULL)
                    {
                        count += func(args);
                        //i++;
                    }
                    i++;
                }
                
            }
            else
            {
                _putc(format[i]);
                count++;
            }
            i++;

        }
        va_end(args);
    }
    return (count);
}

#include <stdio.h>
#include <limits.h>

int main(void)
{
    //int len;
    //int len2;
    //unsigned int ui;
    //void *addr;
    //int str = "man gcc: When you invoke GCC , it normally does preprocessing, compilation, assembly and linking. The "overall options" allow you to stop this process at an intermediate stage. For example, the -c option says not to run the linker. Then the output consists of object files output by the assembler. Other options are passed on to one stage of processing. Some options control the preprocessor and others the compiler itself. Yet other options control the assembler and linker; most of these are not documented here, since you rarely need to use any of them. Most of the command line options that you can use with GCC are useful for C programs; when an option is only useful with another language (usually C ++ ), the explanation says so explicitly. If the description for a particular option does not mention a source language, you can use that option with all supported languages. The gcc program accepts options and file names as operands. Many optio... [Diff had to be removed because it was too long] [Diff had to be removed because it was too long] [Diff had to be removed because it was too long] [Diff had to be removed because it was too long] [Diff had to be removed because it was too long] [Diff had to be removed because it was too long] [Diff had to be removed because it was too long] [Diff had to be removed because it was too long] [Diff had to be removed because it was too long] [Diff had to be removed because it was too long] [Diff had to be removed because it was too long] [Diff had to be removed because it was too long]";

    /*len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("%c", 'S');
    printf("%c", 'S');
    len = _printf("%c", 'S');
    printf("%d\n", len);

    _printf("_printf: %s", "This sentence is retrieved from va_args!\n");
    printf("printf: %s", "This sentence is retrieved from va_args!\n");
    _printf("_printf: Complete the sentence: You %s nothing, Jon Snow.\n", "know");
    printf("printf: Complete the sentence: You %s nothing, Jon Snow.\n", "know");
    _printf("_printf: Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
    printf("printf: Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
    _printf("_printf: %c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');
    printf("printf: %c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');
    _printf("_printf: %s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');
    printf("printf: %s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');
    _printf("_printf: css%ccs%scscscs\n", 'T', "Test");
    printf("printf: css%ccs%scscscs\n", 'T', "Test");
    _printf("_printf: man gcc:\n%s", str);
    printf("printf: man gcc:\n%s", str);
    _printf("_printf: ");
    _printf("%");
    _printf("\n");
    printf("printf: ");
    printf("%");
    printf("\n");
    _printf("_printf: %!\n");
    printf("printf: %!\n");
    _printf("_printf: %K\n");
    printf("printf: %K\n");*/
    //printf("%");
    //_printf("Unknown:[%r]\n");
    //printf("Unknown:[%r]\n");

    int len, len2;

	len = _printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');
	len2 = printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');
    printf("\n%d, %d", len, len2);

    fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

    //printf(NULL);

    return (0);
}
