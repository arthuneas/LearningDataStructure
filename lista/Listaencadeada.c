#include <stdio.h>
#include <stdlib.h>

typedef struct listano {
    int item;
    ListaNo* prox;
    
} ListaNo;

typedef struct {
    ListaNo* prim;

} Lista;


void insere(Lista* l, int v) {
    //Cria o nó
    ListaNo* novo =  (ListaNo*) malloc(sizeof(ListaNo));
    
    //Colocamos o valor dentro dele
    novo -> item = v ; 
    
    //Conectamos o novo nó ao inicio da lista 
    novo -> prox = l -> prim;

    //atualiza o começo da lista ser o proximo nó
    l -> prim = novo;
}


void imprime (Lista* l){
    if (l -> prim == NULL){
        printf("A Lista Está Vazia\n");

    } else {
        for (ListaNo* p = l -> prim; p != NULL; p = p -> prox){
            printf("Item = %d\n", p -> item);

        }
    }
}


void remove (Lista* l, int v){
    //deve usar um ponteiro que p (atual) e um ant (anterior)
    ListaNo* p = l -> prim;
    ListaNo* ant = NULL;

    //while (nao for fim da lista e o valor do item não for o digitado)
    while (p != NULL && p -> item != v){
        
        //atribuimos o valor atual como anterior
        ant = p;
        //o valor aponta para o prox
        p = p -> prox;
    }

    //condição de analise para ver se a busca falhou
    if (p == NULL){
        printf("O elemento solicitado não está na lista\n");
        return;
    }

    if (ant == NULL){
        // aqui o primeiro no da lista pertence ao segundo elemento
        l -> prim = p -> prox;

    } else {
        //aqui pegamos o no anterior o atribuimos ao proximo da lista
        //para ser ligado com o proximo
        ant -> prox = p -> prox;
    }

    //agora liberamos o valor p da memoria
    free(p);
}


void libera (Lista* l){
    ListaNo* p = l -> prim;

    while (p != NULL){
        //criacao de variavel temporaria para liberar a lista com seguranca
        ListaNo* t = p -> prox;
        free(p);
        p = t;
    } 

    free(l);
}


Lista* cria (void){
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l -> prim = NULL;
    return l;
}



int main(){

    Lista* meu_beneficio = cria();

    char indice;
    int elem;

    while(indice != 'X'){
        printf("I - Inserir");
        printf("R - Remover");
        printf("P - Imprimir");
        printf("X - Sair");

        printf("Digite o que deseja fazer em sua lista: ");
        scanf("%c", &indice);
        getchar();

        switch (indice){
            case 'I':
                printf("digite um elemento para inserir: ");
                scanf("%d", &elem);
                getchar();
                insere(meu_beneficio, elem);
                break;

            case 'R':
                printf("digite um elemento para remover: ");
                scanf("%d", &elem);
                getchar();
                remove(meu_beneficio, elem);
                break;

            case 'P':
                imprime(meu_beneficio);
                break;
        }

    }

    libera(meu_beneficio);

    return 0;
}