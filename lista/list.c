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


void insert(Lista* l, int v){
    ListaNo* novo = (ListaNo*) malloc(sizeof(ListaNo));

    novo -> item = v;

    novo -> prox = l -> prim;

    l -> prim = novo;
}


void print(Lista* l){
    if (l -> prim == NULL){
        printf("Empty List\n");
    
    } else {
        for (ListaNo* p = l -> prim; p != NULL; p = p -> prox){
            printf("%d", p -> item);

        }
    }
}


void remove(Lista* l, int v){
    //inicializacao e declaracao
    ListaNo* p = l -> prim;
    ListaNo* ant = NULL;

    //achar o no
    while (p != NULL && p -> item != v){
        ant = p;
        p = p -> prox;

    }

    if (p == NULL){
        printf("Element Not Found In List!\n");
        return;
    }

    //remover o no
    if (ant == NULL){
        l -> prim = p -> prox;
    
    } else {
        ant -> prox = p -> prox;
        
    }

    //liberar valor removido a memoria
    free(p);
}


Lista* create(void){
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l -> prim = NULL;
    return l;
}



int main(){
    Lista* minha_lista = create();

    char indice = '\0';
    int elem;

    while(indice != 'X'){

        printf("Digite o que deseja fazer em sua lista: ");

        scanf("%c", &indice);

        getchar();

        switch (indice){

        case 'I':
            printf("digite um elemento para inserir: ");
            scanf("%d", &elem);
            getchar();

            insert(minha_lista, elem);
            break;

        case 'F':

            printf("digite um elemento para remover: ");

            scanf("%d", &elem);
            getchar();
            remove(minha_lista, elem);
            break;

        case 'P':

            printf("digite um elemento para remover: ");

            scanf("%d", &elem);
            getchar();
            remove(minha_lista, elem);
            break;

        case 'D':

            printf("digite um elemento para remover: ");

            scanf("%d", &elem);
            getchar();
            remove(minha_lista, elem);
            break;

        case 'X':
            printf("%d", minha_lista);
            return;

        }

    }

    return 0;
}