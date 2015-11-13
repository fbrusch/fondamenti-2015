#include <stdio.h>

int p(int a, int b) {
    if(b==0) return 1;
    return a*p(a, b-1);
}


int d(int a, int b) {
    while(a>=b) a = a-b;
    return a;
}


int f(int a, int b) {
   int i=1;
   while(d(i,a) + d(i,b) > 0)
       i++;
   return i;
}


/*
 *
 * A quale valore vengono valutate, le seguenti espressioni?

    f(1,2))     _______
    f(1000,2))  _______
    f(1000,3))  _______
    f(13,2))    _______
    f(14,2))    _______

    C'è una coppia di valori (a,b) per cui
    la valutazione di f(a,b) non termina mai?
    si [] no []
    se sì: a: ______, b: ______
*/
