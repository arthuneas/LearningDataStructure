#include <stdio.h>
#include <stdlib.h>

//alocaçao de vetor: *arr
//para matriz: **arr

/*
a estrutura necessita de duas tres coisas:
- a matriz
- numero de vertices
- numero de arestas
*/

typedef struct {
    int **matriz;
    int vertices, arestas;

} graph;

graph* inicializarGrafo(int n){
    graph *g = (graph*) malloc(sizeof(graph));

    g -> vertices = n;
    g -> arestas = 0;

    g -> matriz = (int**) malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        g -> matriz[i] = (int*) malloc(n * sizeof(int));

        for (int j = 0; j < n; j++) {
            g -> matriz[i][j] = 0;
        }
    }

    return g;
}

void insereGrafo(graph* g, int v, int w) {
    if (g -> matriz[v][w] == 0) {

        //fazer apenas nessa direção [v][w] cria um grafo direcionado

        g -> matriz[v][w] = 1;

        g -> arestas++; 
    }
}

void printGraph(graph* g) {
    for (int i = 0; i < g -> vertices; i++) {
        printf("Vertice %d: ", i);

        for (int j = 0; j < g -> vertices; j++) {
            if (g -> matriz[i][j] == 1){
                printf("%d -> ", j);
            }
        }

        puts("");
    }
}



int main(){

    int n;
    
    printf("digite a quantidade de vertice(s): ");
    scanf("%d", &n);

    graph* grafo;
    grafo = inicializarGrafo(n);

    insereGrafo(grafo, 0, 1);
    insereGrafo(grafo, 1, 2);
    insereGrafo(grafo, 2, 0);

    printGraph(grafo);

    return 0;
} 
