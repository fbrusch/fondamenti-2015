int r(int n)
{
    int i,sum=0;
    for(i=1;i<=l(n);i++)
        sum+=q(n,h(n,i));
    return sum;
}

int main()
{
    printf("%i\n",r(72));
}
