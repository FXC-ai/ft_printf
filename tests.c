#include <stdio.h>

int sum(char a, int b, int c)
{

    printf("r = %c", a);
    return(b + c);

}

int subtract(int a, int b)
{

    return a - b;
}

int main(void)
{


int (*p[4]) ();


p[0] = sum; /* address of sum() */
p[1] = subtract; /* address of subtract() */

p[0](1,2,4);

}