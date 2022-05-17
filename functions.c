#include "main.h"

/**
 * @brief 
 * 
 * @param c 
 * @return int 
 */
int _putc(char c)
{
    return (write(1, &c, 1));
}

/**
 * @brief 
 * 
 * @param s 
 * @return int 
 */
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

/**
 * @brief 
 * 
 * @param n 
 */
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