# Massimobasi reloaded!

Si chiede di codificare una funzione che elabora due stringhe, ns e is,
passate
come parametri. La prima è costituita da una sequenza di numeri separati da
spazi.  I numeri rappresentano una sequenza di coppie (b,n), tali per cui b
è una base (compresa tra 2 e 9) e n è un numero espresso in base b. Ogni
coppia di numeri consecutivi esprime quindi un valore intero v.

La seconda è costituita da una sequenza di espressioni, nella forma di
somme di numeri interi. I valori delle espressioni rappresentano degli
indici, che "puntano" ai valori codificati dalle coppie della prima stringa.
La funzione da codificare deve restituire il massimo tra i valori espressi
dalle coppie di numeri della stringa <expr>, indicati dalle espressioni
di is.

Ad esempio, se la funzione riceve le stringhe "2 101  3 2  8 101" e "0
1+0", la funzione deve ritornare il valore 5 (101 in base 2).

Si possono considerare diversi livelli di "difficoltà", che corrispondono a
una maggiore o minore variabilità nella stringa degli indici:

- *basic*: la stringa degli indici contiene un solo indice, in forma di
numero semplice (es: "12") 
- *medium*: la stringa degli indici contiene più indici, ma numerici
(es: "3 4 1") 
- *full*: la stringa degli indici contiene più valori, in forma di
somme (es: "1+1 0+1 2+3") 
Il sistema verifica la soluzione con stringhe di "difficoltà" crescente:
affrontando da subito il livello "full" si ottiene ovviamente anche la
soluzione dei precedenti, mentre non vale il viceversa (però... una
soluzione più limitata permette comunque di risolvere almeno i test più
semplici).

Attenzione: il sistema registra solo l'esito dell'ultimo tentativo
effettuato in ordine cronologico, quindi... tenete al sicuro il codice
funzionante! :)
