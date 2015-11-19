#include <stdio.h>

int g(int a)
{
    int i;
    for (i=a-1;i>1 && a%i!=0 ;i--)
        ;
    return i==1 ? 1 : 0;

}

int h(int n, int k)
{
    int i;
    for(i=2;i<=n;i++)
    {
        if (g(i) && n%i==0) k--;
        if (k==0) return i;
    }
    return 0;
}

int l(int a)
{
    int i;
    for(i=1;h(a,i)!=0;i++)
        ;
    return i-1;
} 

int q(int n, int d)
{
    if(n%d!=0) return 0;
    return 1+q(n/d,d); 
}

