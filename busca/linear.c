/*
a busca linear é universal e não necessita da ordenação do array, ao contrário da 
busca binaria.
*/
#include <stdio.h>
#include <stdlib.h>


int buscaLinear(int *arr, int n, int elem){

    for (int i = 0; i < n; i++){
        if (arr[i] == elem){
            return i;
        } 
    }
    return -1;
}


int main() {

    int tamanho, i, j, elem;
    i = 0;
    j = 0;

    printf("qual o tamanho do seu array: ");
    scanf("%d", &tamanho);

    getchar();
    system("clear");

    int* arr = (int*) malloc(tamanho * sizeof(int));

    while (i < tamanho){
        printf("digite o conteudo de arr[%d]: ", i);
        scanf("%d", &arr[i]);

        if (arr[i] == 1001){
            break;
        }

        i++;
    }

    while(j < i){
        printf("array[%d] = %d\n", j, arr[j]);

        j++;
    }

    printf("qual elemento você quer achar: ");
    scanf("%d", &elem);

    printf("%d", buscaLinear(arr, i, elem));

    return 0;
}