#include <stdio.h>
#include <stdlib.h>


typedef struct pilhano PilhaNo;

struct pilhano {
    int item;
    PilhaNo* prox;
};

typedef struct {
    PilhaNo* prim;
} Pilha;


Pilha* create(void){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p -> prim = NULL;

    return p;
}


void push(Pilha* p, int v){
    PilhaNo* novo = (PilhaNo*) malloc(sizeof(PilhaNo));

    novo -> item = v;
    novo -> prox = p -> prim;
    p -> prim = novo;
}


int pop(Pilha* p){
    PilhaNo* atual = p -> prim;
    PilhaNo* temp = NULL;

    int valor_removido;

    if (p == NULL){
        printf("PILHA VAZIA\n");
        exit(1);
    } else {
        temp = p -> prim;
        
        valor_removido = p -> prim -> item;

        p -> prim = p -> prim -> prox;
        free(temp);
        

        return valor_removido;
    }
}


void printStack(Pilha* p){      

    if (p -> prim == NULL){
        printf("The Stack Is Already Empty");
        return;
    }

    for (PilhaNo* k = p -> prim; k != NULL; k = k -> prox){
        printf("-----\n   %d\n-----", k -> item);
    }

}


void freeStack(Pilha* p){
    PilhaNo* atual = p -> prim;
    PilhaNo* temp = NULL;

    while(atual != NULL){
        temp = atual;
        atual = atual -> prox;
        free(temp);
    }
    free(p);
}


int main(){



    return 0;
}