#include <stdio.h>


int f(int a, int b, int i, int j) {
    if(j == a) 
        return i;
    if(i+1 == b) 
        return f(a, b, 0, j+1);
    else
        return f(a, b, i+1, j+1); 
}

int h(int a, int b) {
    return f(a,b,0,0);
}

int m(int c) {
    if (c<100) return c;
    return m(c/10);
}

int n(int c) {
    return h(c,100);
}

int p(int a) {
    return h(m(a), n(a));
}


/*
 * A quale valore vengono valutate, le seguenti espressioni?
 *
    p(1001) _____
    p(1210) _____
    p(1310) _____
    p(13123123901823091210) _____

  */
