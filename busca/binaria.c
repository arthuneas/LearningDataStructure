#include <stdio.h>
#include <stdlib.h>

void limpatela(){
    getchar();
    system("clear");
    printf("\n\n");
}

void swap(int *a, int *b) {
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

/*
  Função principal do QuickSort
  arr[] --> Array a ser ordenado
  low   --> Índice inicial
  high  --> Índice final
*/
int partition(int *arr, int high, int low){
    int p = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] <= p) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int *arr, int high, int low){
    if (low < high) {
        int p = partition(arr, high, low);

        quickSort(arr, p - 1, low);
        quickSort(arr, high, p + 1);
    }
}

int buscaBinaria(int *arr, int init, int end, int elem){
    int mid;

    while (init <= end) {
        mid =  init + (end - init) / 2;

        if (arr[mid] == elem) {
            return mid;
        } else if (arr[mid] > elem) {
            end = mid - 1;
        } else {
            init = mid + 1;
        }
    }

    return -1;
}

void printArray(int *arr, int n){
    printf("Vetor Resultante: \n");

    for (int i = 0; i < n; i++) {
        printf("array[%d] = %d\n", i, arr[i]);
    }
}

void ShowArray(int *arr, int n){
    printf("Vetor Resultante: \n");
    printf("[ ");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
     
    printf("]");
}

int main() {

    int tamanho, i, elem, k, init, end;
    i = 0;
    init = 0;

    printf("qual o tamanho do seu array: ");
    scanf("%d", &tamanho);

    end = tamanho - 1;

    limpatela();

    int* arr = (int*) malloc(tamanho * sizeof(int));

    printf("digite o conteudo de: \n");
    while (i < tamanho){
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);

        i++;
    }

    limpatela();

    printArray(arr, tamanho);

    limpatela();

    ShowArray(arr, tamanho);

    limpatela();

    quickSort(arr, end, init);

    printf("Vetor Ordenado: \n");
    ShowArray(arr, tamanho);

    limpatela();

    printf("qual elemento você quer achar: ");
    scanf("%d", &elem);

    k = buscaBinaria(arr, init, end, elem);

    limpatela();

    ShowArray(arr, tamanho);
    printf("\n\no seu elemento (%d) esta no vetor de indice %d\n", elem, k);

    free(arr);

    return 0;
}