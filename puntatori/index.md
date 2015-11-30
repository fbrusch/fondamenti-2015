---
layout: page
---

# La memoria e il C

Abbiamo visto come Python ci offra delle strutture dati molto elastiche e
flessibili, come le *liste*, che consentono di adattarsi *dinamicamente* ai
dati che acquisiamo e/o generiamo durante l'esecuzione di un programma. D'altra
parte, abbiamo visto come i dispositivi di memoria presentino un'interfaccia
molto meno *astratta*: una serie ordinata di *parole*, ciascuna di dimensioni
(numero di bit) determinata, accessibile tramite indirizzi.  Come è possibile
implementare il sofisticato comportamento dinamico delle strutture di Python
utilizzando la primitiva interfaccia della memoria? Per capirlo, utilizzeremo
un ottimo livello di astrazione intermedio: il C. Il C difatti ci offre
un'interfaccia alla memoria che astrae molto poco, rendendoci la visto comunque
più facile di quanto succederebbe in codice macchina, o in assembler.
Ma bando alle chiacchiere, andiamo subito sul pezzo...

## Mamma, da dove nascono le variabili? E quando muoiono, dove vanno?

Consideriamo il seguente codice:

```C

    int main()
    {
     int a;
        
     for (a=0;a<10;a++)
      printf ("%i\t",a);
    }

```

Concentriamoci su: `int a`. In che modo questa dichiarazione viene interpretata dal compilatore?
Come sappiamo, tutti i dati che servono all'esecuzione del programma vengono memorizzati nella... _memoria_.
Ricordiamo che, per quello che ci riguarda, la memoria può essere modellizzata
come una tabella di celle numerate, nelle quali è possibile scrivere, e dalle
quali è possibile leggere. Ogni cella può contenere una sequenza di bit di una
certa dimensione, tipicamente una potenza di 2 (8, 16, 32 bit) 

In un certo momento, lo stato della memoria sarà qualcosa del tipo:

|Indirizzo      |Dat     |
|:--------------|--------|
|       1       |00000000|
|               |        |
|       2       |00001100|
|       3       |01011010|
|       4       |10100100|
|   .....       |........|
|     100       |00101010|
|    .....      |        |

Per scrivere un dato, è necessario fornire il numero della riga (_indirizzo_) e il dato da scrivere (_dato_)

