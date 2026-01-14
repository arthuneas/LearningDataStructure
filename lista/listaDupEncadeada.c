#include <stdlib.h>
#include <stdio.h>


typedef struct listano{
    int item;
    struct listano* prox;
    struct listano* ant;
} ListaNo;

typedef struct{
    ListaNo* prim;
    ListaNo* ult;

} Lista;


Lista* cria(void){    
    //alloca memoria para a criação da lista;
    Lista* l = (Lista*) malloc(sizeof(Lista));
    
    //inicializa os ponteiros
    l -> prim = NULL;
    l -> ult = NULL;

    //retorna a lista criada
    return l;
}


void insere_inicio(Lista* l, int v){
    //criamos o nó
    ListaNo* novo = (ListaNo*) malloc(sizeof(ListaNo));

    //inserir o endereço de onde vamos guardar no que vamos guardar
    //onde vamos guardar = o que vamos guardar
    novo -> item = v;

    //ajuste dos ponteiros do nó
    //o engate da frente aponta para o antigo primeiro nó 
    novo -> prox = l -> prim;

    //ajuste do nó de tras do primeiro elemento
    novo -> ant = NULL;
    
    //analisa se a lista já possui um elemento
    if (l -> prim != NULL){
        //aqui acessamos para o endereço do elemento anterior acessar todo o novo endereço
        l -> prim -> ant = novo;

    } else {
        //aqui o ultimo elemento também é o novo elemento
        l -> ult = novo;

    }

    //aqui o inicio da lista reconhece a existencia do primeiro elemento como novo
    l -> prim = novo;

}





int main(){


    return 0;
}