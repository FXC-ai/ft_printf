#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include "libft/libft.h"

void foo(char *fmt, ...);

int main()
{
	
	int c;

	c = 120;
	printf("TEST %%c : %c\n", c);

	char *str_test0 = "lsakdghl k;ouhl; k jskhLKJH ;R'PO E R58 RE+- ERGGLKW 88 R";
	printf("TEST %%s : \"%s\"\n", str_test0);
	
	printf("TEST %%p : %p\n", &str_test0);

	int n = -2147483648;
	printf("TEST %%d : %d\n", n);
	printf("TEST %%d : %d\n", 012);
	
	printf("TEST %%i : %i\n", 012);
	printf("TEST %%i : %i\n", 033);

	unsigned int un = 2147483649;
	printf("TEST %%u : %u\n", un);
	printf("TEST %%u : %u\n", UINT_MAX);

	printf("TEST %%x : %x\n", -1598);
	printf("TEST %%x : %x\n", -0x12f);

	printf("TEST %%X : %X\n", 15);
	printf("TEST %%X : %X\n", 0x12f);

	foo("s et dc", "OUI", 21, 'P');

    //printf("TEST %%X : %g\n", 0x12f); NE COMPILE PAS DANS CE CAS LA.


	return 0;
}

void foo(char *fmt, ...)
{
    va_list ap, ap2;
    int d;
    char c, *s;

    va_start(ap, fmt);
    va_copy(ap2, ap);
    while (*fmt)
        switch(*fmt++) 
		{
            case 's':                       /* string */
                s = va_arg(ap, char *);
                printf("string %s\n", s);
                break;
            case 'd':                       /* int */
                d = va_arg(ap, int);
                printf("int %d\n", d);
                break;
            case 'c':                       /* char */
                                   /* Note: char is promoted to int. */
                c = va_arg(ap, int);
                printf("char %c\n", c);
                break;
        }
    va_end(ap);

                   /* use ap2 to iterate over the arguments again */

    va_end(ap2);
}

