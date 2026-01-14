#include <stdio.h>
#include <stdlib.h>


void BubbleSort(int *arr, int n){
    
    for (int i = 0; i < n; i++){
       for (int j = 0; j < n - 1; j++){
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

            }
       }
    }
}


int main(){



    return 0;
}