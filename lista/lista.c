#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    float info;
    struct lista* prox;
} Lista;

// Inserir no início
Lista* inserir(Lista* l, float i){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    return novo;
}

// Percorrer e imprimir a lista
void percorrer(Lista* l){
    Lista* p;
    for(p = l; p != NULL; p = p->prox){
        printf("info = %.2f\n", p->info);
    }
}

// Remover a primeira ocorrência de um valor
Lista* remover(Lista* l, float valor){
    Lista* anterior = NULL;
    Lista* p = l;

    while (p != NULL && p->info != valor) {
        anterior = p;
        p = p->prox;
    }

    if (p == NULL) return l; // valor não encontrado

    if (anterior == NULL) {
        l = p->prox; // era o primeiro da lista
    } else {
        anterior->prox = p->prox;
    }

    free(p);
    return l;
}

// Liberar toda a lista
void liberar(Lista* l){
    Lista* p = l;
    while(p != NULL){
        Lista* proximo = p->prox;
        free(p);
        p = proximo;
    }
}

int main (){
    Lista* l = NULL;

    int n;
    float numero;

    printf("digite o numero de elementos que deseja colocar: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        printf("digite o %d elemento: ", i + 1);
        scanf("%f", &numero);
        l = inserir(l, numero);
    }
    

    printf("Lista original:\n");
    percorrer(l);

    printf("digite qual elemento deseja remover");
    scanf("");
    l = remover(l, 4);

    printf("\nLista após remover o valor 4:\n");
    percorrer(l);

    liberar(l);
    return 0;
}