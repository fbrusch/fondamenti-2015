/*
title: cifre diverse di un numero rappresentato in una certa base
tags: interi, rappresentazione
text:
    it: "Dire quale output produrrebbe l'esecuzione del seguente programma"
    en: "Show what output would produce the execution of the following program"
suitable_for: prima_in_itinere, appello
notes:
    it: |
        `f` calcola il numero di cifre differenti che contiene un certo numero, rappresentato in base b

        `g` controlla se la cifra a è contenuta nella rappresentazione in base `b` del numero `c`
    en: |
        `f` computes the number of different digits used to represent `a` in base `b`
        `g` checks wether the digit `a` is present in the representation of `c` in base `b`
*/

#include <stdio.h>

int g(int a, int b, int c)
{
    int i;
    for (; c>0; c/=b)
        if (a == (c%b)) return 1;
    return 0;
}

int f(int a, int b)
{
    int n=0;
    for (; a>0; a /= b)
        if (!g(a%b, b, a/b))
            n++;
    return n;
}

int main()
{
    printf ("%i\n",f(123,10));
    printf ("%i\n",f(1223,10));
    printf ("%i\n",f(1*123+1*(123*123*123),123));
    printf ("%i\n",f(2+2*123+2*(123*123)+2*(123*123*123),123));
    return (0);
}
