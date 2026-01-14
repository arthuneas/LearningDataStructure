#include <stdio.h>
#include <stdlib.h>

typedef struct pilhano PilhaNo;

struct pilhano{
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

    novo -> prox = p -> prim;

    novo -> item = v;

    p -> prim = novo;
}


int pop(Pilha* p){
    PilhaNo* atual = p -> prim;

    int valor_removido;
    
    if(p -> prim == NULL){
        printf("THE STACK IS ALREADY EMPTY");
        exit(1);
    
    } else {    
        //precisa se a primeira operaçao par salvar o valor do antigo no prim
        valor_removido = p -> prim -> item;

        //aqui o valor do começo atualiza para o segundo
        p -> prim = p -> prim -> prox;

        free(atual);

        return valor_removido;
    }

}


void print(Pilha* p){
    if (p -> prim == NULL){
        puts("THERE IS NOTHING TO PRINT, THE STACK IS EMPTY");
        return;
    }

    for(PilhaNo* k = p -> prim; k != NULL; k = k -> prox){
        puts("-----");
        printf("  %d  ", k -> item);
        puts("-----");
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