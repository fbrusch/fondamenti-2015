#include <stdio.h>

void stampa_stringhe(char* a[], int l) {
    int i;
    for(i=0;i<l;i++)
        printf("%s\n", a[i]);

}

/*[...] ordina_stringhe(char* a[], int l) {*/

    /*{....}*/

/*}*/


void ordina_interi(int a[], int l) {
    int i, j;
    for(j=0;j<l;j++)
        for(i=0;i<l-1;i++) {
            if(a[i+1]<  a[i]) {
                // swappa gli elementi!
                int tmp;
                tmp = a[i];
                a[i] = a[i+1];
                a[i+1] = tmp;
            }
        }
}

int ltstr(char* a, char* b) {
    if (a[0] != b[0]) return a[0] < b[0];
    if(a[0] == '\0') return -1;
    return ltstr(a+1, b+1);
}

void ordina_stringhe(char** a, int l) {
    int i, j;
    for(j=0;j<l;j++)
        for(i=0;i<l-1;i++) {
            if(ltstr(a[i+1], a[i])) {
                // swappa gli elementi!
                char* tmp;
                tmp    = a[i];
                a[i]   = a[i+1];
                a[i+1] = tmp;
            }
        }
}

void stampa_array_interi(int a[], int l) {
    int i;
    for(i=0;i<l;i++) printf("%i\n", a[i]);
}


int main(int argc, char* argv[]) {
    stampa_stringhe(argv+1, argc-1);
    ordina_stringhe(argv+1, argc-1);
    stampa_stringhe(argv+1, argc-1);
    return 0;
    /*int a[6] = {20, 45, 12, 345, 7, -1};*/

    /*stampa_array_interi(a, 6);*/
    /*ordina_interi(a, 6);*/
    /*stampa_array_interi(a, 6);*/

    char* a[6] = {"padroneggiate", "di", "brutto", "bacca", "materia",
                  "oh yes"};

    stampa_stringhe(a, 6);
    ordina_stringhe(a, 6);
    stampa_stringhe(a, 6);
}
