#include <stdio.h>


int q(int a) {
    return a*a;
}

int e(int a, int b) {
    if(b==0) return 1;
    return a*e(a, b-1);
}

int e10(int a) {
    return e(10, a);
}

int iq(int a) {
    int i;
    for (i=0;q(i)<=a;i++)
        ;
    return i-1;
}

int ie10(int a) {
    int i;
    for (i=0;e10(i)<=a;i++)
        ;
    return i-1;
}

/*

 A quale valore vengono valutate le seguenti espressioni?

    iq(2))             _______________________
    iq(4))             _______________________
    iq(26))            _______________________
    iq(10000))         _______________________
    ie10(1))           _______________________
    ie10(123))         _______________________
    ie10(321))         _______________________
    ie10(321321321))   _______________________
*/
