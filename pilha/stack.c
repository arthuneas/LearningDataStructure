/*
- - -> Stack <- - -
Esse modo é LIFO, last in, First Out

Função PUSH é para adicionar um elemento na stack, parecida com a função da lista encadeada INSERT_INIT
para adicionar um elemento no topo da pilha

Função POP é para remover um elemento na stack, mas ele remove apenas o primeiro elemento e assim consecutivo.
Ou seja, a remoção é apenas do inicio da stack até o ultimo elemento, o elemento mais abaixo.

 */


#include <stdio.h>
#include <stdlib.h>


typedef struct pilhano PilhaNo;

struct pilhano{
    int item;
    PilhaNo* prox;

};

typedef struct{
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

    p -> prim =  novo;

}


int pop(Pilha* p){
    int removed_value;
    PilhaNo* add = NULL;
    
    if (p -> prim == NULL){
        printf("THE STACK IS ALREADY EMPTY\n");
        exit(1);
    
    } else {
        removed_value = p -> prim -> item;
        add = p -> prim;

        p -> prim = p -> prim -> prox;
        
        free(add);

        return removed_value;
    }

    return 0;
}


void free_stack(Pilha* p){
    PilhaNo* atual = p -> prim;
    PilhaNo* temp =  NULL;

    while(atual != NULL){
        temp = atual;
        atual  = atual -> prox;
        free(temp);
    }

    free(p);
}


void print(Pilha* p){
    getchar();
    system("clear");

    if (p ->prim == NULL){
        printf("EMPTY STACK\n");
        return;
    }

    for (PilhaNo* k = p -> prim; k != NULL; k = k -> prox){ 
        printf("-----\n  %d\n-----\n", k -> item);
    }
}



int main(){

    Pilha* my_stack = create();

    int n, k, element, remove;
    printf("digite a quantidade de elementos da sua stack: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        printf("Elemento %d: ", i + 1);
        scanf("%d", &element);
        push(my_stack, element);

    }

    print(my_stack);

    getchar();
    system("clear");

    printf("digite a quantidade de elementos que voce deseja remover da pilha: ");
    scanf("%d", &k);
    getchar();

    for (int i = 0; i < k; i++){
        remove = pop(my_stack);
        printf("Elemento removido: %d\n", remove);
    }

    printf("pilha_resultante: \n");
    print(my_stack);

    free_stack(my_stack);

    return 0;
}