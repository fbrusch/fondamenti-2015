# Array di stringhe
#
# Caso d'uso: ordinamento di parole
#

Immaginiamo di voler ordinare un insieme di stringhe, magari rappresentanti le
parole di un testo. Perché dovremmo volerlo fare? Per un sacco di ragioni. Una
notevole è che magari vogliamo poter cercare se una parola è presente
nell'insieme in maniera efficiente: in questo caso la [ricerca
dicotomica](https://it.wikipedia.org/wiki/Ricerca_dicotomica) (quella
che ci consente di cercare una parola in un vocabolario di 1000 pagine con la
stessa disinvoltura di uno di 2000) potrebbe essere quello che fa al caso nostro... 

Affrontiamo il problema per gradi: partiamo dall'ordinamento di un array di
interi.

Chiariamoci le idee con un algoritmo classico: il [bubble
sort](https://it.wikipedia.org/wiki/Bubble_sort)

Il bubble sort si esegue reiterando un certo numero di volte un particolare
"trattamento" dei dati del nostro array: Si confronta il primo elemento dell'array con il secondo. Se i due non sono
in ordine, li si inverte. Poi si passa a confrontare il secondo con il terzo, e
cosi via fino all'$n-1$ con l'$n$. Alla fine del trattamento, l'elemento più
grande è sicuramente in fondo. Se si riapplica il procedimento, il secondo
elemento più grande finirà di sicuro in penultima posizione, e così via.
Reiterando $n$ volte si ha la sicurezza di avere ordinato tutti gli elementi.

Si noti come questo sia un'algoritmo di ordinamento cosiddetto _in place_:
ad essere ordinato è l'array originario, del quale si perde quindi
l'informazione sull'ordinamento iniziale.

In `C` un'implementazione (ben poco ottimizzata) del bubblesort per un array di
interi può essere:

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

Alcune cose notevoli:

1. L'array di interi viene passato come `int a[]`. Sarebbe stato equivalente
passarlo come `int* a`?
2. Viene passata anche la lunghezza dell'array, con il parametro `l`. (&Egrave;
proprio necessario?)
3. Viene utilizzata una variabile di supporto per scambiare gli elementi (che
viene dichiarata all'interno del blocco del corpo del `for`, giustamente, visto
che serve solo lì dentro)

Ok, ora proviamo a passare dagli interi alle stringhe.

Per prima cosa: come rappresentiamo un array di stringhe?

Per rispondere, chiediamoci ancora una volta: come rappresentiamo una stringa?
Come un array di caratteri, terminato da un carattere `\0` (un terminatore). E
il tipo di una variabile array, come sappiamo, è un puntatore. Un puntatore a
cosa? Al tipo di dati dell'array.

Quindi, ci riferiamo ad una stringa attraverso un puntatore a carattere, che
punta al primo carattere di quella stringa.

Vediamo un esempio di _dichiarazione_ e di _inizializzazione_ di un array di
stringhe:
    
    char* a[6] = {"padroneggiate", "di", "brutto", "la", "materia",
                  "oh yeah"};
                  
`char* a[6]` è la dichiarazione di un array di sei puntatori a `char`, che
potrebbero rappresentare sei stringhe.

Vediamo una semplice funzione che fa qualcosa con un array di questo tipo:
stampa le stringhe una sotto l'altra:

    
    #include <stdio.h>

    void stampa_stringhe(char* a[], int l) {
        int i;
        for(i=0;i<l;i++)
            printf("%s\n", a[i]);

    }

Ok. Proviamo allora ad adattare la funzione di ordinamento che abbiamo usato per
gli interi:


    void ordina_stringhe(char** a, int l) {
        int i, j;
        for(j=0;j<l;j++)
            for(i=0;i<l-1;i++) {
                if(a[i+1] > a[i])) {
                    // swappa gli elementi!
                    char* tmp;
                    tmp    = a[i];
                    a[i]   = a[i+1];
                    a[i+1] = tmp;
                }
            }
    }
    
Questo adattamento però è un po' troppo _naive_. Perché non funziona? Perché il
confronto avviene tra i valori degli _indirizzi di memoria_ a cui cominciano le
stringhe, e non alfabeticamente tra i loro caratteri!

Se avessimo una funzione `ltstr`, (_l_ess-_t_han-_str_ing), che confronta due
stringhe e ci dice se la prima è minore della seconda, potremmo tradurre il
nostro ordinamento, in modo corretto, così:


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

Ok, allora scriviamo `ltstr`!

    int ltstr(char* a, char* b) {
        if (a[0] != b[0]) return a[0] < b[0];
        if(a[0] == '\0') return -1;
        return ltstr(a+1, b+1);
    }
    
Il ragionamento ricorsivo è semplice: confronto i primi caratteri di `a` e di
`b`: se sono diversi, posso stabilire subito quale stringa viene prima
alfabeticamente. Se sono diversi, tolgo il primo carattere e considero le
stringhe `a` e `b`, tranne le prime lettere (`a+1`, `b+1`)[[.]]

Ecco fatto! Ho ottenuto una funzione che ordina un array di stringhe!

Ecco un testbench per la mia funzione:

int main(int argc, char* argv[]) {
    stampa_stringhe(argv+1, argc-1);
    ordina_stringhe(argv+1, argc-1);
    stampa_stringhe(argv+1, argc-1);
    return 0;

    char* a[6] = {"padroneggiate", "di", "brutto", "bacca", "materia",
                  "oh yes"};

    stampa_stringhe(a, 6);
    ordina_stringhe(a, 6);
    stampa_stringhe(a, 6);
}


