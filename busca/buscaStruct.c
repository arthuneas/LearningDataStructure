/*
a busca linear é universal e não necessita da ordenação do array, ao contrário da 
busca binaria.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int mat;
    char nome[50];
    float nota1, nota2;

} aluno;

void limpatela(){
    getchar();
    system("clear");
    printf("\n\n");
}


int buscaLinearMat(aluno *v, int n, int elem){

    for (int i = 0; i < n; i++){
        if (v[i].mat == elem){
            return i;
        } else {
            if (v[i].mat > elem){
                return -1;
            }
        }
    }

    return -1;
}


int buscaLinearNome(aluno *v, int n, char* elem){

    for (int i = 0; i < n; i++){
        if (strcmp(elem, v[i].nome) == 0){
            return i;
        }
    }

    return -1;
}


void ShowArray(aluno *v, int n){
    printf("Struct: \n");

    for (int i = 0; i < n; i++) {
        printf("%d\n", v[i].mat);
        printf("%s\n", v[i].nome);
        printf("%f | %f\n", v[i].nota1, v[i].nota2);
    }

    printf("\n\n");
}

int main() {

    aluno aluno;

    int tamanho, i, elem, k, init, end;
    i = 0;
    init = 0;

    struct aluno *v[4] = {
        {2, "André", 9.5, 8.5},
        {4, "Ricardo", 8.7, 6.8},
        {1, "Pedro", 6.7, 8.4},
        {3, "Ana", 6.1, 7.4}
    };

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

    ShowArray(arr, tamanho);

    limpatela();

    quickSort(arr, end, init);

    printf("Vetor Ordenado: \n");
    ShowArray(arr, tamanho);

    limpatela();

    printf("qual elemento você quer achar: ");
    scanf("%d", &elem);

    k = buscaLinearOrd(arr, tamanho, elem);

    limpatela();

    ShowArray(arr, tamanho);
    printf("\n\no seu elemento (%d) esta no vetor de indice %d\n", elem, k);

    free(arr);
    
    return 0;
}