#include <stdio.h>
#include <stdlib.h>


typedef struct filano FilaNo;

struct filano {
    int item;
    FilaNo* prox;
};

typedef struct filaNo {
    FilaNo* prim;
    FilaNo* ult;

} Fila;


Fila* create(void){
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f -> prim = NULL;
    f -> ult = NULL;

    return f;
}


void enqueue(Fila* f, int v){
    FilaNo* novo = (FilaNo*) malloc(sizeof(FilaNo));

    //o novo elemento vai para o final da fila
    novo -> prox = NULL;
    novo -> item = v;

    if (f -> ult == NULL){
        f -> prim = novo;
        f-> ult = novo;

    } else {
        f -> ult -> prox = novo;
        f -> ult = novo;
    
    }

}


int dequeue(Fila* f){
    FilaNo* temp = NULL;

    int valor_removido;
    
    if (f -> prim == NULL) {
        printf("THE QUEUE IS ALREADY EMPTY");
        exit(1);

    } else if (f -> prim == f -> ult){
        valor_removido = f -> prim -> item;
        
        temp = f -> prim;

        f -> prim = NULL;
        f -> ult = NULL;

        free(temp);

        return valor_removido;

    } else {
        valor_removido = f -> prim -> item;
            
        temp = f -> prim;

        f -> prim = f -> prim -> prox; 

        free(temp);

        return valor_removido;
    }
}


void print(Fila* f){
    if (f -> prim == NULL){
        printf("THE QUEUE IS EMPTY");   
        return;
    }

    for (FilaNo* i = f -> prim; i != NULL; i = i -> prox){
        printf("%d ->", i -> item);
    }
    printf("NULL");
}


void libera_meu_beneficio(Fila* f){
    FilaNo* atual = f -> prim;
    FilaNo* temp = NULL;

    while(atual != NULL){
        temp = atual;
        atual = atual -> prox;
        free(temp);
    }

    free(f);
}


int main(){


    return 0;
}