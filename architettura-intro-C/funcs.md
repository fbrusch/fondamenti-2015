Introduciamo la sintassi e gli elementi fondamentali del linguaggio C
ripercorrendo i passi fatti con Python. In particolare, ripartiamo dalla
definizione delle funzioni che mappano numeri interi su numeri interi, partendo
dalla più semplice in assoluto, e quindi complicando...

La funzione più semplice in assoluto, ricorderete, è la *costante*, che
"restituisce" sempre lo stesso valore (e, dovendo scegliere, scegliamo il numero
più "semplice", cioè lo 0).

~~~{.C}
    int costante() {
        return 0;
    }
~~~

Le principali differenze con la definizione in Python sono:

1. non c'è la parola chiave `def`
2. il corpo della funzione è delimitato dalle parentesi graffe `{}`, piuttosto che dall'indentazione
diversa. Questo varrà dovunque c'è un blocco di istruzioni (nei rami
dell'`if-else`)
3. dopo il return c'è un punto e virgola (`;`)
4. il nome della funzione è preceduto da `int`: questo è un identificativo del
tipo di dato ritornato dalla funzione. In C, il tipo di dato ritornato da una
funzione (e non solo quello) viene
indicato *esplicitamente*. Vedremo come questo possa costituire, di volta in
volta, un limite oppure un vantaggio. 
Per cominciare ad apprezzare questa duplice natura, passiamo a considerare la
seconda funzione meno complicata in assoluto: l'*identità*!

~~~{.c}
int ident(int x) {
    return x;
}
~~~

Qui vediamo come, quando c'è un parametro, anche di quello debba essere
specificato il tipo. In questo caso, il tipo del parametro `x` è lo stesso di
quello di ritorno della funzione, e la cosa non dovrebbe stupirci.

Ok, ora spingiamo il divertimento al quadrato!

~~~{.C}
int square(int x) {
    return x*x;
}
~~~

[...]

~~~{.C}
int somma(int a, int b) {
    return a+b;
}

int fibo(int n) {
    if(n<2) {return 1;}
    return fibo(n-1) + fibo(n-2);
}

int isprimo(int n) {
    int i;
    i = 2;
    while(i<n){
        if(n % i == 0) {
            return 0;
        }
        i = i +1;
    }
    return 1;
}

int isprimo_rifat(int n) {
    int i;
    for(i=2; i<n; i=i+1)
        if(n%i==0) return 0;
    return 1;
}

#include <stdio.h>

int main() {
    printf("%i\n", costante());
    printf("l'identico di 10 è %i\n", ident(10));
    printf("fibo(4) -> %i\n", fibo(4));
    printf("isprimo(10) -> %i\n", isprimo(10));
    printf("isprimo(17) -> %i\n", isprimo(17));
    printf("isprimo_rifat(10) -> %i\n", isprimo_rifat(10));
    printf("isprimo_rifat(17) -> %i\n", isprimo_rifat(17));
}
~~~
