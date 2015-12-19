#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int valore;
    struct nodo * prossimo;
};

void print_list(struct nodo *head) {
    if(head->prossimo == NULL) {
        printf("%i\n", head->valore);
        return;
    }
    printf("%i -> ",head->valore);
    print_list(head->prossimo);
}

void append(int n, struct nodo* head) {
    if(head->prossimo == NULL) {
        /* la lista è lunga 1!!!! */
        head->prossimo = malloc(sizeof(struct nodo));
        head->prossimo->valore = n;
        head->prossimo->prossimo = NULL;
        return;
    }
    append(n, head->prossimo);
}

void push(int n, struct nodo **testa) {
    struct nodo* new_elem = malloc(sizeof(struct nodo));
    new_elem->valore = n;
    new_elem->prossimo = *testa;
    *testa = new_elem;
}

struct nodo *last(struct nodo *head) {
    if(head->prossimo == NULL) {
        return head;
    }
    return last(head->prossimo);
}

int main() {

    struct nodo elemento;
    int i;
    struct nodo* testa;
    struct nodo* tmp;

    elemento.valore = 13;
    elemento.prossimo = NULL;

    testa = &elemento;

    print_list(testa);

    for(i=0;i<10;i++) {
        append(i*i, testa);
    }

    print_list(testa);

    for(i=0;i<10;i++) {
        push(i*i*i, &testa);
    }

    print_list(testa);

    return 0;

}
