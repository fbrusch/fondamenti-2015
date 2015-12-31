### `Express Yourself`

Si richiede di codificare una funzione in linguaggio *C* che valuta una
semplicissima espressione aritmetica contenuta in una stringa.

La funzione riceve una stringa <expr> costituita da una sequenza
di uno o più numeri interi positivi, intervallati da operatori
aritmetici (che possono essere solo + o -), senza nessuno spazio
né altri caratteri.

La funzione restituisce un intero pari al valore
dell'espressione.

Ad esempio se la funzione riceve la stringa `"2+1+3"` restituisce
il valore intero `6`.

Si possono considerare diversi livelli di "difficoltà", che
corrispondono a una maggiore o minore variabilità nella stringa
da valutare: 

- *basic*: i numeri sono tutti costituiti da una sola cifra e
l'unico operatore è il '+' 
- *medium*: i numeri possono anche essere di due cifre.  
- *full*: i numeri hanno lunghezza arbitraria e l'operatore può
anche essere il '-'

Il sistema valuta la soluzione proposta con stringhe di
"difficoltà" crescente: affrontando da subito il livello "full"
si ottiene ovviamente anche la soluzione dei precedenti, mentre
non vale il viceversa (però... una soluzione più limitata
permette comunque di risolvere almeno i test più semplici).
