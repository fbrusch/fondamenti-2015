# Massimo Basi

Si chiede di codificare una funzione che elabora una stringa expr, passata
come unico parametro, costituita da una sequenza di numeri separati da spazi.  I numeri rappresentano una sequenza di coppie (`b`,`n`), tali per cui `b`
è una base (compresa tra 2 e 9) e n è un numero espresso in base `b`. Ogni
coppia di numeri consecutivi esprime quindi un valore intero `v`.
 
La funzione da codificare deve restituire il massimo tra i valori espressi dalle coppie di numeri della stringa `expr`.

Ad esempio, se la funzione riceve la stringa `"2 101  3 2  8 101"`, costituita
da tre coppie che esprimono nell'ordine i valori `5` (101 in base 2), `2` (2 in
base 3) e `65` (101 in base 8), deve restituire il valore 65.

Si possono considerare diversi livelli di "difficoltà", che corrispondono a
una maggiore o minore variabilità nella stringa da valutare:

- *basic*: anche le codifiche, non solo le basi, sono sempre costituite da una sola cifra, e vi è sempre un solo spazio come separatore tra i numeri 
- *medium*: le codifiche e le sequenze di spazi sono di lunghezza anche superiore a 1 
- *full*: le codifiche possono anche rappresentare numeri
negativi (sempre espressi con un segno '-' davanti alla cifra più
significativa)

Il sistema verifica la soluzione con stringhe di "difficoltà" crescente:
affrontando da subito il livello "full" si ottiene ovviamente anche la
soluzione dei precedenti, mentre non vale il viceversa (però... una
soluzione più limitata permette comunque di risolvere almeno i test più semplici).