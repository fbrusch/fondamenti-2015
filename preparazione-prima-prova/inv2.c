#include <stdio.h>

int og(n)
{
    if(n<10) return 1;
    return 10*og(n/10);
}

int i(int n)
{
    if(n < 10) return n;
    return n%10*og(n)+i(n/10);
}

int main()
{
    printf("%i\n", og(1));
    printf("%i\n", og(1234));
    printf("%i\n", i(1234));
    printf("%i|n", i(321))
}
