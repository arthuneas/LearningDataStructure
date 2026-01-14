/*

*/

#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *arr, int n){
    int atual, j;
    atual = 0;

    for (int i = 1; i < n; i++) {
        atual = arr[i];  

        for (j = i; j > 0; j--) {
            
            if (atual < arr[j - 1]){
                arr[j] = arr[j - 1];
            }
        }
    
        arr[j] = atual;

    }
}

int main(){

    int arr[8] = {8, 7, 6, 5, 4, 3, 2, 1};
    int n = 8;

    for (int i  = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    insertionSort(arr, n);
    puts("");

    for (int i  = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}