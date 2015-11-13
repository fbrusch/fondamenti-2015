#include <stdio.h>

int f(int n, int c)
{
    if (n==0) return 0;
    if (n%10 == c) return (1 + f(n/10, c));
    else return f(n/10, c);
}

int g(int n1, int n2)
{
    int i;
    for (i=1;i<10;i++)
        if (f(n1,i) != f(n2,i))
            return 0;
    return 1;
}

int k(int n)
{
    int i=1;
    while(n>i)
        i*=10;
    return i;
}

void h(int n)
{
    int i;
    for (i=k(n)/10;i<k(n);i++)
        if (g(n,i))
            printf ("%i\n",i);
}

int main()
{
    h(123);
    h(1222);
    h(9999);
}
