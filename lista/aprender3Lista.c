#include <stdio.h>
#include <stdlib.h>

typedef struct listano ListaNo;

struct listano {
    int item;
    ListaNo* prox;

};

typedef struct {
    ListaNo* prim;
    ListaNo* ult;

} Lista;


Lista* createList(void){
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l -> prim = NULL;
    l -> ult = NULL;

    return l;
}


int isEmpty(Lista* l){
        return (l -> prim == NULL);
}


//inserir no inicio da lista
void FInsert(Lista* l, int v){
    ListaNo* novo = (ListaNo*) malloc(sizeof(ListaNo));

    novo -> item = v;

    //adicionar em uma lista vazia
    if(isEmpty(l)){
        novo -> prox = l -> prim;
        l -> prim = novo;
        l -> ult = novo;
       
    //adicionar com um outro elemento
    } else {
        novo -> prox = l -> prim;
        l -> prim = novo;
    }

}


void LInsert(Lista* l, int v){
    ListaNo* novo = (ListaNo*) malloc(sizeof(ListaNo));

    novo -> item = v;

    if(isEmpty(l)){
        novo -> prox = l -> ult;
        l -> prim = novo;
        l -> ult = novo;
    } else {
        novo -> prox = NULL;
        l -> ult -> prox = novo;
        l -> ult = novo;

    }

}


int FRemove(Lista* l){
    ListaNo* atual = l -> prim;
    ListaNo* rem_add = NULL;

    int removed_value;

    if(isEmpty(l)){
        return 0;
    
    } else {
        removed_value = l -> prim -> item;
        rem_add = atual;
        l -> prim = atual -> prox;

        if (l -> prim == NULL){
            l -> ult = NULL;
        }
       
        free(rem_add);
    
        return removed_value;

    }
}


int LRemove(Lista* l){
    ListaNo* atual = l -> ult;
    ListaNo* aux = NULL;

    int removed_value;

    if(isEmpty(l)){
       return 0;
    
    } else {
        aux = atual;
        removed_value = l -> ult -> item;
        
        if (l -> prim == l -> ult){
            l -> prim = NULL;
            l -> ult = NULL;

        } else {
            ListaNo* penultimo = l -> prim;
            while (penultimo -> prox != l -> ult){
                penultimo = penultimo -> prox;

            }

            penultimo -> prox = NULL;
            l -> ult = penultimo;
        }

        free(aux);
        return removed_value;      
    }
}


//printa a lista e encerra o programa
void printList(Lista* l){
    if (isEmpty(l)) {
        return; 

    }

    printf("\n");
    for(ListaNo* p = l -> prim; p != NULL; p = p -> prox){
        printf("%d\n", p -> item);
    }

}


void freeList(Lista* l){
    ListaNo* atual = l -> prim;
    ListaNo* aux = NULL;

    while(atual != NULL){
        aux = atual;
        atual = atual -> prox;
        free(aux);
    }
    
    free(l);
}


int main(){

    Lista* minha_lista = createList();

    char indice;
    int elem;

    while(1){
         
        scanf(" %c", &indice);

        switch (indice){
            case 'I':
                scanf("%d", &elem);
                FInsert(minha_lista, elem);
                break;

            case 'F':
                scanf("%d", &elem);
                LInsert(minha_lista, elem);
                break;

            case 'P':
                printf("%d\n", LRemove(minha_lista));
                break;

            case 'D':
                printf("%d\n", FRemove(minha_lista));
                break;

            case 'X':
                printList(minha_lista);
                freeList(minha_lista);
                return 0;            
        }

    }
    
    return 0;
}