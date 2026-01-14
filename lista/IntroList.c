/*
--- LISTA ESTATICA --->
Essa lista é um vetor com um tamanho maximo definido desde o inicio do programa, sendo assim, armazenamos os elementos um após o outro, em consecutivas posições de memorias.
um número vai sendo armazenado em caixa, o n+1 vai para a caixa seguinte.

Supondo que há uma lista com 5 elementos, array[4]
A vantagem dessa lista é a posição pre-identificada da memoria, garantindo um acesso rápido e direto.
A maior desvantagem é ao adicionar um evento no meio da lista, pois o adicionar um elemento na posição p, os elementos seguinte vão para a posição n+1

Porém, é problemático caso se a lista estiver com todas as posições ocupadas e se seu tamanho for substancialsim



--- LISTA DINAMICA --->
Nesse caso, ao invés de organizar tudo em um array, usamos um nó individual que pode estar em qualquer lugar da memória. 
O nó possui duas infos: 
--> o dado, numero, a informação que será analisado
--> um ponteiro com o endereço do próximo nó da sequência.
seria como uma corrente, cada nó está conectado apenas ao próximo. A lista começará por um ponteiro *inicio, e o ultimo aponta para NULL, indicando o fim da lista.

Para adicionar um elemento na lista, direcionamos os ponteiros, a seta do novo nó deve aponta para o proximo e a seta do elemento que estava atrás deve apontar para o novo nó.

Logo, ela é mais vantajosa que a lista estática pela sua crescente dinamica, não necessário um limite pré-definido de elementos.
Para encontrar um elemento do nó (apontado por *begin), seguir a seta para o próximo até achar o elemento, isso é chamado de acesso sequencial. 
Ao querendo o elemento na posição 10, precisa-se passar pelos 9 anteriores. O que é contraponto da lista dinamica, que voce pode acessar pelo array diretamente.



--- LISTA DUPLAMENTE ENCADEADA --->
Ela tem dois nós, um ponteiro prox para o elemento seguinte e um ponteiro ant para o elemento anterior.
A lista é como uma corrente que pode ser percorrida nos dois sentidos: para frente e trás.

Em um lista com 5000 elementos, para achar o item antes do atual, podemos percorrer a lista para frente e para trás.
Para inserir um nó B, precisa-se ajustar dois parãmetros:
Prox de A -> B
Prox de B -> C
Ant de C -> B
Ant de B -> A
Com isso, percorrenmos a lista em dois sentidos.



--- LISTA CIRCULAR --->
Nas listas anteriores, o ultimo ponteiro apontava para NULL indicando o fim da lista.
Nessa lista, o ponteiro do ultimo elemento aponta para o primeiro, fechando um ciclo, logo, a lista não há um fim definido.
Sua vantagem é percorrer o ciclio diversas vezes continuamente.
-- code --
ListaNo* p = l->prim
if (p!= NULL){
    while(p != l->prim){
        p = p->prox;
    }
}


*/
#include <stdio.h>
#include <stdlib.h>


typedef struct listano { //aqui temos a estrutura do nó
    int item; //o valor armazenado no item, carga do trem
    ListaNo* prox; //ponteiro para o proximo nó, engate para o proximo trem, aramzena endereço de memoria

} ListaNo; //isso conecta um vagão a outro, isso conecta um nó a outro

typedef struct { //locomotiva do trem, onde amarzena o primeiro valor
    ListaNo* prim; //primeira informação (item e prox) da lista, se prim por NULL, a lista está vazia

} Lista; 

//Agora, precisamos criar a lista e garantir sua existencia atribuindo NULL a prim.
void insere (Lista* l, int v){ //l: representa a lista toda, v: o item inserido
    //1. criamos um espaço na memoria de modo dinamico para um novo elemento, o nó
    ListaNo* novo = (ListaNo*) malloc(sizeof(ListaNo)); 
    
    //2. o nó existe, precisamos o valor v dentro do item
    //adicionar valor a novo elemento
    novo -> item = v; // aqui o novo elemento acessa o campo item, aqui o v recebe esse valor.

    //3. agora queremos colocar o priemiro endereço da lista no próximo, fazendo com que seja o engate
    novo -> prox = l -> prim; // aqui o endereço antigo se liga ao novo

    //4. agora precisa apontar o novo elemento como o primeiro elemento de novo]
    l -> prim = novo;
    
}


void imprime(Lista* l){
    if (l -> prim == NULL) {
        printf("LISTA VAZIA");
    } else {
    
    }

}



int main(){


    
    return 0;
}