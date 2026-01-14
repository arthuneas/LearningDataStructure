#include <stdlib.h>
#include <stdio.h>

typedef struct pilhano PilhaNo;

struct pilhano{
    int item;
    PilhaNo* prox;

};


typedef struct{
    PilhaNo* primeiro;

} Pilha;


int isEmpty(Pilha* pilha){
    return (pilha -> primeiro == NULL);
}


Pilha* createStack(void){
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));
    pilha -> primeiro =  NULL;

    return pilha;
}


Pilha* push(Pilha* pilha, int valor){
    PilhaNo* new_element = (PilhaNo*) malloc(sizeof(PilhaNo));

    new_element -> item = valor;
    
    new_element -> prox = pilha -> primeiro;

    pilha -> primeiro = new_element;
}


int pop(Pilha* pilha){
    PilhaNo* auxiliar;
    int removed_value;

    if(isEmpty(pilha)){
        return -1;
    }

    removed_value = pilha -> primeiro -> item;

    auxiliar = pilha -> primeiro;        
    
    pilha -> primeiro = pilha -> primeiro -> prox;

    free(auxiliar);

    return removed_value;
}


void printStack(Pilha* pilha){
    if(isEmpty(pilha)){
        return;
    }

    for (PilhaNo* auxiliar = pilha -> primeiro; auxiliar != NULL; auxiliar = auxiliar -> prox){
        printf("%d\n", auxiliar -> item);
    }    
}


void freeStack(Pilha* pilha){
    PilhaNo* auxiliar;

    while (pilha -> primeiro != NULL){
        auxiliar = pilha -> primeiro;
        pilha -> primeiro = pilha -> primeiro -> prox;
        free(auxiliar);
    }
    free(pilha);
}


int main(){



    return 0;
}