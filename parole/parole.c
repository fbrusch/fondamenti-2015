#include <stdlib.h>
#include <string.h>

struct freq_parola {
    char* parola;
    int freq;
};

(struct freq_parola)* freqs(char* frase) {

}



char* copian(char* from, char* to)
{
    char* res=(char*)malloc(sizeof(char)*(to-from)+1);
    int i;
    for(i=0;i<to-from;i++) {
        res[i]=from[i];
    }
    res[i]='\0';
    return res;
}

int isLetter(char c) {
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9');
}

char* ppp(char* i) {
        while(isLetter(*i)) {i++;}
        if(*i == '\0') return NULL;
        while(!isLetter(*i)) {i++;}
        return i;
}

char* parola(char* frase, int n) {
    if(n==0) {
        char* i=frase;
        while(isLetter(*i)) {i++;}
        return copian(frase, i);
    } else {
        char* i=ppp(frase);
        if(i==NULL) return NULL;
        return parola(i, n-1);
    }
}

int conta_parole(char* p, char* str) {
    int i=0;
    int j;
    for(j=0;parola(str, j)!=NULL;j++)
        if(strcmp(p, parola(str,j))==0)
            i++;
    return i;
}

char* max_parola(char* frase, int n) {
    char* max_str = NULL;
    int max = 0;
    int i;
    for(i=0;parola(frase, i)!=NULL;i++) {
        int n = conta_parole(parola(frase, i), frase);
        if(n>max) {
            max=n;
            max_str=parola(frase, i);
        }
    }
    return max_str;
}


