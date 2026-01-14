/*
== TIPOS DE COMPLEXIDADE ==
a. Time Complexity 
    indica quanto tempo (ou operações) o algoritmo leva para ser executado.

b. Space Complexity
    indica quanto espaço na memoria adicional o algoritmo requer além dos dados de entrada.

    --------------------------
== NOTAÇOES MAIS USADAS (assintóticas) ==
    -> O(log n): aumenta lentamente conforme n cresce
        > logarítmica
        ex: busca binária.
    
    -> O(n): tempo cresce proporcionalmente ao tamanho de entrada.
        > linear
        
    -> O(n log(n)): um pouco mais lento que o linear, comum em algoritmos de ordenação.
        > quasilinear

    -> O(nˆ2): cresce muito rapidamente; ocorre em laços aninhados.
        > quadrática

    -> O(2ˆn): muito lento; cresce muito rapido com n.
        > exponencial

    -> O(n!): extremamente lento; usado em permutações.
        > fatorial
        ex: problema do caixeiro viajante

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//complexidade exponencial, cresce absurdamente rápido 
//se tiver interaçao, a complexidade fica 0(n)
int fibo (int n){
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibo(n - 1) + fibo (n - 2);
}


//exemplos de complexidade fatorial
//ou seja, ela cresce 10!, ou seja, absurdamente errado.
//
void permutar(int *arr, int inicio, int fim) {
    if (inicio == fim) {
        for (int i = 0; i <= fim; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for (int i = inicio; i <= fim; i++) {
        // troca arr[i] com arr[inicio]
        int temp = arr[i];
        arr[i] = arr[inicio];
        arr[inicio] = temp;

        permutar(arr, inicio + 1, fim);

        // desfaz a troca (backtrack)
        temp = arr[i];
        arr[i] = arr[inicio];
        arr[inicio] = temp;
    }
}


int main(){

    int n;
    printf("qual o numero de n: ");
    scanf("%d", &n);

//exemplo de complexidade linear
//cresce de acordo com n
//n = 2, output tera dois olas.
    for (int i = 0; i < n; i++) { 
        printf("Olá\n");
    }
    printf("-----------------------------\n");


//exemplo de complexidade quadratica
//cresce de acordo com os ns
// n = 2, terao 4 outputs, matricial.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Teste\n");
        }
    }
    printf("-----------------------------\n");


// exemplo de complexidade logarítmica
// a cada iteração, i dobra de valor
// ou seja, número de passos cresce lentamente: log₂(n)
// n = 16, output = 2, 4, 8, 16
    int i = 1;
    while (i < n) {
        i = i * 2;
        printf("%d\n", i);
    }
    printf("-----------------------------\n");


//o laço "for" externo roda n vezes
//o laço "while" interno roda log(i) vezes
//dessa forma, a complexidade vai ser O(n log n)
    for (int i = 1; i <= n; i++) {
        int j = 1;
        while (j < i) {
            j = j * 2;
            printf("n: %d | j: %d\n", i, j);
        }
    }
    printf("-----------------------------\n");

    printf("%d", fibo(n));


    
    return 0;
}