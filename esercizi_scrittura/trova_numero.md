Si chiede di codificare una funzione che elabora due stringhe, `val` e
`pos`,
passate come parametri, costituite da sequenze di numeri separati da spazi.  I
numeri di `val` rappresentano una sequenza di valori, quelli di `pos` una sequenza
di posizioni. Ogni posizione si riferisce a un valore della prima sequenza,
indicando con 0 la posizione del primo valore, 1 quella del secondo, ...

La funzione da codificare deve restituire il minimo tra i valori indicati dalle
posizioni di pos. Eventuali posizioni negative o superiori al numero di valori
in `val` sono da considerarsi non valide, e quindi i "non-numeri" da loro non
indicati non devono essere considerati.

Ad esempio, se la funzione riceve le stringhe

`val` : "100 50 31 -45 999 -111 456" 

`pos` : "0 4 -2 6 9 2 -12 3 11"

deve restituire -45 (il -111, che è il minimo assoluto in `val`, non è considerato
perché la sua posizione, 5, non compare in `pos`).

Si possono considerare diversi livelli di "difficoltà", che corrispondono a una
maggiore o minore variabilità nella stringa da valutare:

- *basic*: valori e posizioni sono sempre costituiti da una sola cifra, i
valori non sono mai negativi, e le posizioni sono sempre valide 
- *medium*: valori e posizioni, comunque mai negativi, possono essere
costituiti da più cifre 
- *full*: valori e posizioni possono anche essere
negativi

Il sistema valuta la soluzione proposta con stringhe di "difficoltà" crescente:
affrontando da subito il livello "full" si ottiene ovviamente anche la soluzione
dei precedenti, mentre non vale il viceversa (però... una soluzione più limitata
permette comunque di risolvere almeno i test più semplici).

Attenzione: il sistema registra solo l'esito dell'ultimo tentativo effettuato in
ordine cronologico, quindi... tenete al sicuro il codice funzionante! :)
