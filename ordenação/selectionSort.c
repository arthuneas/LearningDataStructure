#include <stdio.h>
#include <stdlib.h>

//nesse algoritmo ha a divisao o array em duas partes, uma ordenada e outra desordenada
//tem complexidade n^2 pelo seu melhor caso ser necessário ordená-lo


void selectionSort(int *arr, int n){

    int menor;

    for (int i = 0; i < n - 1; i++) {
        menor = i;     

        for (int j = i + 1; j < n; j++){
        
            if (arr[j] < arr[menor]){
                menor = j;
            }

        }

        int temp = arr[i];
        arr[i] = arr[menor];
        arr[menor] =  temp;

    }

}



int main(){

    int arr[8] = {8, 7, 6, 5, 4, 3, 2, 1};
    int n = 8;

    for (int i  = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    selectionSort(arr, n);
    puts("");

    for (int i  = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}