Ok, torniamo al problema di come nascono le variabili, e dell'interpretazione
della dichiarazione `int a`. Quando il compilatore incontra `int a`, capisce
che, nel codice che segue, faremo riferimento ad `a` come ad una variabile di
valore intero. Quello che il compilatore fa è di prenotare (_allocare_) una
locazione di memoria per contenere il valore della variabile `a`. Se una cella
sola non basta, perché per esempio gli interi che utilizziamo necessitano di 16
bit per essere rappresentati, mentre le celle della memoria sono a singolo byte
(8 bit), il compilatore alloca tante celle quante ne servono per memorizzare il
dato.  Ma cosa vuole dire che il compilatore _alloca_ memoria per la variabile
`a`? Vuol dire che sceglie un pezzetto di memoria per contenere `a` (un erto
numero di celle contigue), e _si segna_ da qualche parte che quella memoria è
_riservata_ ad `a`. Cioè, da qualche parte, il compilatore si segna questa
informazione: "la variabile `a` è memorizzata in due celle, a partire dall
100".  In questo modo, se dovesse incontrare un'altra dichiarazione, tipo `char
b`, avrebbe tutta l'informazione per allocare una zona di memoria diversa.
Ora: successivamente, tutte le operazioni che utilizzano il valore di `a`
vengono trasformate in letture alle celle 100 e 101, e tutte quelle che
modificano il valore di `a` vengono tradotte in scritture alle stesse celle.

E per gli array??

    int a[10];

Quando il compilatore incontra questa dichiarazione, alloca spazio contiguo
sufficiente per memorizzare tutti gli elementi dell'array (in questo caso, ad
esempio, continuando a considerare l'ipotesi che un intero occupi due celle di
memoria, il compilatore potrebbe allocare la memoria dall'indirizzo 100 al 119.

Notare come tutte queste cose avvengano al momento della compilazione. Il
motivo per cui non abbiamo potuto utilizzare, fino ad ora, strutture dati
dinamiche, tipo array la cui dimensione è stabilita _durante l'esecuzione_ (a
_runtime_) piuttosto che durante la compilazione (a _compile time_), è che
abbiamo lasciato fare tutto il lavoro di allocazione della memoria al
compilatore. E' il momento di assurmerci le nostre responsabilità, e prendere
in mano il nostro destino.

## L'allocazione dinamica della memoria

Nella libreria standard C esiste una funzione che consente di _riservare_ della
memoria durante l'esecuzione del programma. L'unica informazione richiesta è la
quantità di memoria che serve. La funzione si chiama `malloc`. E così la
chiamata:

    malloc(10)

alloca 10 parole di memoria. `malloc` controlla se in memoria ci sono 10 celle
libere. Se sì, si segna in una tabella che sono occupate e... attenzione:
_restituisce l'indirizzo della prima delle celle occupate_.  L'indirizzo? E
cosa me ne faccio, dell'indirizzo?

## I puntatori

Si da il caso che, in C, sia possibile accedere direttamente alla cella di
memoria ad un certo indirizzo, se lo si conosce.  Capiamoci con un caso
concreto. Consideriamo la nostra solita dichiarazione:

    int c;

Abbiamo capito che il compilatore assocerà al nome di variabile `c` un
indirizzo in memoria. Ebbene, esiste il modo di sapere qual è questo indirizzo!
Questo è possibile con l'operatore `&`: `&c` è un espressione che ha il valore
dell'indirizzo in memoria della variabile `c`! E che ce ne facciamo,
dell'indirizzo di `c`, una volta che l'abbiamo ottenuto? Beh, possiamo per
esempio memorizzarlo in una variabile:

    a = &c;

Ma che di che tipo deve essere, `a`? Lo vediamo tra un attimo. L'indirizzo in
memoria di una variabile si chiama anche _puntatore_ a quella variabile. Dopo
l'assegnamento di sopra, `a` contiene il puntatore a `c`. Si dice anche che
_`a` punta a `c`_. Ora chiediamoci: che altro posso fare, con un puntatore?
Un'altra cosa notevole che posso fare è _accedere alla locazione di memoria
alla quale il puntatore punta_. Saltando l'intermediazione del compilatore!
Questo è possibile tramite l'operatore `*`. Immaginiamo di voler scrivere il
valore `1` alla locazione di memoria il cui indirizzo è il valore della
variabile `a`. La cosa si fa così:

    *a = 1;

In questo modo abbiamo scritto `1` alla locazione di memoria alla quale punta
`a`. Ma sopra avevamo fatto in modo che `a` 'puntasse' a `c`. Quindi, secondo
voi, cosa stamperà la seguente chiamata a `printf`?

    printf ("%i",c);

L'operatore `*` si può usare anche per leggere dalla memoria:

    printf ("%i",*a);

Ok, ora poniamoci il problema del tipo della variabile `a`. Che cosa contiene
la variabile `a`? Contiene un puntatore ad un valore intero. Quindi
l'espressione `*a` è un valore intero. Cioè `*a` è un `int`. Allora, se
vogliamo dichiarare `a` come puntatore ad intero, la dichiarazione è:

    int *a;

Bene. Torniamo alla `malloc`. Abbiamo detto che `malloc` ritorna l'indirizzo alla
prima cella di memoria allocata. Se questo è vero, potremmo "creare"
autonomamente una variabile intera, dichiarando un puntatore, allocando la
memoria per contenere il dato, e facendo puntare il puntatore a quella zona di
memoria. E' molto più facile a farsi:

{% highlight c %}
    
    int *p;  
    
    p=malloc(Hey un momento!);
    
{% endhighlight %}

Hey, un momento? Quanta memoria mi serve, per contenere un intero? In generale, non siamo tenuti a saperlo. Per fortuna esiste una funzione speciale, `sizeof`, con cui possiamo ottenere quest'informazione. Il numero di parole che serve per contenere un intero è quindi `sizeof(int)`. E, quindi, per allocare memoria per un intero, facciamo così:

    p=malloc(sizeof(int));

A questo punto, possiamo usare `*p` per accedere alla zona di memoria che abbiamo appena allocato, e che contiene un intero. Non è fantastico?

    *p=1;
    (*p)++
    printf ("%i",*p)

## E gli array?

Ebbene, abbiamo un puntatore, memorizzato nella variabile `c`, di tipo puntatore. Sappiamo che `*c` ci consente di accedere alla cella di memoria "puntata" da `c`. Ma a noi piace esplorare. E quindi ci chiediamo: che succede se cerchiamo di accedere a `c+1`? Facciamo questo esperimento:

    int a[2]={10,20};
    c = &a[0];
    printf ("%i",*c);
    printf ("%i",*(c+1));

Cosa succede? Succede che gli elementi dell'array `a`, come possiamo immaginare, sono memorizzati, in memoria, tutti in sequenza. Quindi, se otteniamo l'indirizzo del primo elemento, `a[0]`, che d'ora in poi chiamareremo _base_ dell'array, possiamo ottenere gli indirizzi degli altri, sommando alla base un valore intero.
Ora, aprite bene gli occhi, ecco un paio di equivalenze notevoli in C:

    a == &a[0]
    a[n] == *(a+n)

Queste due uguaglianze sono sempre vere! Cioè: se abbiamo dichiarato un array `a` con `int a[10]`, l'espressione `a` da sola rappresenta l'indirizzo al primo elemento, cioè la base! Quindi: quando dichiariamo un array, stiamo dichiarando un puntatore e contemporaneamente, stiamo chiedendo al compilatore di allocare la memoria necessaria per contenere gli elementi dell'array e di far puntare il puntatore all'inizio della zona di memoria allocata.
Beh, se ci riflettiamo, ora sappiamo farlo anche noi, senza bisogno dell'aiuto del compilatore. E, soprattutto, possiamo farlo a run time!

Ecco un esempio:

    #include <stdio.h>

    int main()
    {
        int *a;
        int i,n;
        printf ("quanto lo vuoi lungo, l'array?");
        scanf("%i",&n);                                 
        a=malloc(sizeof(int)*n);    // alloca lo spazio per l'array, e fai puntare
                                    // a allo spazio allocato
        for (i=0;i<n;i++)           // riempi l'array di valori
            a[i]=i;                 
        for (i=0;i<n;i++)           // stampa i valori dell'array
            printf("%i",a[i])
    }


Dal codice sopra, possiamo finalmente anche capire la ragione dell'operatore `&` prima della variabile in cui vogliamo memorizzare il dato richiesto dalla `scanf`. Il fatto è questo: in C, come abbiamo visto, tutte le variabili sono passate _per valore_. Cioè, chiamiamo una funzione, `f(e)`, dove `e` è una qualsiasi espressione, quello che succede è che:
- il valore di `e` viene valutato
- una _copia_ del valore di `e` viene passata a `f`
Quindi, se `e` è una variabile, a `f` viene passato il valore di `e`, ed `f` non può in nessun modo cambiare il contenuto della variabile `e`. "Ma `scanf` il valore lo cambia!", vi sento dire! E avete ragione! Ma la cosa va così: a `scanf` non viene passato il valore della variabile nella quale memorizzare il dato, bensì _un puntatore ad essa_! In questo modo, `scanf` può accedere direttamente alla zona di memoria in cui è memorizzata la variabile in cui mettere il dato.
Proviamo a fare qualcosa di analogo, e che non potremmo fare senza puntatori: una funzione che scambia il valore di due variabili.

<br>

    void f(int *a, int *b)
    {
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }


Et voilà!


