#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void bubbleSort(int arr[], int n){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

}


int main(){
    int arr[] = {90, 3, 31, 43, 5, 9, 7};
    int n = sizeof(arr) / sizeof(arr[0]); //saber tamanho de array em C

    printf("%d\n\n", n);

    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    
    printf("\n\n");
    bubbleSort(arr, n);

    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    
    return 0;
}