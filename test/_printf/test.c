#include <limits.h>
#include <stdio.h>
#include "main.h"
#include <stdarg.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */

int _printf(char *fmt, ...)
{
   va_list ap; /* points to each unnamed arg in turn */
   char *p, *sval, ichar;
   int ival, val;
   double dval;
   unsigned int uint, oint;
   va_start(ap, fmt); /* make ap point to 1st unnamed arg */
   for (p = fmt; *p; p++) 
   {
      if (*p != '%') 
      {
         putchar(*p);
         continue;
      }
      switch (*++p) 
      {
         case 'd':
            val = va_arg(ap, int);
            printf("%d", val);
            break;
         case 'i':
            ival = va_arg(ap, int);
            printf("%i", ival);
            break;
         case 'u':
            uint = va_arg(ap, int);
            printf("%u", uint);
            break;
         case 'c':
            ichar = va_arg(ap, int);
            printf("%c", ichar);
            break;
         case 'o':
            oint = va_arg(ap, unsigned int);
            printf("%d", oint);
            break;
        case 'f':
            dval = va_arg(ap, double);
            printf("%f", dval);
            break;
        case 's':
            for (sval = va_arg(ap, char *); *sval; sval++)
            putchar(*sval);
            break;
        default:
            putchar(*p);
            break;
      }
   }
   va_end(ap); /* clean up when done */
   
   return 0;
}

int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
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
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    return (0);
}

