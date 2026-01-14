#include <stdio.h>
#include <stdlib.h>


typedef struct listano ListaNo;

struct listano {
    int item;
    ListaNo* prox;
};

typedef struct {
    ListaNo* prim;

} Lista;


Lista* create(void){
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l -> prim = NULL;

    return l;
}


ListaNo* criano(int item){
    ListaNo* novo = (ListaNo*) malloc(sizeof(ListaNo));
    novo -> item = item;
    novo -> prox = NULL;

    return novo;
}


void insert(Lista* l, int item){
    ListaNo* novo = criano(item);

    novo -> prox = l -> prim;
    l -> prim = novo;   
}


void print(Lista* l){
    if(l -> prim == NULL){
        printf("Empty List\n");
        return;
    }

    for (ListaNo* p = l -> prim; p != NULL; p = p -> prox){
        printf("%d -> ", p -> item);
        
    }
    
    printf("NULL\n");

}


void free_list(Lista* l){
    ListaNo* atual = l -> prim;
    ListaNo* prox = NULL;

    while (atual != NULL){
        prox = atual -> prox;
        free(atual);
        atual = prox;
    }

    free(l);
}


void remove(Lista* l, int item){
    ListaNo* ant = NULL;
    ListaNo* atual = l -> prim;
    
    if (l -> prim == NULL){
        printf("The List is Already Empty\n");
    }
    

    while(atual != NULL && item != atual -> item){
        ant = atual;
        atual = ant -> prox;

    }

    if (atual == NULL){
            printf("Element Not Found\n");
    } 

    if (ant == l -> prim){
        atual = ant;
        
    } else {
        atual = atual -> prox;
        ant = atual;

    } 

}



int main(){

    Lista* minha_lista = create();

    int n, element;

    printf("Digite de elementos que deseja adicionar na sua lista: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        scanf("%d", &element);

        insert(minha_lista, element);
    }

    print(minha_lista);


    return 0;
}
