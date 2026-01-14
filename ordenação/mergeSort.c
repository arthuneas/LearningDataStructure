#include <stdio.h>
#include <stdlib.h>

//nesse algoritmo ha a divisao o array em duas partes, uma ordenada e outra desordenada
//tem complexidade n^2 pelo seu melhor caso ser necessário ordená-lo

void merge(int *arr, int inicio, int meio, int fim){
    int i, j, k;
    int n1 = meio - inicio + 1; //tamanho do array esquerdo
    int n2 = fim - meio; //tamanho do array direito

    //array temporario
    int L[n1], R[n2];

    //copia os dados para os arrays temporarios
    for (i = 0; i < n1; i++){
        L[i] = arr[inicio + i];
    }

    for (j = 0; j < n2; j++){
        R[j] = arr[meio + 1 + j];
    }

    i = 0;
    j = 0;
    k = inicio;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;

        } else {
            arr[k] = R[j];
            j++;
        }
        k++;

    }

    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }

}


void mergeSort(int *arr, int inicio, int fim){
    if (inicio < fim){
        int meio = inicio + (fim - inicio) / 2;

        mergeSort(arr, inicio, meio);

        mergeSort(arr, meio + 1, fim);

        merge(arr, inicio, meio, fim);
    }
}



int main(){

    int arr[8] = {8, 7, 5, 6, 4, 3, 2, 1};
    int n = 8;

    for (int i  = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    puts("");
    mergeSort(arr, 0, n - 1);
    

    for (int i  = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    puts("");

    return 0;
}