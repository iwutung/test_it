#include <stdio.h>
#include <unistd.h>

#include "main.h"

/**
 * _putc - writes a character to standard output
 *
 * @c: character to print
 * Return: 1 if success, -1 if unsuccessful
 */
int _putc(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printc - prints a character
 * 
 * @args - character arguments to be printed
 * Return: count of characters printed 
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
 * @args: string to be printed 
 * Return:count of characters printed 
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

/**
 * _printi - print integer and decimal
 *
 * @n: the integer of the decimal to be printed
 *
 */
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