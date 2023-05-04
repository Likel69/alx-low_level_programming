#include <limits.h>
#include <stdio.h>
#include "main.h"
#include <stdarg.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */

int _printf(char *format, ...)
{
   va_list ap; /* points to each unnamed arg in turn */
   int val;
   char *p, *sval, ichar;
   va_start(ap, format); /* make ap point to 1st unnamed arg */
   for (p = format; *p; p++) 
   {
      if (*p != '%') 
      {
         putchar(*p);
         continue;
      }
      switch (*++p) 
      {
      	case 'c':
      	    ichar = va_arg(ap, int);
      	    printf("%c", ichar);
      	    break;
        case 's':
            for (sval = va_arg(ap, char *); *sval; sval++)
            putchar(*sval);
            break;
        case 'd':
            val = va_arg(ap, int);
            printf("%d", val);
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

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    
    return 0;
}
