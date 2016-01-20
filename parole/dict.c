#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _elem {
    char* key;
    int data;
    struct _elem* next;
} elem;

elem* get(elem* d, char* key) {
    if(d==NULL) return NULL;
    if(strcmp(d->key, key)==0) return d;
    return get(d->next, key);
}

void insert(elem** head, char* key, int d) {
    elem* obj=(elem*)malloc(sizeof(elem));
    obj->key=strdup(key);
    obj->data=d;
    obj->next=*head;
    (*head)=obj;
}

void stampa(elem* head) {
    if(head==NULL) printf("NULL\n");
    else {
        printf("%s:%i->", head->key, head->data);
        stampa(head->next);
    }
}

void inc(elem** head, char* key) {
    elem* e=get(*head, key);
    if(e) (e->data)++;
    else insert(head, key, 1);
}

int len(elem* head) {
    if(head==NULL) return 0;
    return 1+len(head->next);
}

elem** dict2array(elem* head) {
    elem* j=head;
    int l=len(head), i;
    elem** res=(elem**)malloc(l*sizeof(elem*));
    for(i=0;i<l;i++,j=j->next)
        res[i]=j;
    return res;
}

void sort(elem** a, int l) {
    int i,j;
    for(i=0;i<l;i++)
        for(j=0;j<l-1;j++) {
            if(a[j]->data<a[j+1]->data) {
                elem* tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
            }
        }
}


int main() {
    int l, i;
    elem** a;
    elem* head=NULL;
    char *token, *string, *tofree;

    tofree = string = strdup("ciao ciao boh pausa uhm uhm ciao");

    while ((token = strsep(&string, " ")) != NULL)
           inc(&head, token);

    /*inc(&head, "ciao");*/
    /*inc(&head, "boh");*/
    /*inc(&head, "boh");*/
    /*inc(&head, "ciao");*/
    /*inc(&head, "pausa");*/
    /*inc(&head, "pausa");*/
    /*inc(&head, "pausa");*/
    /*inc(&head, "pausa");*/
    /*inc(&head, "ciao");*/
    stampa(head);
    l = len(head);
    a = dict2array(head);
    sort(a, l);
    for(i=0;i<l;i++) {
        printf("%s:%i\n",a[i]->key, a[i]->data);
    }
}


