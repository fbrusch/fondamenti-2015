/*
suitable_for: [prima_prova, appello]
tags: [interi, fattorizzazione, numeri_primi]
text:
    it: "Si indichi l'output prodotto dall'esecuzione del seguente codice"
    en:
title: 'fattori primi al quadrato'
notes:
    it: |
        `f` verifica la primalità di un numero
        `g` verifica il __grado__ di `a` come fattore del numero `b`,
        cioè l'esponente massimo a cui `b` può essere elevato,
        rimanendo un divisore di `a`
        `h` ritorna il valore del massimo tra gli esponenti di tutte le possibili
        scomposizioni in fattori di a (es: h(3*7*7*7*13)=3)
    en:

*/

#include <stdio.h>

int f(int n)
{
    int i;
    if (n==1) return 0;
    for (i=2;i<n;i++)
        if ((n%i) == 0)
            return 0;
    return 1;
}

int g(int a, int b)
{
    int r=1; int e;
    for (e=0;(a%r)==0;r*=b, e++)
        ;
    return e-1;
}

int h(int a)
{
    int e=0; int i;
    for (i=2;i<=a;i++)
        if (g(a,i)>e) e=g(a,i);
    return e;
}

main()
{
    printf ("%i\n",h(3));
    printf ("%i\n",h(10));
    printf ("%i\n",h(20));
    printf ("%i\n",h(256*11));
    printf ("%i\n",h(1));
}
