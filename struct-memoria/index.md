# Struct
#

Immaginiamo di voler rappresentare, in C, questi semplici dati anagrafici che rappresentano
una persona: il nome e l'età.

Per il nome possiamo usare una stringa, mentre per l'età possiamo usare un
intero.

Potremmo fare una cosa di questo tipo:

    char* persona_name = "Bob";
    int persona_age = 30;
    
    
Ora, se dovessi rappresentare un'altra persona, potrei fare così:

    char* persona2_name = "Alice";
    int persona2_age = 27;
    
`name` ed `age` le uso sempre _insieme_, riferite ad uno stesso "oggetto".

Per gestire meglio casi come questi, il C ci offre la possibilità di definire
delle _strutture_, cioè dei tipi di dato formati dall'aggregazione di più dati.

Come al solito, _easier done that said_:

    struct persona {
        char* name;
        int age;
    }
    
Una volta definita una struct, la possiamo utilizzare come un vero e proprio
tipo di dato, alla stregua per esempio di `int`. Quindi possiamo per esempio
dichiarare una struttura di tipo persona:

    struct persona p;

A seguito di questa dichiarazione, verrà allocata memoria per contenere il
puntatore a carattere `name` e l'intero `age`.

I dati che costituiscono la struttura di chiamano "campi", e vi si può accedere
così:

    p.nome = "Bob";
    p.age = [[]]30;
    


Come per ogni variabile, anche per `p` possiamo chiederci quale sia l'indirizzo
a partire dal quale è memorizzata.

    address = &p;
    
Di che tipo sarà `address`? Di tipo `(struct persona *)`:

    struct persona* address;

Attraverso `address` possiamo accedere a `persona`:

    (*address).nome = "Alice";
    
C'è una notazione semplificata per questo:

    address->nome = "Alice";
    

Ecco qui sotto un esempio di utilizzo di tutto questo:

    #include <stdio.h>

    struct persona {
        char* nome;
        int numero;
    };

    void stampa_persona(
            struct persona p)
    {
        printf("Nome: %s\n",
                p.nome);
        printf("Numero: %i\n",
                p.numero);
    }

    int main() {

        struct persona a;
        struct persona *p;

        p = &a;

        a.numero = 1;
        a.nome = "francesco";

        (*p).numero = 2;
        (*p).nome = "armando";

        p->numero = 3;
        p->nome = "giulio";


        stampa_persona(a);
    }
